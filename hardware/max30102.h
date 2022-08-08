#ifndef __MAX_30102_H__
#define __MAX_30102_H__

#include "bflb_platform.h"

extern const int32_t BUFFER_SIZE;

extern uint8_t max_sensoractive;

void max30102_init();
void max30102_ReadFifo(uint32_t* pun_red_led, uint32_t* pun_ir_led);

void max30102_ON(void);
void max30102_OFF(void);

void rf_heart_rate_and_oxygen_saturation(uint32_t* pun_ir_buffer, int32_t n_ir_buffer_length, uint32_t* pun_red_buffer, float* pn_spo2, int8_t* pch_spo2_valid, int32_t* pn_heart_rate,
    int8_t* pch_hr_valid, float* ratio, float* correl);
float rf_linear_regression_beta(float* pn_x, float xmean, float sum_x2);
float rf_autocorrelation(float* pn_x, int32_t n_size, int32_t n_lag);
float rf_rms(float* pn_x, int32_t n_size, float* sumsq);
float rf_Pcorrelation(float* pn_x, float* pn_y, int32_t n_size);
void rf_initialize_periodicity_search(float* pn_x, int32_t n_size, int32_t* p_last_periodicity, int32_t n_max_distance, float min_aut_ratio, float aut_lag0);
void rf_signal_periodicity(float* pn_x, int32_t n_size, int32_t* p_last_periodicity, int32_t n_min_distance, int32_t n_max_distance, float min_aut_ratio, float aut_lag0, float* ratio);


#endif //__MAX_30102_H__
