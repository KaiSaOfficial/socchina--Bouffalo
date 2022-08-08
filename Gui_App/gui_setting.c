#include "gui_setting.h"
#include "app.h"

static const char* list_item_name [] = {
	HWATCH_SYMBOL_CLOCK,
	HWATCH_SYMBOL_LIGHT,
	HWATCH_SYMBOL_SOUND_ON,
	HWATCH_SYMBOL_ALARM_ON,
	HWATCH_SYMBOL_TASK,
};

extern Time_t time_s;

static lv_obj_t* m_setting;

lv_obj_t* lv_title_setting_label;

lv_obj_t* lv_setting_tabview;
lv_obj_t* lv_tabs[SETTING_COUNT];

//时间设置控件
lv_obj_t* lv_time_roller_label;
lv_task_t* time_set_task;

PageRegHandler setting_handler;
static short setting_index;

static void tab_item_focus();
static void tab_item_cancelfocus();

void time_set_task_callback(lv_task_t* task) {
	//提示设置成功
	get_time(&time_s);

}

static void event_roller_handler(lv_obj_t* obj, lv_event_t event) {
	switch (event) {
	case LV_EVENT_KEY:
	{
		const uint32_t* key = lv_event_get_data();

		if (*key == LV_KEY_BACKSPACE) {
			tab_item_cancelfocus();
		}
		break;
	}
	case LV_EVENT_PRESSING:
	{
		time_set_task = lv_task_create_basic();
		lv_task_set_cb(time_set_task, time_set_task_callback);
		lv_task_once(time_set_task);
		break;
	}
	}
}

static void event_tabview_handler(lv_obj_t* obj, lv_event_t event) {
	switch (event) {
	case LV_EVENT_KEY:
	{
		const uint32_t* key = lv_event_get_data();
		if (*key == LV_KEY_BACKSPACE) {
			setting_handler(p_apps, app_null);
		}
		break;
	}
	case LV_EVENT_PRESSING:
	{
		tab_item_focus();
		break;
	}

	default:
		break;
	}

}

void GUI_Setting_Init(lv_obj_t* psetting, lv_group_t* group, PageRegHandler handler) {
	m_setting = psetting;
	setting_handler = handler;

	lv_obj_set_size(m_setting, WIN_W, WIN_H);
	lv_obj_add_style(m_setting, LV_OBJ_PART_MAIN, &page_style);
	lv_obj_set_event_cb(m_setting, event_tabview_handler);
	lv_group_add_obj(group, m_setting);

	lv_title_setting_label = lv_label_create(m_setting, NULL);
	lv_label_set_text(lv_title_setting_label, APP_SETTING);
	lv_obj_add_style(lv_title_setting_label, LV_LABEL_PART_MAIN, &font_style2);
	lv_obj_align(lv_title_setting_label, NULL, LV_ALIGN_IN_TOP_MID, 0, 10);

	//创建选项卡
	lv_setting_tabview = lv_tabview_create(m_setting, NULL);
	lv_obj_set_size(lv_setting_tabview, 180, 185);
	lv_obj_add_style(lv_setting_tabview, LV_OBJ_PART_MAIN, &page_style);
	lv_tabview_set_anim_time(lv_setting_tabview, ANIM_TIME);
	lv_tabview_set_btns_pos(lv_setting_tabview, LV_TABVIEW_TAB_POS_TOP);
	lv_obj_add_style(lv_setting_tabview, LV_TABVIEW_PART_TAB_BTN, &icons_style);
	lv_obj_align(lv_setting_tabview, lv_title_setting_label, LV_ALIGN_OUT_BOTTOM_MID, 0, 2);

	// lv_time_roller_label = lv_label_create(lv_tabs[setting_time], NULL);
	// lv_label_set_long_mode(lv_time_roller_label, LV_LABEL_LONG_SROLL_CIRC);
	// lv_obj_set_size(lv_time_roller_label, 160, 20);
	// lv_obj_add_style(lv_time_roller_label, LV_LABEL_PART_MAIN, &font_style2);
	// lv_label_set_text(lv_time_roller_label, "");
	// //lv_obj_set_auto_realign(lv_time_roller_label, true);
	// lv_label_set_align(lv_time_roller_label, LV_LABEL_ALIGN_CENTER);
	// lv_obj_align(lv_time_roller_label, NULL, LV_ALIGN_IN_TOP_MID, 0, 5);

	// for (uint8_t i = 0;i < SETTING_COUNT;i++) {
	// 	lv_tabs[i] = lv_tabview_add_tab(lv_setting_tabview, list_item_name[i]);

	// 	lv_group_add_obj(group, lv_tabs[i]);
	// 	lv_obj_set_event_cb(lv_tabs[i], event_tabview_handler);
	// }

	//闹钟 TAB
	//AlarmClock_Init(lv_tabs[setting_alarm], group);

	//任务 TAB
	//SettingTask_Init(lv_tabs[setting_task], group);
}

void GUI_Setting_FocusInit() {
	lv_group_focus_obj(lv_tabs[setting_index]);
}

static void tab_item_cancelfocus() {
	lv_tabview_get_tab_act(lv_setting_tabview);
	lv_group_focus_obj(lv_tabs[setting_index]);
}


static void tab_item_focus() {
	switch (setting_index) {
	case setting_time:
		// timer_roller_change();
		break;
	case setting_blight:

		break;
	case setting_sound:

		break;
	case setting_alarm:
		// AlarmClock_FocusInit();
		break;
	case setting_task:
		// SettingTask_FocusInit();
		break;
	}
}




