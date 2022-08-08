#include "gui_sysinfo.h"

static lv_obj_t* m_sysinfo;

lv_obj_t* lv_title_sysinfo_label;
lv_obj_t* lv_info_label;

PageRegHandler sysinfo_handler;

const char sys_info[255];

static void event_handler(lv_obj_t* obj, lv_event_t event) {
	switch (event) {
	case LV_EVENT_KEY:
	{
		const uint32_t* key = lv_event_get_data();
		if (*key == LV_KEY_ENTER) {

		} else if (*key == LV_KEY_BACKSPACE) {
			sysinfo_handler(p_apps, app_null);
		}
	}
	break;
	default:
		break;
	}
}

void GUI_SYSInfo_Init(lv_obj_t* psys, lv_group_t* group, PageRegHandler handler) {
	m_sysinfo = psys;
	sysinfo_handler = handler;

	// sys_info_init();

	lv_obj_set_size(m_sysinfo, WIN_W, WIN_H);
	lv_obj_add_style(m_sysinfo, LV_OBJ_PART_MAIN, &page_style);
	lv_obj_set_event_cb(m_sysinfo, event_handler);
	lv_group_add_obj(group, m_sysinfo);

	lv_title_sysinfo_label = lv_label_create(m_sysinfo, NULL);
	lv_label_set_text(lv_title_sysinfo_label, APP_SYSINFO);
	lv_obj_add_style(lv_title_sysinfo_label, LV_LABEL_PART_MAIN, &font_style2);
	lv_obj_align(lv_title_sysinfo_label, NULL, LV_ALIGN_IN_TOP_MID, 0, 10);

	lv_info_label = lv_label_create(m_sysinfo, NULL);
	lv_label_set_text(lv_info_label, sys_info);
	lv_label_set_align(lv_info_label, LV_LABEL_ALIGN_CENTER);
	lv_obj_add_style(lv_info_label, LV_LABEL_PART_MAIN, &font_style1);
	lv_obj_align(lv_info_label, NULL, LV_ALIGN_CENTER, 0, 10);

}

void GUI_SYSInfo_FocusInit() {
	lv_group_focus_obj(m_sysinfo);
	lv_label_set_text(lv_info_label, sys_info);
}

