#ifndef __AT_H_
#define __AT_H_

enum at_resp_status {
    AT_RESP_OK = 0,         /* AT response end is OK */
    AT_RESP_ERROR = -1,     /* AT response end is ERROR */
    AT_RESP_TIMEOUT = -2,   /* AT response is timeout */
    AT_RESP_BUFF_FULL = -3, /* AT response buffer is full */
};

struct at_client {
    /* the current received one line data buffer */
    uint8_t* recv_line_buf;
    /* The length of the currently received one line data */
    uint32_t recv_line_len;
    /* The maximum supported receive data length */
    uint32_t recv_bufsz;

    uint32_t timeout;
    const char* resp_succ;
    const char* resp_err;
    enum at_resp_status resp_status;
};

uint8_t at_init(void);
uint8_t init_WiFi(void);

void at_send_steps_ontnet(uint32_t steps);
void at_send_heart_ontnet(uint32_t heart);
void at_send_SpO2_ontnet(uint32_t SpO2);
void at_send_fall_ontnet(uint8_t stat);
void at_send_medi_ontnet(uint8_t stat);

void at_get_time_str(char* str);
void at_get_step_str(char* str);

#endif
