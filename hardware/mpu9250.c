#include "mpu9250.h"
#include "i2c_bus.h"

//using I2c interface

// 定义MPU9250内部地址
//****************************************	
#define MPU9250_RA_INT_ENABLE       0x38
#define MPU9250_RA_PWR_MGMT_1       0x6B
#define MPU9250_RA_GYRO_CONFIG      0x1B	    //陀螺仪自检及测量范围，典型值：0x18(不自检，2000deg/s)
#define MPU9250_RA_ACCEL_CONFIG     0x1C	    //加速计自检、测量范围及高通滤波频率，典型值：0x01(不自检，2G，5Hz)
#define MPU9250_RA_CONFIG           0x1A	    //低通滤波频率，典型值：0x06(5Hz)
#define MPU9250_RA_SMPLRT_DIV       0x19	    //陀螺仪采样率，典型值：0x07(125Hz)
#define MPU9250_RA_INT_PIN_CFG      0x37

#define	WHO_AM_I					0x75	    //IIC地址寄存器(默认数值0x71，只读)
#define	MPU9250_ADDRESS   			(0xD0 >> 1)	//陀螺从机地址

#define MAG_ADDRESS    (0x18 >> 1)   //磁场地址

//设置低通滤波
#define MPU9250_DLPF_BW_256         0x00
#define MPU9250_DLPF_BW_188         0x01
#define MPU9250_DLPF_BW_98          0x02
#define MPU9250_DLPF_BW_42          0x03
#define MPU9250_DLPF_BW_20          0x04
#define MPU9250_DLPF_BW_10          0x05
#define MPU9250_DLPF_BW_5           0x06

enum ACCEL_ADD {
    ACCEL_XOUT_H = 0x3B,
    ACCEL_XOUT_L = 0x3C,
    ACCEL_YOUT_H = 0x3D,
    ACCEL_YOUT_L = 0x3E,
    ACCEL_ZOUT_H = 0x3F,
    ACCEL_ZOUT_L = 0x40
};

enum TEMP_ADD {
    TEMP_OUT_H = 0x41,
    TEMP_OUT_L = 0x42
};

enum GYRO_ADD {
    GYRO_XOUT_H = 0x43,
    GYRO_XOUT_L = 0x44,
    GYRO_YOUT_H = 0x45,
    GYRO_YOUT_L = 0x46,
    GYRO_ZOUT_H = 0x47,
    GYRO_ZOUT_L = 0x48
};

enum MAG_ADD {
    MAG_XOUT_L = 0x03,
    MAG_XOUT_H = 0x04,
    MAG_YOUT_L = 0x05,
    MAG_YOUT_H = 0x06,
    MAG_ZOUT_L = 0x07,
    MAG_ZOUT_H = 0x08,
};


uint8_t BUF[6];             //接收数据缓存区
uint8_t TEMPBUF[2];
//short mpu9250_data[4];		 //X,Y,Z轴,温度

void mpu9250_init(void) {
    if (0x71 != i2c_Mem_read8bit(MPU9250_ADDRESS, WHO_AM_I)) {
        return;
    }

    i2c_Mem_write8bit(MPU9250_ADDRESS, MPU9250_RA_PWR_MGMT_1, 0x80); //复位MPU9250
    bflb_platform_delay_ms(100);
    i2c_Mem_write8bit(MPU9250_ADDRESS, MPU9250_RA_PWR_MGMT_1, 0x00); //唤醒MPU9250，并选择陀螺仪x轴PLL为时钟源 (MPU9250_RA_PWR_MGMT_1, 0x01)
    i2c_Mem_write8bit(MPU9250_ADDRESS, MPU9250_RA_INT_ENABLE, 0x00); //禁止中断
    i2c_Mem_write8bit(MPU9250_ADDRESS, MPU9250_RA_GYRO_CONFIG, 0x18); //陀螺仪满量程+-2000度/秒 (最低分辨率 = 2^15/2000 = 16.4LSB/度/秒)
    i2c_Mem_write8bit(MPU9250_ADDRESS, MPU9250_RA_ACCEL_CONFIG, 0x08); //加速度满量程+-4g   (最低分辨率 = 2^15/4g = 8196LSB/g )
    i2c_Mem_write8bit(MPU9250_ADDRESS, MPU9250_RA_CONFIG, MPU9250_DLPF_BW_20);//设置陀螺的输出为1kHZ,DLPF=20Hz
    i2c_Mem_write8bit(MPU9250_ADDRESS, MPU9250_RA_SMPLRT_DIV, 0x00);  //采样分频 (采样频率 = 陀螺仪输出频率 / (1+DIV)，采样频率1000hz)
    i2c_Mem_write8bit(MPU9250_ADDRESS, MPU9250_RA_INT_PIN_CFG, 0x02); //MPU 可直接访问MPU9250辅助I2C
}

//读取加速度
void read_mpu9250_accel(uint16_t dat []) {
    //读取计算X轴数据
    BUF[0] = i2c_Mem_read8bit(MPU9250_ADDRESS, ACCEL_XOUT_L);
    BUF[1] = i2c_Mem_read8bit(MPU9250_ADDRESS, ACCEL_XOUT_H);
    dat[0] = (BUF[1] << 8) | BUF[0];

    //读取计算Y轴数据
    BUF[2] = i2c_Mem_read8bit(MPU9250_ADDRESS, ACCEL_YOUT_L);
    BUF[3] = i2c_Mem_read8bit(MPU9250_ADDRESS, ACCEL_YOUT_H);
    dat[1] = (BUF[3] << 8) | BUF[2];

    //读取计算Z轴数据
    BUF[4] = i2c_Mem_read8bit(MPU9250_ADDRESS, ACCEL_ZOUT_L);
    BUF[5] = i2c_Mem_read8bit(MPU9250_ADDRESS, ACCEL_ZOUT_H);
    dat[2] = (uint16_t)(BUF[5] << 8) | BUF[4];
}

//读取陀螺
void read_mpu9250_gyro(uint16_t dat []) {
    //读取计算X轴数据
    BUF[0] = i2c_Mem_read8bit(MPU9250_ADDRESS, GYRO_XOUT_L);
    BUF[1] = i2c_Mem_read8bit(MPU9250_ADDRESS, GYRO_XOUT_H);
    dat[0] = (BUF[1] << 8) | BUF[0];
    //    dat[0] /= 16.4;

        //读取计算Y轴数据
    BUF[2] = i2c_Mem_read8bit(MPU9250_ADDRESS, GYRO_YOUT_L);
    BUF[3] = i2c_Mem_read8bit(MPU9250_ADDRESS, GYRO_YOUT_H);
    dat[1] = (BUF[3] << 8) | BUF[2];
    //    dat[1] /= 16.4;

        //读取计算Z轴数据
    BUF[4] = i2c_Mem_read8bit(MPU9250_ADDRESS, GYRO_ZOUT_L);
    BUF[5] = i2c_Mem_read8bit(MPU9250_ADDRESS, GYRO_ZOUT_H);
    dat[2] = (BUF[5] << 8) | BUF[4];
    //    dat[2] /= 16.4;

}


//读取磁场
void read_mpu9250_mag(uint16_t dat []) {
    i2c_Mem_write8bit(MPU9250_ADDRESS, 0x37, 0x02);//turn on Bypass Mode
    bflb_platform_delay_ms(10);
    i2c_Mem_write8bit(MAG_ADDRESS, 0x0A, 0x01);
    bflb_platform_delay_ms(10);

    BUF[0] = i2c_Mem_read8bit(MAG_ADDRESS, MAG_XOUT_L);
    BUF[1] = i2c_Mem_read8bit(MAG_ADDRESS, MAG_XOUT_H);
    dat[0] = (BUF[1] << 8) | BUF[0];

    BUF[2] = i2c_Mem_read8bit(MAG_ADDRESS, MAG_YOUT_L);
    BUF[3] = i2c_Mem_read8bit(MAG_ADDRESS, MAG_YOUT_H);
    dat[1] = (BUF[3] << 8) | BUF[2];
    //读取计算Y轴数据

    BUF[4] = i2c_Mem_read8bit(MAG_ADDRESS, MAG_ZOUT_L);
    BUF[5] = i2c_Mem_read8bit(MAG_ADDRESS, MAG_ZOUT_H);
    dat[2] = (BUF[5] << 8) | BUF[4];
    //读取计算Z轴数据
}