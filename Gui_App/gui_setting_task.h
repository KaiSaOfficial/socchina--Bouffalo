#ifndef GUI_SETTING_TASK_H_INCLUDED
#define GUI_SETTING_TASK_H_INCLUDED

#include "gui_manager.h"

#define STOP_WATCH_MAX 15	//秒表最多可记录数

typedef struct {

	uint8_t watch_min;	//分
	uint8_t watch_sec;	//秒
	uint8_t watch_ms;	//ms * 10
	uint8_t watch_num;	//已记录秒表数量

}StopWatchVars;

#define SCREEN_RESET_TIME_OPTIONS ("\
10\n20\n30\n40\n50\n60\
")\

void SettingTask_Init(lv_obj_t* tab, lv_group_t* group);
void SettingTask_FocusInit(void);

#endif // GUI_SETTING_TASK_H_INCLUDED
