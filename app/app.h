#ifndef __APP_H__
#define __APP_H__

#include "bflb_platform.h"
#include "max30102.h"

#include "gui_main.h"

#include "mpu9250.h"
#include "max30102.h"
#include "mcu_lcd.h"
#include "at_cmd.h"
#include "ble_peripheral_tp_server.h"

#include "pedometer.h"
#include "fall_dectection.h"

typedef struct {
    uint8_t isvalid;
    uint8_t SpO2;
    uint8_t Hrate;
} max30102_t;

// typedef struct {
//     uint8_t WIFI;
//     uint8_t BLE;
// } Wireless_t;

void gpio_irq(void);
void get_max_sensor(void);

void get_time(Time_t* t);
void sync_step(void);
void update_time(Time_t* t);

#endif
