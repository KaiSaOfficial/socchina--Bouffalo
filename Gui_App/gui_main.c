#include "gui_main.h"

static lv_obj_t* m_main;
Time_t time_s;

lv_obj_t* lv_lmeter;
lv_obj_t* lv_time_label;
lv_obj_t* lv_date_label;
lv_obj_t* lv_week_label;

lv_obj_t* lv_wifi_ico;
lv_obj_t* lv_hr_ico;
lv_obj_t* lv_step_label;

lv_task_t* time_task;

extern const char* Week [];
extern QueueHandle_t xSteps_Queue;
extern QueueHandle_t xWirelss_Queue;
PageRegHandler main_handler;

static void main_task(lv_task_t* task) {
	static uint32_t steps = 0;
	static uint8_t wireless = 0;

	lv_linemeter_set_value(lv_lmeter, time_s.sec);
	//设置时间
	// lv_label_set_text_fmt(lv_time_label, "%s", time_buff);
	lv_label_set_text_fmt(lv_time_label, "%02d : %02d : %02d", time_s.hour, time_s.min, time_s.sec);

	//设置日期
	lv_label_set_text_fmt(lv_date_label, "%02d/%02d/%02d", time_s.year, time_s.month, time_s.date);

	//设置星期
	if (time_s.week != 0) {
		lv_label_set_text_fmt(lv_week_label, "%s", Week[time_s.week - 1]);
	} else {
		lv_label_set_text_fmt(lv_week_label, "%s", Week[0]);
	}

	//设置步数
	if (xQueueReceive(xSteps_Queue, &(steps), (TickType_t)10) == pdPASS) {
		lv_label_set_text_fmt(lv_step_label, "%d", steps);
	}

	if (xQueuePeek(xWirelss_Queue, &(wireless), (TickType_t)10) == pdPASS) {
		lv_label_set_text(lv_wifi_ico, HWATCH_SYMBOL_CLOUD_DOWN);
	}
}

static void event_handler(lv_obj_t* obj, lv_event_t event) {
	switch (event) {
	case LV_EVENT_PRESSING:
		main_handler(p_apps, app_null);

		break;
	default:
		break;
	}
}

void GUI_Main_Init(lv_obj_t* pmain, lv_group_t* group, PageRegHandler handler) {
	m_main = pmain;
	main_handler = handler;

	lv_obj_set_size(m_main, WIN_W, WIN_H);
	//lv_obj_align(m_main, NULL, LV_ALIGN_CENTER, 0, 0);
	lv_obj_add_style(m_main, LV_OBJ_PART_MAIN, &page_style);
	lv_obj_set_event_cb(m_main, event_handler);
	lv_group_add_obj(group, m_main);

	//创建表盘
	lv_lmeter = lv_linemeter_create(m_main, NULL);
	lv_linemeter_set_range(lv_lmeter, 0, 60);
	lv_linemeter_set_value(lv_lmeter, 0);
	lv_linemeter_set_scale(lv_lmeter, 360, 61);
	lv_linemeter_set_angle_offset(lv_lmeter, 180);
	lv_obj_set_size(lv_lmeter, LCD_W - 18, LCD_H - 80);
	lv_obj_align(lv_lmeter, NULL, LV_ALIGN_CENTER, 0, 0);
	lv_obj_add_style(lv_lmeter, LV_LINEMETER_PART_MAIN, &lmeter_style);

	//时间标签
	lv_time_label = lv_label_create(m_main, NULL);
	//	lv_label_set_long_mode(lv_time_label, LV_LABEL_LONG_BREAK);
	//	lv_obj_set_width(lv_time_label, lv_page_get_width_fit(m_main));
	lv_label_set_long_mode(lv_time_label, LV_LABEL_LONG_SROLL_CIRC);
	lv_obj_set_size(lv_time_label, 200, 36);
	lv_label_set_text(lv_time_label, "23 : 59 : 59");
	lv_label_set_align(lv_time_label, LV_LABEL_ALIGN_CENTER);
	lv_obj_add_style(lv_time_label, LV_LABEL_PART_MAIN, &font_style);
	lv_obj_align(lv_time_label, NULL, LV_ALIGN_CENTER, 0, -18);

	//日期标签
	lv_date_label = lv_label_create(m_main, NULL);
	lv_label_set_long_mode(lv_date_label, LV_LABEL_LONG_SROLL_CIRC);
	lv_obj_set_size(lv_date_label, 200, 24);
	lv_label_set_text(lv_date_label, "21/01/01");
	lv_label_set_align(lv_date_label, LV_LABEL_ALIGN_CENTER);
	lv_obj_add_style(lv_date_label, LV_LABEL_PART_MAIN, &font_style1);
	lv_obj_align(lv_date_label, lv_time_label, LV_ALIGN_OUT_BOTTOM_MID, 0, 2);

	//星期标签
	lv_week_label = lv_label_create(m_main, NULL);
	lv_label_set_text(lv_week_label, "Sun");
	lv_obj_add_style(lv_week_label, LV_LABEL_PART_MAIN, &font_style1);
	lv_obj_align(lv_week_label, lv_time_label, LV_ALIGN_OUT_TOP_MID, 2, 0);

	lv_wifi_ico = lv_label_create(m_main, NULL);
	lv_obj_add_style(lv_wifi_ico, LV_LABEL_PART_MAIN, &icons_style);
	lv_obj_align(lv_wifi_ico, lv_time_label, LV_ALIGN_OUT_TOP_LEFT, 24, -6);

	lv_step_label = lv_label_create(m_main, NULL);
	lv_obj_add_style(lv_step_label, LV_LABEL_PART_MAIN, &font_style2);
	lv_label_set_text(lv_step_label, "0");
	lv_obj_align(lv_step_label, lv_time_label, LV_ALIGN_CENTER, 0, 60);

	lv_hr_ico = lv_label_create(m_main, NULL);
	lv_label_set_text(lv_hr_ico, HWATCH_SYMBOL_HEART);
	lv_obj_add_style(lv_hr_ico, LV_LABEL_PART_MAIN, &icons_style1);
	lv_obj_align(lv_hr_ico, lv_time_label, LV_ALIGN_OUT_TOP_LEFT, 50, -6);

	GUI_Main_FocusInit();
}

void GUI_Main_FocusInit() {
	lv_group_focus_obj(m_main);
	//创建主页更新任务，优先级设置为高
	time_task = lv_task_create(main_task, 1000, LV_TASK_PRIO_HIGHEST, NULL);
}

