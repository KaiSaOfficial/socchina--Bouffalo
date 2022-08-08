#ifndef __MY_TASK_H__
#define __MY_TASK_H__

#include "bflb_platform.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "event_groups.h"
#include "ble.h"

#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"

#include "app.h"
#include "pedometer.h"
#include "fall_dectection.h"

extern QueueHandle_t xSteps_Queue;
extern QueueHandle_t xMax_Queue;
extern QueueHandle_t xWirelss_Queue;

void FreeRTOS_Task_Create(void);

#endif // !__MY_TASK_H__
