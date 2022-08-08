/****************************************************************************
FILE NAME
    ble_peripheral_tp_server.c

DESCRIPTION
    test profile demo

NOTES
*/
/****************************************************************************/

#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>

#include "app.h"
#include "bluetooth.h"
#include "conn.h"
#include "gatt.h"
#include "hci_core.h"
#include "uuid.h"
#include "ble_peripheral_tp_server.h"
#include "log.h"

#include "mytask.h"

static void ble_tp_connected(struct bt_conn* conn, u8_t err);
static void ble_tp_disconnected(struct bt_conn* conn, u8_t reason);

static struct bt_conn* ble_tp_conn;
#if !defined(CONFIG_BT_OAD_SERVER)
static struct bt_gatt_exchange_params exchg_mtu;
#endif

static struct k_sem notify_poll_sem;

static int tx_mtu_size = 20;
static u8_t created_tp_task = 0;
static u8_t isRegister = 0;

static uint16_t steps = 0;
static max30102_t max_sensor;

char data[4] = { };

static struct bt_conn_cb ble_tp_conn_callbacks = {
    .connected = ble_tp_connected,
    .disconnected = ble_tp_disconnected,
};

#if !defined(CONFIG_BT_OAD_SERVER)
/*************************************************************************
NAME
    ble_tp_tx_mtu_size
*/
static void ble_tp_tx_mtu_size(struct bt_conn* conn, u8_t err,
    struct bt_gatt_exchange_params* params) {
    if (!err) {
        tx_mtu_size = bt_gatt_get_mtu(ble_tp_conn);
    } else { }
}
#endif
/*************************************************************************
NAME
    ble_tp_connected
*/
static void ble_tp_connected(struct bt_conn* conn, u8_t err) {
#if !defined(CONFIG_BT_OAD_SERVER)
    int tx_octets = 0x00fb;
    int tx_time = 0x0848;
#endif

    if (err) {
        return;
    }

    ble_tp_conn = conn;

#if !defined(CONFIG_BT_OAD_SERVER)
    //set data length after connected.
    bt_le_set_data_len(ble_tp_conn, tx_octets, tx_time);

    //exchange mtu size after connected.
    exchg_mtu.func = ble_tp_tx_mtu_size;
    bt_gatt_exchange_mtu(ble_tp_conn, &exchg_mtu);

#endif
}

/*************************************************************************
NAME
    ble_tp_disconnected
*/
static void ble_tp_disconnected(struct bt_conn* conn, u8_t reason) {

    if (created_tp_task) {
        created_tp_task = 0;
    }

    ble_tp_conn = NULL;
}

/*************************************************************************
NAME
    ble_tp_recv_rd
*/
static int ble_tp_recv_rd(struct bt_conn* conn, const struct bt_gatt_attr* attr,
    void* buf, u16_t len, u16_t offset) {

    uint8_t size = 4;

    if (xQueueReceive(xSteps_Queue, &(steps), (TickType_t)10) == pdPASS) {
        data[0] = (steps >> 8);
        data[1] = steps & 0xff;
    }

    if (xQueuePeek(xMax_Queue, &(max_sensor), (TickType_t)10) == pdPASS) {
        if (max_sensor.isvalid == 1) {
            data[2] = max_sensor.Hrate;
            data[3] = max_sensor.SpO2;
        }
    }

    memcpy(buf, data, size);

    vTaskDelay(15 * 1000);

    return size;
}

/*************************************************************************
NAME
    ble_tp_recv_wr(receive data from client)
*/
static int ble_tp_recv_wr(struct bt_conn* conn, const struct bt_gatt_attr* attr,
    const void* buf, u16_t len, u16_t offset, u8_t flags) {

    if (flags & BT_GATT_WRITE_FLAG_PREPARE) {
        //Don't use prepare write data, execute write will upload data again.
        return 0;
    }

    if (flags & BT_GATT_WRITE_FLAG_CMD) {
        //Use write command data.
    } else {
        //Use write request / execute write data.
    }

    k_sem_give(&notify_poll_sem);
    return len;
}

/*************************************************************************
*  DEFINE : attrs
*/
static struct bt_gatt_attr attrs [] = {
    BT_GATT_PRIMARY_SERVICE(BT_UUID_SVC_BLE_TP),

    BT_GATT_CHARACTERISTIC(BT_UUID_CHAR_BLE_TP_RD,
                           BT_GATT_CHRC_READ,
                           BT_GATT_PERM_READ,
                           ble_tp_recv_rd,
                           NULL,
                           NULL),

    BT_GATT_CHARACTERISTIC(BT_UUID_CHAR_BLE_TP_WR,
                           BT_GATT_CHRC_WRITE | BT_GATT_CHRC_WRITE_WITHOUT_RESP,
                           BT_GATT_PERM_WRITE | BT_GATT_PERM_PREPARE_WRITE,
                           NULL,
                           ble_tp_recv_wr,
                           NULL),
};

/*************************************************************************
NAME
    get_attr
*/
struct bt_gatt_attr* get_attr(u8_t index) {
    return &attrs[index];
}

static struct bt_gatt_service ble_tp_server = BT_GATT_SERVICE(attrs);

/*************************************************************************
NAME
    ble_tp_init
*/
void ble_tp_init() {
    if (!isRegister) {
        isRegister = 1;
        bt_conn_cb_register(&ble_tp_conn_callbacks);
        bt_gatt_service_register(&ble_tp_server);
        k_sem_init(&notify_poll_sem, 0, 1);
    }
}
