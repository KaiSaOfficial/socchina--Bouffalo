#ifndef GUI_ABOUT_H_INCLUDED
#define GUI_ABOUT_H_INCLUDED

#include "gui_manager.h"

#define CONTENT ("\
Watch\r\n\
NJTech\r\n\
")\

void GUI_About_Init(lv_obj_t* pmain, lv_group_t* group, PageRegHandler handler);
void GUI_About_FocusInit(void);

#endif // GUI_ABOUT_H_INCLUDED
