#include "app.h"
#include "hal_gpio.h"
#include "FreeRTOS.h"
#include "queue.h"

#include "mytask.h"

const char* Week [] = { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };
const char* Month [] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul","Aug","Sep","Oct","Nov", "Dec" };

static max30102_t max_sen;

static uint32_t aun_ir_buffer[100]; //infrared LED sensor data
static uint32_t aun_red_buffer[100]; //red LED sensor data
static float n_spo2, ratio, correl; //SPO2 value

static int8_t ch_spo2_valid; //indicator to show if the SPO2 calculation is valid
static int32_t n_heart_rate; //heart rate value
static int8_t ch_hr_valid; //indicator to show if the heart rate calculation is valid
static int8_t sample_counter;

struct {
    char rec_buf[50];
    char sec[3];
    char min[3];
    char hou[3];
    char date[3];
    char mon[4];
    char year[5];
    char week[4];
} timebuff;

struct {
    char rec_buf[35];
    char time[3];
    char step_str[7];
    char step[6];
} stepbuff;

extern const int32_t BUFFER_SIZE;

void gpio_irq(void) {
    if (sample_counter < BUFFER_SIZE) {
        max30102_ReadFifo((aun_ir_buffer + sample_counter), (aun_red_buffer + sample_counter));
        sample_counter++;
    }
}

void get_max_sensor(void) {

    sample_counter = 0;
    for (uint8_t try_time = 0; try_time < 2; try_time++) {

        for (uint8_t t = 0; t < 100 && (sample_counter != BUFFER_SIZE); t++) {
            vTaskDelay(100);
        }

        sample_counter = 0;

        //calculate heart rate and SpO2 after first 100 samples (first 4 seconds of samples)
        rf_heart_rate_and_oxygen_saturation(aun_ir_buffer, BUFFER_SIZE, aun_red_buffer, &n_spo2, &ch_spo2_valid, &n_heart_rate, &ch_hr_valid, &ratio, &correl);

        if (ch_hr_valid != 0 && ch_spo2_valid != 0) {
            max_sen.isvalid = 1;
            max_sen.SpO2 = (uint8_t)n_spo2;
            max_sen.Hrate = (uint8_t)n_heart_rate;

            break;
        } else {
            max_sen.isvalid = 0;
        }
    }

    if (uxQueueSpacesAvailable(xMax_Queue)) {
        xQueueSend(xMax_Queue, (void*)&max_sen, (TickType_t)10);
    } else {
        xQueueOverwrite(xMax_Queue, (void*)&max_sen);
    }

    ch_hr_valid = 0;
    ch_spo2_valid = 0;

    max30102_OFF();
}


void get_time(Time_t* t) {

    at_get_time_str(timebuff.rec_buf);

    memcpy(timebuff.sec, timebuff.rec_buf + 25, 2);
    memcpy(timebuff.min, timebuff.rec_buf + 22, 2);
    memcpy(timebuff.hou, timebuff.rec_buf + 19, 2);
    memcpy(timebuff.year, timebuff.rec_buf + 14, 4);
    memcpy(timebuff.mon, timebuff.rec_buf + 10, 3);
    memcpy(timebuff.date, timebuff.rec_buf + 7, 2);
    memcpy(timebuff.week, timebuff.rec_buf + 2, 3);

    for (uint8_t i = 0; i < 7; i++) {
        if (strcmp(timebuff.week, Week[i]) == 0) {
            t->week = i + 1;
        }
    }

    for (uint8_t i = 0; i < 12; i++) {
        if (strcmp(timebuff.mon, Month[i]) == 0) {
            t->month = i + 1;
        }
    }

    t->year = atoi(timebuff.year);
    t->date = atoi(timebuff.date);
    t->hour = atoi(timebuff.hou) + 8;
    t->min = atoi(timebuff.min);
    t->sec = atoi(timebuff.sec);

}

void sync_step(void) {

    at_get_step_str(stepbuff.rec_buf);

    memcpy(stepbuff.time, stepbuff.rec_buf, 2);

    if (strcmp(timebuff.date, stepbuff.time) == 0) {
        uint16_t Step = 0;

        memcpy(stepbuff.step_str, stepbuff.rec_buf + 25, 6);
        //{
        uint8_t i;
        for (i = 0; i < strlen(stepbuff.step_str); i++) {
            if (*(stepbuff.step_str + i) == '}')
                break;
        }

        memcpy(stepbuff.step, stepbuff.step_str, i);

        Step = atoi(stepbuff.step);

        sync_local_step(Step);
    }

}


void update_time(Time_t* t) {
    t->sec++;

    if (t->sec == 60) {
        t->sec = 0;
        t->min++;
    }

    if (t->min == 60) {
        t->min = 0;
        t->hour++;
    }

    if (t->hour == 24) {
        t->hour = 0;
        t->date++;
    }
}

