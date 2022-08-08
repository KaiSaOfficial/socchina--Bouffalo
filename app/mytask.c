#include "mytask.h"
#include "gui_main.h"

#include "bflb_platform.h"

// FreeRTOS: the length and size of the queue 
#define STEPS_QUEUE_LENGTH  2
#define STEPS_SIZE  (sizeof(uint16_t))
#define HRASP_QUEUE_LENGTH  1
#define HRASP_SIZE  (sizeof(max30102_t))
#define WIRELESS_QUEUE_LENGTH  1
#define WIRELESS_SIZE  (sizeof(uint8_t))

// FreeRTOS: the stack and handle of task
static StackType_t lvgl_stack[512];
static StaticTask_t lvgl_handle;
static StackType_t max30102_stack[512];
static StaticTask_t max30102_handle;
static StackType_t AT_Task_stack[512];
static StaticTask_t AT_Task_handle;
static StackType_t step_Task_stack[512];
static StaticTask_t step_Task_handle;
static StackType_t falling_dectection_Task_stack[512];
static StaticTask_t falling_dectection_handle;
static StackType_t time_Task_stack[512];
static StaticTask_t time_Task_handle;

// FreeRTOS: the queue
static StaticQueue_t xSteps_StaticQueue;
static uint8_t ucSteps_QueueStorageArea[STEPS_QUEUE_LENGTH * STEPS_SIZE];
QueueHandle_t xSteps_Queue;
static StaticQueue_t xMax_StaticQueue;
static uint8_t ucMax_QueueStorageArea[HRASP_QUEUE_LENGTH * HRASP_SIZE];
QueueHandle_t xMax_Queue;
static StaticQueue_t xWirelss_StaticQueue;
static uint8_t ucWirelss_QueueStorageArea[HRASP_QUEUE_LENGTH * HRASP_SIZE];
QueueHandle_t xWirelss_Queue;

// FreeRTOS: the Mutex
static SemaphoreHandle_t xSemaphore = NULL;
static StaticSemaphore_t xMutexBuffer;

// WIFI status
const uint8_t WiFi_State = (0x01 << 1);
static uint8_t AT_init = 0;

static void lvgl_task(void* pvParameters) {
    while (1) {
        lv_task_handler();
        vTaskDelay(5);
    }
}

static void max30102_task(void* pvParameters) {

    vTaskDelay(10000);

    while (1) {
        if (xSemaphoreTake(xSemaphore, (TickType_t)100) == pdTRUE) {
            max30102_ON();

            get_max_sensor();

            xSemaphoreGive(xSemaphore);

            vTaskDelay(120 * 1000);
        }
    }

    vTaskDelete(NULL);
}

static void at_task(void* pvParameters) {
    uint32_t steps = 0;
    max30102_t max_sensor;

    vTaskDelay(500);

    while (1) {
        switch (AT_init) {
        case 0x00: {
            AT_init = at_init();

            break;
        }
        case 0x01: {
            AT_init |= (init_WiFi() << 1);

            xQueueSend(xWirelss_Queue, &AT_init, (TickType_t)10);

            vTaskDelay(5000);
            get_time(&time_s);
            sync_step();

            break;
        }
        case 0x03: {
            if (xQueueReceive(xSteps_Queue, &(steps), (TickType_t)10) == pdPASS) {
                at_send_steps_ontnet(steps);
            }

            if (xQueuePeek(xMax_Queue, &(max_sensor), (TickType_t)10) == pdPASS) {
                if (max_sensor.isvalid == 1) {
                    at_send_heart_ontnet(max_sensor.Hrate);
                    at_send_SpO2_ontnet(max_sensor.SpO2);
                }
            }

            if (time_s.min % 10 == 0 && time_s.sec < 30) {
                at_send_medi_ontnet(1);
            } else {
                at_send_medi_ontnet(0);
            }

            at_send_fall_ontnet(0);

            vTaskDelay(15 * 1000);

            break;
        }
        default:
            vTaskDelay(10000);
            break;
        }

    }
}


static void fall_dectect_task(void* pvParameters) {
    uint8_t is_falling = 0;

    vTaskDelay(300);

    while (1) {
        if (xSemaphoreTake(xSemaphore, (TickType_t)10) == pdTRUE) {

            fall_dectection(&is_falling);

            if (is_falling && (AT_init & WiFi_State)) {
                at_send_fall_ontnet(1);
            }

            xSemaphoreGive(xSemaphore);

            vTaskDelay(250);
        }
    }

    vTaskDelete(NULL);
}

static void step_task(void* pvParameters) {
    static uint16_t Steps = 0;

    peak_value_init(&peak);

    vTaskDelay(300);

    while (1) {
        if (xSemaphoreTake(xSemaphore, (TickType_t)10) == pdTRUE) {

            Steps = get_step();

            xSemaphoreGive(xSemaphore);

            xQueueSend(xSteps_Queue, (void*)&Steps, (TickType_t)10);

            vTaskDelay(100);    //100
        }
    }

    vTaskDelete(NULL);
}


static void time_task(void* pvParameters) {

    while (1) {

        update_time(&time_s);

        if (time_s.min == 30 && time_s.hour == 12 && AT_init & WiFi_State) {
            get_time(&time_s);
        }

        vTaskDelay(1000);
    }
}

void FreeRTOS_Task_Create(void) {
    xTaskCreateStatic(lvgl_task, (char*)"lvgl_task", sizeof(lvgl_stack) / 4, NULL, configMAX_PRIORITIES - 6, lvgl_stack, &lvgl_handle);
    xTaskCreateStatic(max30102_task, (char*)"max30102_task", sizeof(max30102_stack) / 4, NULL, configMAX_PRIORITIES - 3, max30102_stack, &max30102_handle);
    xTaskCreateStatic(time_task, (char*)"time_task", sizeof(time_Task_stack) / 4, NULL, configMAX_PRIORITIES - 1, time_Task_stack, &time_Task_handle);
    xTaskCreateStatic(at_task, (char*)"at_task", sizeof(AT_Task_stack) / 4, NULL, configMAX_PRIORITIES - 7, AT_Task_stack, &AT_Task_handle);
    xTaskCreateStatic(step_task, (char*)"step_task", sizeof(step_Task_stack) / 4, NULL, configMAX_PRIORITIES - 5, step_Task_stack, &step_Task_handle);
    xTaskCreateStatic(fall_dectect_task, (char*)"fall_dectect_task", sizeof(falling_dectection_Task_stack) / 4, NULL, configMAX_PRIORITIES - 4, falling_dectection_Task_stack, &falling_dectection_handle);

    xSteps_Queue = xQueueCreateStatic(STEPS_QUEUE_LENGTH, STEPS_SIZE, ucSteps_QueueStorageArea, &xSteps_StaticQueue);
    xMax_Queue = xQueueCreateStatic(HRASP_QUEUE_LENGTH, HRASP_SIZE, ucMax_QueueStorageArea, &xMax_StaticQueue);
    xWirelss_Queue = xQueueCreateStatic(WIRELESS_QUEUE_LENGTH, WIRELESS_SIZE, ucWirelss_QueueStorageArea, &xWirelss_StaticQueue);

    xSemaphore = xSemaphoreCreateMutexStatic(&xMutexBuffer);
}

void user_vAssertCalled(void) __attribute__((weak, alias("vAssertCalled")));
void vAssertCalled(void) {
    MSG("vAssertCalled\r\n");

    while (1)
        ;
}

void vApplicationTickHook(void) {
    lv_tick_inc(1);
    //MSG("vApplicationTickHook\r\n");
}

void vApplicationStackOverflowHook(TaskHandle_t xTask, char* pcTaskName) {
    MSG("vApplicationStackOverflowHook\r\n");

    if (pcTaskName) {
        MSG("Stack name %s\r\n", pcTaskName);
    }

    while (1)
        ;
}

void vApplicationMallocFailedHook(void) {
    MSG("vApplicationMallocFailedHook\r\n");

    while (1)
        ;
}
void vApplicationGetIdleTaskMemory(StaticTask_t** ppxIdleTaskTCBBuffer, StackType_t** ppxIdleTaskStackBuffer, uint32_t* pulIdleTaskStackSize) {
    /* If the buffers to be provided to the Idle task are declared inside this
    function then they must be declared static - otherwise they will be allocated on
    the stack and so not exists after this function exits. */
    static StaticTask_t xIdleTaskTCB;
    static StackType_t uxIdleTaskStack[configMINIMAL_STACK_SIZE];

    /* Pass out a pointer to the StaticTask_t structure in which the Idle task's
    state will be stored. */
    *ppxIdleTaskTCBBuffer = &xIdleTaskTCB;

    /* Pass out the array that will be used as the Idle task's stack. */
    *ppxIdleTaskStackBuffer = uxIdleTaskStack;

    /* Pass out the size of the array pointed to by *ppxIdleTaskStackBuffer.
    Note that, as the array is necessarily of type StackType_t,
    configMINIMAL_STACK_SIZE is specified in words, not bytes. */
    *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
}

/* configSUPPORT_STATIC_ALLOCATION and configUSE_TIMERS are both set to 1, so the
application must provide an implementation of vApplicationGetTimerTaskMemory()
to provide the memory that is used by the Timer service task. */
void vApplicationGetTimerTaskMemory(StaticTask_t** ppxTimerTaskTCBBuffer, StackType_t** ppxTimerTaskStackBuffer, uint32_t* pulTimerTaskStackSize) {
    /* If the buffers to be provided to the Timer task are declared inside this
    function then they must be declared static - otherwise they will be allocated on
    the stack and so not exists after this function exits. */
    static StaticTask_t xTimerTaskTCB;
    static StackType_t uxTimerTaskStack[configTIMER_TASK_STACK_DEPTH];

    /* Pass out a pointer to the StaticTask_t structure in which the Timer
    task's state will be stored. */
    *ppxTimerTaskTCBBuffer = &xTimerTaskTCB;

    /* Pass out the array that will be used as the Timer task's stack. */
    *ppxTimerTaskStackBuffer = uxTimerTaskStack;

    /* Pass out the size of the array pointed to by *ppxTimerTaskStackBuffer.
    Note that, as the array is necessarily of type StackType_t,
    configTIMER_TASK_STACK_DEPTH is specified in words, not bytes. */
    *pulTimerTaskStackSize = configTIMER_TASK_STACK_DEPTH;
}


