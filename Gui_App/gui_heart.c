#include "gui_heart.h"
#include "app.h"

#include "task.h"
#include "mytask.h"

static lv_obj_t* m_heart;

lv_obj_t* lv_msg_label;
lv_obj_t* lv_title_heart_label;
lv_obj_t* lv_heart_label;
lv_obj_t* lv_spo2_label;
lv_task_t* beat_task;

static max30102_t max_sen;
PageRegHandler heart_handler;

static void heart_task(lv_task_t* task) {
	if (xQueuePeek(xMax_Queue, &(max_sen), (TickType_t)10) == pdPASS) {
		if (max_sen.isvalid == 1) {
			lv_label_set_text_fmt(lv_heart_label, "heartrate:%d", max_sen.Hrate);
			lv_label_set_text_fmt(lv_spo2_label, "SpO2:%d", max_sen.SpO2);

			lv_label_set_text_fmt(lv_msg_label, "Measurement Succeed");

			max_sen.isvalid = 0;
		}
	}
}

static void event_handler(lv_obj_t* obj, lv_event_t event) {
	switch (event) {
	case LV_EVENT_KEY:
	{
		const uint32_t* key = lv_event_get_data();
		if (*key == LV_KEY_BACKSPACE) {
			lv_task_del(beat_task);
			heart_handler(p_apps, app_null);
			break;
		} else if (*key == LV_KEY_UP) {
			lv_label_set_text_fmt(lv_msg_label, "Measuring");
			xTaskAbortDelay(xTaskGetHandle((char*)"max30102_task"));
			taskYIELD();
		}
	}

	default:
		break;
	}
}

void GUI_Heart_Init(lv_obj_t* pheart, lv_group_t* group, PageRegHandler handler) {
	m_heart = pheart;
	heart_handler = handler;

	lv_obj_set_size(m_heart, WIN_W, WIN_H);
	lv_obj_add_style(m_heart, LV_OBJ_PART_MAIN, &page_style);
	lv_obj_set_event_cb(m_heart, event_handler);
	lv_group_add_obj(group, m_heart);

	lv_title_heart_label = lv_label_create(m_heart, NULL);
	lv_label_set_text(lv_title_heart_label, APP_HEART);
	lv_obj_add_style(lv_title_heart_label, LV_LABEL_PART_MAIN, &font_style2);
	lv_obj_align(lv_title_heart_label, NULL, LV_ALIGN_IN_TOP_MID, 0, 20);

	lv_heart_label = lv_label_create(m_heart, NULL);
	lv_label_set_long_mode(lv_heart_label, LV_LABEL_LONG_SROLL_CIRC);
	lv_obj_set_size(lv_heart_label, 180, 36);
	lv_label_set_text(lv_heart_label, "heartrate:");
	lv_label_set_align(lv_heart_label, LV_LABEL_ALIGN_CENTER);
	lv_obj_add_style(lv_heart_label, LV_LABEL_PART_MAIN, &font_style2);
	lv_obj_align(lv_heart_label, NULL, LV_ALIGN_CENTER, 0, -18);

	lv_spo2_label = lv_label_create(m_heart, NULL);
	lv_label_set_long_mode(lv_spo2_label, LV_LABEL_LONG_SROLL_CIRC);
	lv_obj_set_size(lv_spo2_label, 180, 36);
	lv_label_set_text(lv_spo2_label, "SpO2:");
	lv_label_set_align(lv_spo2_label, LV_LABEL_ALIGN_CENTER);
	lv_obj_add_style(lv_spo2_label, LV_LABEL_PART_MAIN, &font_style2);
	lv_obj_align(lv_spo2_label, NULL, LV_ALIGN_CENTER, 0, -50);

	lv_msg_label = lv_label_create(m_heart, NULL);
	lv_label_set_long_mode(lv_msg_label, LV_LABEL_LONG_SROLL_CIRC);
	lv_obj_set_size(lv_msg_label, 180, 36);
	lv_label_set_text(lv_msg_label, "");
	lv_label_set_align(lv_msg_label, LV_LABEL_ALIGN_CENTER);
	lv_obj_add_style(lv_msg_label, LV_LABEL_PART_MAIN, &font_style2);
	lv_obj_align(lv_msg_label, NULL, LV_ALIGN_CENTER, 0, 82);

}

void GUI_Heart_FocusInit() {
	lv_group_focus_obj(m_heart);

	//创建任务
	beat_task = lv_task_create(heart_task, 20, LV_TASK_PRIO_MID, NULL);
}

