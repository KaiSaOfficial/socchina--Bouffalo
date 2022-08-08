#ifndef GUI_MAIN_H_INCLUDED
#define GUI_MAIN_H_INCLUDED

#include "gui_manager.h"

typedef struct {
    uint16_t year;
    uint8_t month;
    uint8_t date;
    uint8_t hour;
    uint8_t min;
    uint8_t sec;
    uint8_t week;
}Time_t;

extern Time_t time_s;

void GUI_Main_Init(lv_obj_t* pmain, lv_group_t* group, PageRegHandler handler);
void GUI_Main_FocusInit(void);

#endif // GUI_MAIN_H_INCLUDED
