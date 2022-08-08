#include "bflb_platform.h"
#include "hal_uart.h"
#include "at_cmd.h"
#include "ring_buffer.h"
#include "FreeRTOS.h"
#include "task.h"

#include "string.h"

#define DEVICEID "961566655"      //onenet的设备号
#define API_KEY "W8tIfmkQzEnU4ea5StAHRew4P90="  //自己设备的api-key
#define ONENET_IP "183.230.40.33"  //onenent的ip
#define ONENET_PORT "80"     //onenet的端口号
#define SSID  "Mark"
#define PWD  "616820595"

const char time_web [] = "http://api.k780.com/?app=life.time&appkey=10003&sign=b59bc3ef6191eb9f747dd4e83c99f2a4&format=json HTTP/1.0\r\n\r\n";

// #define SSID   "Redmi K30 5G"
// #define PWD    "qwerasdf"

// #define SSID  "OPPO"
// #define PWD  "abcd1234"
// #define SSID  "ppiphone"
// #define PWD  "12345678"
// #define SSID  "201"
// #define PWD  "18851977875"

#define UART_RECV_BUF_SZIE 64    //接收BUFF的大小
#define UART_SEND_BUF_SIZE 1024  //发送BUFF的大小
#define UART_JSON_BUF_SIZE 500   //json数据存放的大小

uint8_t recv_buf[UART_RECV_BUF_SZIE];
char tcp_buffer[UART_SEND_BUF_SIZE];
char ble_buffer[UART_SEND_BUF_SIZE];
char json_data[UART_JSON_BUF_SIZE];

uint32_t recv_len = 0;
uint8_t recv_buffer[1024] = { 0 };

struct at_client static_client;

#define UART_SEND_BUF_SZIE 1024
char send_buf[UART_SEND_BUF_SZIE] = { 0 };

#define UART_RX_RINGBUFFER_SIZE (1 * 1024)

uint8_t uart_rx_mem[UART_RX_RINGBUFFER_SIZE];

struct device* uart1;
Ring_Buffer_Type uart1_rx_rb;

static void uart1_irq_callback(struct device* dev, void* args, uint32_t size, uint32_t state) {
    Ring_Buffer_Write(&uart1_rx_rb, (uint8_t*)args, size);
}

static uint32_t at_vprintfln(const char* format, va_list args) {
    uint32_t len;

    len = vsnprintf(send_buf, sizeof(send_buf) - 2, format, args);
    if (len > sizeof(send_buf) - 2)
        len = sizeof(send_buf) - 2;
    memcpy(send_buf + len, "\r\n", 2);

    len = len + 2;
    MSG("%s\r\n", send_buf);
    device_control(uart1, DEVICE_CTRL_CLR_INT, (void*)(UART_RX_FIFO_IT | UART_RTO_IT));
    uart1->oflag &= ~DEVICE_OFLAG_INT_RX;
    return device_write(uart1, 0, (uint8_t*)send_buf, len);
}

static int at_read_line(struct at_client* client) {
    uint32_t read_len = 0;
    uint32_t start_time = 0;
    char ch = 0, last_ch = 0;

    memset(client->recv_line_buf, 0, client->recv_bufsz);
    client->recv_line_len = 0;

    start_time = bflb_platform_get_time_ms();
    while (1) {
        while (device_read(uart1, 0, &ch, 1) == 0) {
            if ((bflb_platform_get_time_ms() - start_time) > client->timeout) {
                client->resp_status = AT_RESP_TIMEOUT;
                return AT_RESP_TIMEOUT;
            }
        }

        if (read_len < client->recv_bufsz) {
            client->recv_line_buf[read_len++] = ch;
            client->recv_line_len = read_len;
        } else {
            MSG("buf full\r\n");
            client->resp_status = AT_RESP_BUFF_FULL;
            return AT_RESP_BUFF_FULL;
        }

        if (ch == '\n' && last_ch == '\r') {
            if (strstr((const char*)client->recv_line_buf, (const char*)client->resp_succ)) {
                client->resp_status = AT_RESP_OK;
                goto match_out;
            } else if (client->resp_err && strstr((const char*)client->recv_line_buf, (const char*)client->resp_err)) {
                client->resp_status = AT_RESP_ERROR;
                goto match_out;
            }
        }
        last_ch = ch;
    }

match_out:
    MSG("%s", client->recv_line_buf);
    return read_len;
}

static int at_exe_cmd(struct at_client* client, char* cmd_expr, ...) {
    va_list ap;

    va_start(ap, cmd_expr);
    at_vprintfln(cmd_expr, ap);
    va_end(ap);

    return at_read_line(client);
}

static int at_write_recv(uint8_t* send_buffer, uint32_t send_len, uint8_t* recv_buffer, uint32_t* recv_len, uint32_t timeout) {
    int ret = 0;
    uint8_t found = 0;
    uint32_t read_len = 0;
    uint32_t start_time = 0;
    uint8_t ch = 0, last_ch = 0;
    uint8_t tmp_buf[32] = { 0 };
    const char* found_string = "+IPD:0,";
    uint8_t found_index = 0;

    struct at_client static_client;

    static_client.recv_line_buf = tmp_buf;
    static_client.recv_bufsz = 32;
    static_client.resp_succ = ">";
    static_client.resp_err = "FAIL";
    static_client.timeout = 1000;
    ret = at_exe_cmd(&static_client, "AT+CIPSEND=0,%d", send_len);
    if (ret < 0) {
        return -1;
    }

    Ring_Buffer_Reset(&uart1_rx_rb);
    device_control(uart1, DEVICE_CTRL_SET_INT, (void*)(UART_RX_FIFO_IT | UART_RTO_IT));
    device_write(uart1, 0, (uint8_t*)send_buffer, send_len);

    if (recv_buffer == NULL) {
        return 0;
    }

    uint8_t* p = recv_buffer;
    start_time = bflb_platform_get_time_ms();
    while (1) {
        while (Ring_Buffer_Read_Byte(&uart1_rx_rb, &ch) == 0) {
            if ((bflb_platform_get_time_ms() - start_time) > timeout) {
                return AT_RESP_TIMEOUT;
            }
        }

        if (found == 0) {
            tmp_buf[found_index++] = ch;
            if (strstr((const char*)tmp_buf, found_string)) {
                found = 1;
                found_index = 0;
            }
        } else if (found == 1) {
            tmp_buf[found_index++] = ch;
            if (ch == '\n' && last_ch == '\r') {
                if (found_index == 3) {
                    read_len = (tmp_buf[0] - '0');
                } else if (found_index == 4) {
                    read_len = (tmp_buf[0] - '0') * 10 + (tmp_buf[1] - '0');
                } else if (found_index == 5) {
                    read_len = (tmp_buf[0] - '0') * 100 + (tmp_buf[1] - '0') * 10 + (tmp_buf[2] - '0');
                }
                *recv_len = read_len;
                found = 2;
            }
            last_ch = ch;
        } else {
            *p++ = ch;
            read_len--;
            if (read_len == 0) {
                return 0;
            }
        }
    }
    return 0;
}

static void at_client_init() {
    Ring_Buffer_Init(&uart1_rx_rb, uart_rx_mem, UART_RX_RINGBUFFER_SIZE, cpu_global_irq_disable, cpu_global_irq_enable);

    uart_register(UART1_INDEX, "uart1");
    uart1 = device_find("uart1");

    if (uart1) {
        UART_DEV(uart1)->baudrate = 115200;
        device_open(uart1, DEVICE_OFLAG_STREAM_TX | DEVICE_OFLAG_INT_RX);
        device_set_callback(uart1, uart1_irq_callback);
        device_control(uart1, DEVICE_CTRL_SET_INT, (void*)(UART_RX_FIFO_IT | UART_RTO_IT));
        Ring_Buffer_Reset(&uart1_rx_rb);
    }
}

uint8_t at_init(void) {

    at_client_init();

    return 1;
}

uint8_t init_WiFi() {

    static_client.recv_line_buf = recv_buf;
    static_client.recv_bufsz = UART_RECV_BUF_SZIE;

    static_client.resp_succ = "OK";
    static_client.resp_err = NULL;
    static_client.timeout = 2000;

    at_exe_cmd(&static_client, "AT+RST");

    do {
        at_exe_cmd(&static_client, "AT+CWMODE=1");
    } while (static_client.resp_status < 0);

    at_exe_cmd(&static_client, "AT+CWAUTOCONN=1");
    vTaskDelay(1000);
    //    ret = at_exe_cmd(&static_client, "AT+CIPRECVCFG=1");   //这种方式会照成配置不成功
    do {
        at_exe_cmd(&static_client, "AT+CIPRECVCFG=1");
        vTaskDelay(1000);
    } while (static_client.resp_status < 0);

    static_client.resp_succ = "wifi connected";
    static_client.resp_err = NULL;
    static_client.timeout = 20000;

    while (at_exe_cmd(&static_client, "AT+CWJAP=\"%s\",\"%s\"", SSID, PWD) < 0) {
    }

    return 1;
}

void at_send_steps_ontnet(uint32_t steps) {

    memset(json_data, 0, sizeof(json_data));
    memset(tcp_buffer, 0, sizeof(tcp_buffer));
    snprintf(json_data, sizeof(json_data) - 2, "{\"datastreams\":[{\"id\":\"steps\",\"datapoints\":[{\"value\":%ld}]}]}", steps);
    snprintf(tcp_buffer, sizeof(tcp_buffer) - 2, "POST /devices/%s/datapoints HTTP/1.1\r\n"
        "api-key:%s\r\n"
        "Host:api.heclouds.com\r\n"
        "Content-Length:%d\r\n\r\n"
        "%s\r\n", DEVICEID, API_KEY, strlen(json_data), json_data);

    static_client.resp_succ = "+CIPSTA";
    static_client.resp_err = "";
    static_client.timeout = 5000;
    at_exe_cmd(&static_client, "AT+CIPSTART?");
    vTaskDelay(1000);

    if (static_client.resp_status < 0) {
        static_client.resp_succ = "+IPS:0,CONNECTED";
        static_client.resp_err = "ERROR: Connect fail";
        static_client.timeout = 5000;

        while (at_exe_cmd(&static_client, "AT+CIPSTART=0,TCP,%s,%s", ONENET_IP, ONENET_PORT) < 0) {
            vTaskDelay(200);
        }

    }

    at_write_recv((uint8_t*)tcp_buffer, strlen(tcp_buffer), recv_buffer, &recv_len, 5000);

}

void at_send_heart_ontnet(uint32_t heart) {

    memset(json_data, 0, sizeof(json_data));
    memset(tcp_buffer, 0, sizeof(tcp_buffer));
    snprintf(json_data, sizeof(json_data) - 2, "{\"datastreams\":[{\"id\":\"heart\",\"datapoints\":[{\"value\":%ld}]}]}", heart);
    snprintf(tcp_buffer, sizeof(tcp_buffer) - 2, "POST /devices/%s/datapoints HTTP/1.1\r\n"
        "api-key:%s\r\n"
        "Host:api.heclouds.com\r\n"
        "Content-Length:%d\r\n\r\n"
        "%s\r\n", DEVICEID, API_KEY, strlen(json_data), json_data);

    static_client.resp_succ = "+CIPSTA";
    static_client.resp_err = "";
    static_client.timeout = 5000;
    at_exe_cmd(&static_client, "AT+CIPSTART?");
    vTaskDelay(1000);

    if (static_client.resp_status < 0) {
        static_client.resp_succ = "+IPS:0,CONNECTED";
        static_client.resp_err = "ERROR: Connect fail";
        static_client.timeout = 5000;

        while (at_exe_cmd(&static_client, "AT+CIPSTART=0,TCP,%s,%s", ONENET_IP, ONENET_PORT) < 0) {
            vTaskDelay(200);
        }

    }

    at_write_recv((uint8_t*)tcp_buffer, strlen(tcp_buffer), recv_buffer, &recv_len, 5000);

}

void at_send_SpO2_ontnet(uint32_t steps) {

    memset(json_data, 0, sizeof(json_data));
    memset(tcp_buffer, 0, sizeof(tcp_buffer));
    snprintf(json_data, sizeof(json_data) - 2, "{\"datastreams\":[{\"id\":\"SpO2\",\"datapoints\":[{\"value\":%ld}]}]}", steps);
    snprintf(tcp_buffer, sizeof(tcp_buffer) - 2, "POST /devices/%s/datapoints HTTP/1.1\r\n"
        "api-key:%s\r\n"
        "Host:api.heclouds.com\r\n"
        "Content-Length:%d\r\n\r\n"
        "%s\r\n", DEVICEID, API_KEY, strlen(json_data), json_data);

    static_client.resp_succ = "+CIPSTA";
    static_client.resp_err = "";
    static_client.timeout = 5000;
    at_exe_cmd(&static_client, "AT+CIPSTART?");

    if (static_client.resp_status < 0) {
        static_client.resp_succ = "+IPS:0,CONNECTED";
        static_client.resp_err = "ERROR: Connect fail";
        static_client.timeout = 5000;

        while (at_exe_cmd(&static_client, "AT+CIPSTART=0,TCP,%s,%s", ONENET_IP, ONENET_PORT) < 0) {
        }

        vTaskDelay(200);
    }

    at_write_recv((uint8_t*)tcp_buffer, strlen(tcp_buffer), recv_buffer, &recv_len, 5000);

}

void at_send_fall_ontnet(uint8_t stat) {
    memset(json_data, 0, sizeof(json_data));
    memset(tcp_buffer, 0, sizeof(tcp_buffer));
    snprintf(json_data, sizeof(json_data) - 2, "{\"datastreams\":[{\"id\":\"fall\",\"datapoints\":[{\"value\":%d}]}]}", stat);
    snprintf(tcp_buffer, sizeof(tcp_buffer) - 2, "POST /devices/%s/datapoints HTTP/1.1\r\n"
        "api-key:%s\r\n"
        "Host:api.heclouds.com\r\n"
        "Content-Length:%d\r\n\r\n"
        "%s\r\n", DEVICEID, API_KEY, strlen(json_data), json_data);

    static_client.resp_succ = "+CIPSTA";
    static_client.resp_err = "";
    static_client.timeout = 5000;
    at_exe_cmd(&static_client, "AT+CIPSTART?");

    if (static_client.resp_status < 0) {
        static_client.resp_succ = "+IPS:0,CONNECTED";
        static_client.resp_err = "ERROR: Connect fail";
        static_client.timeout = 5000;

        while (at_exe_cmd(&static_client, "AT+CIPSTART=0,TCP,%s,%s", ONENET_IP, ONENET_PORT) < 0) {
        }

        vTaskDelay(200);
    }

    at_write_recv((uint8_t*)tcp_buffer, strlen(tcp_buffer), recv_buffer, &recv_len, 5000);
}

void at_send_medi_ontnet(uint8_t stat) {
    memset(json_data, 0, sizeof(json_data));
    memset(tcp_buffer, 0, sizeof(tcp_buffer));
    snprintf(json_data, sizeof(json_data) - 2, "{\"datastreams\":[{\"id\":\"medicine\",\"datapoints\":[{\"value\":%d}]}]}", stat);
    snprintf(tcp_buffer, sizeof(tcp_buffer) - 2, "POST /devices/%s/datapoints HTTP/1.1\r\n"
        "api-key:%s\r\n"
        "Host:api.heclouds.com\r\n"
        "Content-Length:%d\r\n\r\n"
        "%s\r\n", DEVICEID, API_KEY, strlen(json_data), json_data);

    static_client.resp_succ = "+CIPSTA";
    static_client.resp_err = "";
    static_client.timeout = 5000;
    at_exe_cmd(&static_client, "AT+CIPSTART?");

    if (static_client.resp_status < 0) {
        static_client.resp_succ = "+IPS:0,CONNECTED";
        static_client.resp_err = "ERROR: Connect fail";
        static_client.timeout = 5000;

        while (at_exe_cmd(&static_client, "AT+CIPSTART=0,TCP,%s,%s", ONENET_IP, ONENET_PORT) < 0) {
        }

        vTaskDelay(200);
    }

    at_write_recv((uint8_t*)tcp_buffer, strlen(tcp_buffer), recv_buffer, &recv_len, 5000);
}

void at_get_time_str(char* buff) {

    memset(tcp_buffer, 0, sizeof(tcp_buffer));

    snprintf(tcp_buffer, sizeof(tcp_buffer) - 2, "GET http://api.k780.com/?app=life.time&appkey=10003&sign=b59bc3ef6191eb9f747dd4e83c99f2a4&format=json HTTP/1.0\r\n\r\n");

    static_client.resp_succ = "+CIPSTA";
    static_client.resp_err = "";
    static_client.timeout = 5000;
    at_exe_cmd(&static_client, "AT+CIPSTART?");

    if (static_client.resp_status < 0) {
        static_client.resp_succ = "+IPS:0,CONNECTED";
        static_client.resp_err = "ERROR: Connect fail";
        static_client.timeout = 5000;

        while (at_exe_cmd(&static_client, "AT+CIPSTART=0,TCP,%s,%s", ONENET_IP, ONENET_PORT) < 0) {
        }

        vTaskDelay(200);
    }

    at_write_recv((uint8_t*)tcp_buffer, strlen(tcp_buffer), recv_buffer, &recv_len, 5000);

    memcpy(buff, (char*)(recv_buffer + 43), 32);
}

void at_get_step_str(char* buff) {

    memset(tcp_buffer, 0, sizeof(tcp_buffer));

    snprintf(tcp_buffer, sizeof(tcp_buffer) - 2, "GET /devices/961566655/datapoints?datastream_id=steps HTTP/1.1\r\napi-key:W8tIfmkQzEnU4ea5StAHRew4P90=\r\nHost:api.heclouds.com\r\n\r\n");

    static_client.resp_succ = "+CIPSTA";
    static_client.resp_err = "";
    static_client.timeout = 5000;
    at_exe_cmd(&static_client, "AT+CIPSTART?");

    if (static_client.resp_status < 0) {
        static_client.resp_succ = "+IPS:0,CONNECTED";
        static_client.resp_err = "ERROR: Connect fail";
        static_client.timeout = 5000;

        while (at_exe_cmd(&static_client, "AT+CIPSTART=0,TCP,%s,%s", ONENET_IP, ONENET_PORT) < 0) {
        }

        vTaskDelay(200);
    }

    at_write_recv((uint8_t*)tcp_buffer, strlen(tcp_buffer), recv_buffer, &recv_len, 5000);

    memcpy(buff, (char*)(recv_buffer + 252), 34);

}
