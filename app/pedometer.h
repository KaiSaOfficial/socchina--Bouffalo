/*file pedometer.h*/

#ifndef __PEDOMETER_H_
#define __PEDOMETER_H_

#include "bflb_platform.h"

#define FILTER_CNT 4

#define SAMPLE_SIZE 50

#define DYNAMIC_PRECISION 360 /*动态精度*/

#define ACTIVE_PRECISION 100 /*活跃轴最小变化值*/

enum {
	MOST_ACTIVE_NULL = 0,
	MOST_ACTIVE_X,		/*最活跃轴X*/
	MOST_ACTIVE_Y,		/*最活跃轴Y*/
	MOST_ACTIVE_Z		/*最活跃轴Z*/
};

//三轴数据
typedef struct {
	short x;
	short y;
	short z;
} axis_info_t;

//平均值结构
typedef struct filter_avg {
	axis_info_t info[FILTER_CNT];
	unsigned char count;
} filter_avg_t;

//新旧三轴最值数据结构
typedef struct {
	/*
		typedef struct {
		short x;
		short y;
		short z;
		}axis_info_t;
	*/
	axis_info_t newmax;
	axis_info_t newmin;
	axis_info_t oldmax;
	axis_info_t oldmin;
} peak_value_t;

/*一个线性移位寄存器，用于过滤高频噪声*/
typedef struct slid_reg {
	axis_info_t new_sample;
	axis_info_t old_sample;
} slid_reg_t;

extern peak_value_t peak;

//初始化采样结构体的值
void peak_value_init(peak_value_t* peak);

//得到步数
uint16_t get_step();

void sync_local_step(uint16_t newstep);

#endif