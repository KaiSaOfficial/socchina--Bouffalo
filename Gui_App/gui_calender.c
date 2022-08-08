#include "gui_calender.h"
#include "gui_main.h"

static lv_obj_t* m_calender;

lv_obj_t* lv_title_calender_label;
lv_obj_t* lv_calender;

lv_calendar_date_t lv_today;

lv_task_t* today_task;
PageRegHandler calender_handler;

static void today_init(void);

void today_init_task(lv_task_t* task) {
	//获取一下日期
	lv_today.year = time_s.year;
	lv_today.month = time_s.month;
	lv_today.day = time_s.date;

	lv_calendar_set_today_date(lv_calender, &lv_today);
	lv_calendar_set_showed_date(lv_calender, &lv_today);

}

static void event_handler(lv_obj_t* obj, lv_event_t event) {
	switch (event) {
	case LV_EVENT_KEY:
	{
		const uint32_t* key = lv_event_get_data();
		if (*key == LV_KEY_BACKSPACE) {
			calender_handler(p_apps, app_null);
		}
		break;
	}
	case LV_EVENT_PRESSING:
	{
		today_init();
		break;
	}
	default:
		break;
	}
}

void GUI_Calender_Init(lv_obj_t* pcalender, lv_group_t* group, PageRegHandler handler) {
	m_calender = pcalender;
	calender_handler = handler;

	lv_obj_set_size(m_calender, WIN_W, WIN_H);
	lv_obj_add_style(m_calender, LV_OBJ_PART_MAIN, &page_style);
	lv_obj_set_event_cb(m_calender, event_handler);
	lv_group_add_obj(group, m_calender);

	lv_title_calender_label = lv_label_create(m_calender, NULL);
	lv_label_set_text(lv_title_calender_label, APP_CALENDER);
	lv_obj_add_style(lv_title_calender_label, LV_LABEL_PART_MAIN, &font_style2);
	lv_obj_align(lv_title_calender_label, NULL, LV_ALIGN_IN_TOP_MID, 0, 5);

	//日历控件
	lv_calender = lv_calendar_create(m_calender, NULL);
	lv_obj_set_size(lv_calender, 180, 180);
	lv_obj_align(lv_calender, NULL, LV_ALIGN_CENTER, 0, 0);

	lv_group_add_obj(group, lv_calender);
	lv_obj_set_event_cb(lv_calender, event_handler);

	lv_obj_set_style_local_text_font(lv_calender, LV_CALENDAR_PART_DATE, LV_STATE_DEFAULT, lv_theme_get_font_small());

}

void GUI_Calender_FocusInit() {
	lv_group_focus_obj(lv_calender);
	today_init();
}

static void today_init() {
	today_task = lv_task_create_basic();
	lv_task_set_cb(today_task, today_init_task);
	lv_task_once(today_task);
}
