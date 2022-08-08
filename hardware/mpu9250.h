#ifndef __MPU9250__
#define __MPU9250__

#include "bflb_platform.h"

void mpu9250_init(void);

void read_mpu9250_accel(uint16_t* dat);
void read_mpu9250_gyro(uint16_t* dat);
void read_mpu9250_mag(uint16_t* dat);

#endif // !__MPU9250__
