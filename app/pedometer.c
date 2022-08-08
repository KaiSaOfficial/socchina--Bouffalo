#include "Pedometer.h"
#include "mpu9250.h"

#define ABS(a) (0 - (a)) > 0 ? (-(a)) : (a)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

static unsigned int step_cnt = 0;		//step_cnt为步数

uint8_t num;
uint16_t temp_step = 0;
//uint comdata[3];
uint16_t axis_x, axis_y, axis_z;
uint16_t array_accel[3] = { 0 };
axis_info_t sample;
filter_avg_t filter;
axis_info_t cur_sample;
peak_value_t peak;
slid_reg_t slid;


//读取xyz数据存入均值滤波器，存满进行计算，滤波后样本存入sample（FILTER_CNT个数据的平均值）
static void filter_calculate(filter_avg_t* filter, axis_info_t* sample) {
	unsigned int num;
	short x_sum = 0, y_sum = 0, z_sum = 0;
	for (num = 0; num < FILTER_CNT; num++) {
		x_sum += filter->info[num].x;
		y_sum += filter->info[num].y;
		z_sum += filter->info[num].z;
	}
	sample->x = x_sum / FILTER_CNT;
	sample->y = y_sum / FILTER_CNT;
	sample->z = z_sum / FILTER_CNT;
}

//初始化采样结构体的值
void peak_value_init(peak_value_t* peak) {
	peak->newmax.x = 0;
	peak->newmax.y = 0;
	peak->newmax.z = 0;

	peak->newmin.x = 2048;
	peak->newmin.y = 2048;
	peak->newmin.z = 2048;
}

//在动态阈值结构体初始化时，一定要将max的值都赋值为最小值，min赋值为最大值，这样才有利于动态更新。
static void peak_update(peak_value_t* peak, axis_info_t* cur_sample) {
	static unsigned int sample_size = 0;
	sample_size++;
	if (sample_size > SAMPLE_SIZE) {
		/*采样达到50个，更新一次*/
		sample_size = 1;
		peak->oldmax = peak->newmax;
		peak->oldmin = peak->newmin;
		//初始化
		peak_value_init(peak);
	}
	peak->newmax.x = MAX(peak->newmax.x, cur_sample->x);
	peak->newmax.y = MAX(peak->newmax.y, cur_sample->y);
	peak->newmax.z = MAX(peak->newmax.z, cur_sample->z);

	peak->newmin.x = MIN(peak->newmin.x, cur_sample->x);
	peak->newmin.y = MIN(peak->newmin.y, cur_sample->y);
	peak->newmin.z = MIN(peak->newmin.z, cur_sample->z);
}

//更新数据
static char slid_update(slid_reg_t* slid, axis_info_t* cur_sample) {
	char res = 0;
	if (ABS((cur_sample->x - slid->new_sample.x)) > DYNAMIC_PRECISION) {
		slid->old_sample.x = slid->new_sample.x;
		slid->new_sample.x = cur_sample->x;
		res = 1;
	} else {
		slid->old_sample.x = slid->new_sample.x;
	}
	if (ABS((cur_sample->y - slid->new_sample.y)) > DYNAMIC_PRECISION) {
		slid->old_sample.y = slid->new_sample.y;
		slid->new_sample.y = cur_sample->y;
		res = 1;
	} else {
		slid->old_sample.y = slid->new_sample.y;
	}

	if (ABS((cur_sample->z - slid->new_sample.z)) > DYNAMIC_PRECISION) {
		slid->old_sample.z = slid->new_sample.z;
		slid->new_sample.z = cur_sample->z;
		res = 1;
	} else {
		slid->old_sample.z = slid->new_sample.z;
	}
	return res;
}

/*判断当前最活跃轴*/
static char is_most_active(peak_value_t* peak) {
	char res = MOST_ACTIVE_NULL;
	short x_change = ABS((peak->newmax.x - peak->newmin.x));
	short y_change = ABS((peak->newmax.y - peak->newmin.y));
	short z_change = ABS((peak->newmax.z - peak->newmin.z));

	if (x_change > y_change && x_change > z_change && x_change >= ACTIVE_PRECISION) {
		res = MOST_ACTIVE_X;
	} else if (y_change > x_change && y_change > z_change && y_change >= ACTIVE_PRECISION) {
		res = MOST_ACTIVE_Y;
	} else if (z_change > x_change && z_change > y_change && z_change >= ACTIVE_PRECISION) {
		res = MOST_ACTIVE_Z;
	}
	return res;
}

/*判断是否走步*/
static unsigned int detect_step(peak_value_t* peak, slid_reg_t* slid) {
	char res = is_most_active(peak);
	switch (res) {
	case MOST_ACTIVE_NULL:
	{
		//fix
		break;
	}
	case MOST_ACTIVE_X:
	{
		short threshold_x = (peak->oldmax.x + peak->oldmin.x) / 2;
		if (slid->old_sample.x > threshold_x && slid->new_sample.x < threshold_x) {
			step_cnt++;
		}
		break;
	}
	case MOST_ACTIVE_Y:
	{
		short threshold_y = (peak->oldmax.y + peak->oldmin.y) / 2;
		if (slid->old_sample.y > threshold_y && slid->new_sample.y < threshold_y) {
			step_cnt++;
		}
		break;
	}
	case MOST_ACTIVE_Z:
	{
		short threshold_z = (peak->oldmax.z + peak->oldmin.z) / 2;
		if (slid->old_sample.z > threshold_z && slid->new_sample.z < threshold_z) {
			step_cnt++;
		}
		break;
	}
	default:
		break;
	}
	return step_cnt;
}

uint16_t get_step(void) {

	for (num = 0;num < 4;num++) {

		read_mpu9250_accel(array_accel);

		axis_x = array_accel[0] / 164;
		axis_y = array_accel[1] / 164;
		axis_z = array_accel[2] / 164;

		cur_sample.x = axis_x;
		cur_sample.y = axis_y;
		cur_sample.z = axis_z;

		filter.info[num].x = cur_sample.x;
		filter.info[num].y = cur_sample.y;
		filter.info[num].z = cur_sample.z;
	}

	filter_calculate(&filter, &sample);	//均值滤波
	peak_update(&peak, &sample);		//动态old,new的max，min值更新
	slid_update(&slid, &sample);		//数据更新

	temp_step = detect_step(&peak, &slid);

	return temp_step;
}

void sync_local_step(uint16_t newstep) {
	step_cnt = newstep;
}

