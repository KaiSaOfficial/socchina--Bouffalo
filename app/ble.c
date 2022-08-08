#include "hal_uart.h"
#include <FreeRTOS.h>
#include "semphr.h"
#include "bluetooth.h"
#include "gap.h"
#include "bl702_glb.h"
#include "ble_peripheral_tp_server.h"
#include "ble_lib_api.h"
#include "hci_driver.h"
#include "bl702_sec_eng.h"

#include "ble.h"

int ble_start_adv(void) {
    struct bt_le_adv_param adv_param = {
        //options:3, connectable undirected, adv one time
        .options = (BT_LE_ADV_OPT_CONNECTABLE | BT_LE_ADV_OPT_USE_NAME | BT_LE_ADV_OPT_ONE_TIME),
        .interval_min = BT_GAP_ADV_FAST_INT_MIN_3,
        .interval_max = BT_GAP_ADV_FAST_INT_MAX_3,
    };

    //char *adv_name = "BL_TEST_01"; // This name must be the same as adv_name in ble_central
    struct bt_data adv_data [] = {
        BT_DATA_BYTES(BT_DATA_FLAGS, (BT_LE_AD_NO_BREDR | BT_LE_AD_GENERAL)),
        //BT_DATA(BT_DATA_NAME_COMPLETE, adv_name, strlen(adv_name)),
    };

    return bt_le_adv_start(&adv_param, adv_data, ARRAY_SIZE(adv_data), NULL, 0);
}

#if defined(CONFIG_BT_OAD_SERVER)
bool app_check_oad(u32_t cur_file_ver, u32_t new_file_ver) {
    //App layer decides whether to do oad according to file version
    /*if(new_file_ver > cur_file_ver)
        return true;
    else
        return false;*/
    return true;
}
#endif

void bt_enable_cb(int err) {
    ble_tp_init();
#if defined(CONFIG_BT_OAD_SERVER)
    oad_service_enable(app_check_oad);
#endif
    ble_start_adv();
}

void ble_init(void) {
    GLB_Set_EM_Sel(GLB_EM_8KB);
    ble_controller_init(configMAX_PRIORITIES);

    // Initialize BLE Host stack
    hci_driver_init();

    bt_enable(bt_enable_cb);
}

