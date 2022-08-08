#include "gui_manager.h"
#include "gui_main.h"

GUI_IDS gui_ids;

lv_obj_t* pages[PAGE_COUNT];
lv_obj_t* apps[APPS_COUNT];

/**
@按键组
*/
extern lv_group_t* group;

lv_style_t page_style;
lv_style_t lmeter_style;
lv_style_t font_style, font_style1, font_style2;
lv_style_t icons_style, icons_style1; /*icons_style2*/;
lv_style_t chart_style;

static void gui_init(void);
static void gui_style_init(void);
void pageRegCallback(uint8_t a, short b);

void GUI_ManagerInit() {
	gui_ids.page_id = p_main;
	gui_ids.app_id = app_null;

	lv_init(); 							//lvgl 系统初始化
	lv_port_disp_init();		//lvgl 显示接口初始化
	lv_port_indev_init();		//lvgl 输入接口初始化，此处仅使用按键

	gui_init();		//GUI 初始化
}

static void set_font_style(lv_style_t* style, lv_color_t color, lv_font_t* font) {
	lv_style_reset(style);
	lv_style_init(style);

	lv_style_set_text_font(style, LV_STATE_DEFAULT, font);
	lv_style_set_text_color(style, LV_STATE_DEFAULT, color);
}

//部分使用样式初始化
static void gui_style_init() {

	lv_style_init(&page_style);
	lv_style_set_bg_opa(&page_style, LV_STATE_DEFAULT, LV_OPA_COVER);
	lv_style_set_bg_color(&page_style, LV_STATE_DEFAULT, BG_COLOR_GREEN);			//背景色
	lv_style_set_border_color(&page_style, LV_STATE_FOCUSED, LV_COLOR_GREEN);	//页面聚焦边颜色
	lv_style_set_border_color(&page_style, LV_STATE_DEFAULT, LV_COLOR_GREEN);	//页面默认边颜色

	lv_style_init(&lmeter_style);
	lv_style_set_bg_opa(&lmeter_style, LV_STATE_DEFAULT, LV_OPA_TRANSP);
	lv_style_set_line_width(&lmeter_style, LV_STATE_DEFAULT, 5);  									//刻度线宽度
	lv_style_set_line_color(&lmeter_style, LV_STATE_DEFAULT, LV_COLOR_PURPLE); 			//刻度线起始颜色
	lv_style_set_scale_grad_color(&lmeter_style, LV_STATE_DEFAULT, LV_COLOR_BLUE);		//刻度线终止颜色
	lv_style_set_scale_end_color(&lmeter_style, LV_STATE_DEFAULT, LV_COLOR_RED);	//非活跃刻度线颜色
	lv_style_set_scale_end_line_width(&lmeter_style, LV_STATE_DEFAULT, 2);				//非活跃刻度线宽度
	lv_style_set_scale_width(&lmeter_style, LV_STATE_DEFAULT, 4);	//刻度线长度

	set_font_style(&font_style, FONT_COLOR_ORG, &lv_font_montserrat_32);
	set_font_style(&font_style1, LV_COLOR_OLIVE, &lv_font_montserrat_16);
	set_font_style(&font_style2, LV_COLOR_MAROON, &lv_font_montserrat_16);

	set_font_style(&icons_style, LV_COLOR_BLUE, &hwatch_icons_font_16);
	set_font_style(&icons_style1, LV_COLOR_RED, &hwatch_icons_font_16);
	//	set_font_style(&icons_style2, LV_COLOR_GRAY, &hwatch_icons_font_24);
}
/**
初始化全部页面
*/
static void gui_init() {
	gui_style_init();

	//PAGE_MAIN
	pages[p_main] = lv_page_create(NULL, NULL);
	GUI_Main_Init(pages[p_main], group, pageRegCallback);
	lv_scr_load(pages[p_main]);

	//PAGE_APPS
	pages[p_apps] = lv_cont_create(NULL, NULL);
	GUI_Apps_Init(pages[p_apps], group, pageRegCallback);

	//APP_ABOUT
	apps[app_about] = lv_cont_create(NULL, NULL);
	GUI_About_Init(apps[app_about], group, pageRegCallback);

	//APP_SETTING
	// apps[app_setting] = lv_cont_create(NULL, NULL);
	// GUI_Setting_Init(apps[app_setting], group, pageRegCallback);

	//APP_SYSINFO
	apps[app_sys] = lv_cont_create(NULL, NULL);
	GUI_SYSInfo_Init(apps[app_sys], group, pageRegCallback);

	//APP_HEART
	apps[app_heart] = lv_cont_create(NULL, NULL);
	GUI_Heart_Init(apps[app_heart], group, pageRegCallback);

	//APP_GAMES//内存不够了//取消这个。。
	// apps[app_games] = lv_cont_create(NULL, NULL);
	// GUI_Games_Init(apps[app_games], group, pageRegCallback);

	//APP_CALENDER
	apps[app_calendar] = lv_cont_create(NULL, NULL);
	GUI_Calender_Init(apps[app_calendar], group, pageRegCallback);

	//APP_CALC
	// apps[app_calc] = lv_cont_create(NULL, NULL);
	// GUI_Calc_Init(apps[app_calc], group, pageRegCallback);

	//APP_USB
	// apps[app_usb] = lv_cont_create(NULL, NULL);
	// GUI_Usb_Init(apps[app_usb], group, pageRegCallback);

	//pageRegCallback((uint8_t)p_apps, app_calender);
}

/**
@页面管理，切换回调
@pageRegCallback
@a--page_id
@b--app_id
*/
void pageRegCallback(uint8_t a, short b) {
	gui_ids.page_id = a;
	gui_ids.app_id = b;

	if (a == p_main) {
		lv_scr_load_anim(pages[p_main], LV_SCR_LOAD_ANIM_MOVE_BOTTOM, ANIM_TIME, 50, false);
		GUI_Main_FocusInit();
	} else if (a == p_apps) {
		switch (b) {
		case app_null:
			lv_scr_load_anim(pages[p_apps], LV_SCR_LOAD_ANIM_MOVE_TOP, ANIM_TIME, 50, false);
			GUI_Apps_FocusInit();
			break;
			// case app_setting:
			// 	lv_scr_load_anim(apps[app_setting], LV_SCR_LOAD_ANIM_MOVE_BOTTOM, ANIM_TIME, 50, false);
			// 	GUI_Setting_FocusInit();
			// 	break;
		case app_about:
			lv_scr_load_anim(apps[app_about], LV_SCR_LOAD_ANIM_MOVE_BOTTOM, ANIM_TIME, 50, false);
			GUI_About_FocusInit();
			break;
		case app_sys:
			lv_scr_load_anim(apps[app_sys], LV_SCR_LOAD_ANIM_MOVE_BOTTOM, ANIM_TIME, 50, false);
			GUI_SYSInfo_FocusInit();
			break;
		case app_heart:
			lv_scr_load_anim(apps[app_heart], LV_SCR_LOAD_ANIM_MOVE_BOTTOM, ANIM_TIME, 50, false);
			GUI_Heart_FocusInit();
			break;
			// case app_games:
			// 	lv_scr_load_anim(apps[app_games], LV_SCR_LOAD_ANIM_MOVE_BOTTOM, ANIM_TIME, 50, false);
			// 	GUI_Games_FocusInit();
			// 	break;
		case app_calendar:
			lv_scr_load_anim(apps[app_calendar], LV_SCR_LOAD_ANIM_MOVE_BOTTOM, ANIM_TIME, 50, false);
			GUI_Calender_FocusInit();
			break;
			// case app_calc:
			// 	lv_scr_load_anim(apps[app_calc], LV_SCR_LOAD_ANIM_MOVE_BOTTOM, ANIM_TIME, 50, false);
			// 	GUI_Calc_FocusInit();
			// 	break;
			// case app_usb:
			// 	lv_scr_load_anim(apps[app_usb], LV_SCR_LOAD_ANIM_MOVE_BOTTOM, ANIM_TIME, 50, false);
			// 	GUI_Usb_FocusInit();
			// 	break;
		}

	} else if (a == p_games) {
		switch (b) {
		case game_null:
			break;
		case game_snake:
			break;
		}
	} else if (a == p_settings) {

	}

}
