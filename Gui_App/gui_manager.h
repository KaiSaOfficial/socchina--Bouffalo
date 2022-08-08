#ifndef GUI_MANAGER_H_INCLUDED
#define GUI_MANAGER_H_INCLUDED

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "bflb_platform.h"

#include "gui_inc.h"
#include "gui_apps.h"
#include "gui_about.h"
#include "gui_sysinfo.h"
#include "gui_calender.h"
#include "gui_heart.h"
#include "gui_setting.h"

extern lv_style_t page_style;
extern lv_style_t lmeter_style;
extern lv_style_t font_style, font_style1, font_style2;
extern lv_style_t icons_style, icons_style1; /*icons_style2*/;

void GUI_ManagerInit(void);

extern GUI_IDS gui_ids;

#endif // GUI_MANAGER_H_INCLUDED
