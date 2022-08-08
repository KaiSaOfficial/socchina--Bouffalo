#ifndef GUI_INC_H_INCLUDED
#define GUI_INC_H_INCLUDED

#include "bflb_platform.h"
#include "mcu_lcd.h"
#include "image.h"

#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"

#include "hwatch_symbol_def.h"

#define APP_ABOUT "About"
#define APP_SETTING "Settings"
#define APP_SYSINFO	"SysInfo"
#define APP_HEART	"HeartBeat && SpO2"
#define APP_GAMES "Games"
#define APP_CALENDER "Calendar"
#define APP_CALC	"Calculator"
#define APP_USB "Usb"

#define WIN_W LCD_W
#define WIN_H LCD_H

#define PAGE_COUNT 2
#define APPS_COUNT 8
#define GAME_COUNT 6
#define SETTING_COUNT 5

#define ANIM_TIME 160

LV_FONT_DECLARE(hwatch_icons_font_16);
LV_FONT_DECLARE(hwatch_icons_font_26);
//LV_FONT_DECLARE(hwatch_icons_font_24);

typedef void(*PageRegHandler)(uint8_t pageId, short appId);

typedef enum {
	app_null = -1,//空值
	app_setting,	//设置页
	app_heart,		//心率监测页
	app_sys,			//系统信息页
	app_games,			//内置游戏页
	app_calc,			//计算器
	app_calendar,	//日历
	app_usb,			//PC&USB通信//显示图像//字库里没有合适的图标。。。
	app_about,		//关于页
}APP_ID;

typedef enum {
	game_null = -1,	//空值
	game_snake,			//贪吃蛇
	game_tank,
	game_tetris,
	game_2048,
	game_plane,
	game_block,

}GAME_ID;

typedef enum {
	setting_null = -1,
	setting_time,
	setting_blight,
	setting_sound,
	setting_alarm,
	setting_task,
}SETTING_ID;

typedef enum {
	p_main,		//主页
	p_apps,		//应用列表页
	p_games,	//游戏列表页
	p_settings,	//设置列表页
}PAGE_ID;

typedef struct {
	uint8_t page_id;
	short app_id;
}GUI_IDS;


#define LV_OBJ_ADD_ANIM(obj, attr, target, time)\
do{\
	static lv_anim_t a;\
	lv_obj_add_anim(\
		(obj),&a,\
		(lv_anim_exec_xcb_t)lv_obj_set_##attr,\
		lv_obj_get_##attr(obj),\
		(target),\
		(time)\
	);\
}while(0)


#endif // GUI_INC_H_INCLUDED
