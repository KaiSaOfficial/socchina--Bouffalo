#include "gui_apps.h"

static const char* list_item_name [] = {
	"Settings",
	"HeartBeat",
	"System",
	"Game",
	"Calculator",
	"Calendar",
	"Usb",
	"About"
};

const char* list_item_icon [] = {
	HWATCH_SYMBOL_SETTING,
	HWATCH_SYMBOL_HEART,
	HWATCH_SYMBOL_SYS_INFO,
	HWATCH_SYMBOL_GAME,
	HWATCH_SYMBOL_CALC,
	HWATCH_SYMBOL_CALENDAR,
	HWATCH_SYMBOL_USB,
	HWATCH_SYMBOL_ABOUT
};

static lv_obj_t* m_apps;

//static short app_index;

lv_obj_t* app_list;
lv_obj_t* list_btns[APPS_COUNT];

PageRegHandler apps_handler;

/*****************************/
void create_app_list(lv_style_t* font_style, lv_group_t* g);
/*****************************/

static void event_handler(lv_obj_t* obj, lv_event_t event) {
	switch (event) {
	case LV_EVENT_KEY:
	{
		const uint32_t* key = lv_event_get_data();
		if (*key == LV_KEY_BACKSPACE) {
			apps_handler(p_main, app_null);
		}
		break;
	}
	case LV_EVENT_PRESSING:
	{
		lv_obj_t* select = lv_list_get_btn_selected(obj);

		if (select != NULL) {
			uint32_t select_index = lv_list_get_btn_index(obj, select);

			apps_handler(p_apps, select_index);
		}
		break;
	default:
		break;
	}
	}
}

void GUI_Apps_Init(lv_obj_t* papp, lv_group_t* group, PageRegHandler handler) {
	m_apps = papp;
	apps_handler = handler;

	lv_obj_set_size(m_apps, WIN_W, WIN_H);
	//lv_obj_align(m_apps, NULL, LV_ALIGN_CENTER, 0, 0);
	lv_obj_add_style(m_apps, LV_OBJ_PART_MAIN, &page_style);

	create_app_list(&icons_style1, group);
}

void create_app_list(lv_style_t* font_style, lv_group_t* g) {
	uint8_t i;
	app_list = lv_list_create(m_apps, NULL);
	lv_obj_set_width_fit(app_list, LCD_W);
	lv_obj_set_height_fit(app_list, LCD_H);
	lv_list_set_edge_flash(app_list, true);
	lv_list_set_scroll_propagation(app_list, true);
	lv_list_set_anim_time(app_list, 100);

	lv_group_add_obj(g, app_list);
	lv_obj_set_event_cb(app_list, event_handler);

	for (i = 0;i < APPS_COUNT;i++) {
		uint8_t x = 0;
		list_btns[i] = lv_list_add_btn(app_list, list_item_icon[i], list_item_name[i]);
		lv_btn_set_layout(list_btns[i], LV_LAYOUT_OFF);

		//		lv_group_add_obj( g, list_btns[i] );
		//		lv_obj_set_event_cb( list_btns[i], event_handler );

				//设置图标
		lv_obj_t* img = lv_list_get_btn_img(list_btns[i]);
		lv_img_set_auto_size(img, false);
		lv_obj_set_size(img, 30, 26);
		//lv_obj_clean_style_list(img, LV_OBJ_PART_MAIN);
		lv_obj_add_style(img, LV_LABEL_PART_MAIN, font_style);
		lv_obj_align(img, NULL, LV_ALIGN_CENTER, x, 0);

		//设置Label
		lv_obj_t* label = lv_list_get_btn_label(list_btns[i]);
		lv_label_set_long_mode(label, LV_LABEL_LONG_EXPAND);
		lv_obj_set_width_fit(label, LCD_W);
		lv_obj_align(label, img, LV_ALIGN_OUT_BOTTOM_MID, 0, 5);

	}

}

void GUI_Apps_FocusInit() {
	lv_group_focus_obj(app_list);
}