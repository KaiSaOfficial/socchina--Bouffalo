#include "gui_about.h"

static lv_obj_t* m_about;

lv_obj_t* lv_title_about_label;
lv_obj_t* lv_content_label;
lv_obj_t* lv_version_label;

PageRegHandler about_handler;

static void event_handler(lv_obj_t* obj, lv_event_t event) {
	switch (event) {
	case LV_EVENT_PRESSING: {
		break;
	}

	case LV_EVENT_KEY:
	{
		const uint32_t* key = lv_event_get_data();
		if (*key == LV_KEY_BACKSPACE) {
			about_handler(p_apps, app_null);
		}
		break;
	}

	default:
		break;
	}
}

void GUI_About_Init(lv_obj_t* pabout, lv_group_t* group, PageRegHandler handler) {
	m_about = pabout;
	about_handler = handler;

	lv_obj_set_size(m_about, WIN_W, WIN_H);
	lv_obj_add_style(m_about, LV_OBJ_PART_MAIN, &page_style);
	lv_obj_set_event_cb(m_about, event_handler);
	lv_group_add_obj(group, m_about);

	lv_title_about_label = lv_label_create(m_about, NULL);
	lv_label_set_text(lv_title_about_label, APP_ABOUT);
	lv_obj_add_style(lv_title_about_label, LV_LABEL_PART_MAIN, &font_style2);
	lv_obj_align(lv_title_about_label, NULL, LV_ALIGN_IN_TOP_MID, 0, 20);

	lv_content_label = lv_label_create(m_about, NULL);
	lv_label_set_text(lv_content_label, CONTENT);
	lv_obj_add_style(lv_content_label, LV_LABEL_PART_MAIN, &font_style1);
	lv_label_set_align(lv_content_label, LV_LABEL_ALIGN_CENTER);
	lv_obj_align(lv_content_label, NULL, LV_ALIGN_CENTER, 0, 10);

}

void GUI_About_FocusInit() {
	lv_group_focus_obj(m_about);
}