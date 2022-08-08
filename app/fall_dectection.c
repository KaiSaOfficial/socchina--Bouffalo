#include "mpu9250.h"
#include "i2c_bus.h"
#include "stdbool.h"
#include "fall_dectection.h"

#include "math.h"

//  const int MPU_addr = 0x68; // I2C address of the MPU-6050
int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ;
float ax = 0, ay = 0, az = 0, gx = 0, gy = 0, gz = 0;
bool fall = false; //stores if a fall has occurred
uint8_t trigger1 = false; //stores if first trigger (lower threshold) has occurred
uint8_t trigger2 = false; //stores if second trigger (upper threshold) has occurred
uint8_t trigger3 = false; //stores if third trigger (orientation change) has occurred
uint16_t trigger1count = 0; //stores the counts past since trigger 1 was set true
uint16_t trigger2count = 0; //stores the counts past since trigger 2 was set true
uint16_t trigger3count = 0; //stores the counts past since trigger 3 was set true
int angleChange = 0;

uint16_t dat_accel[3] = { 0 };
uint16_t dat_gyro[3] = { 0 };

void fall_dectection(uint8_t* state) {
  *state = false;

  read_mpu9250_accel(dat_accel);//获取加速度
  AcX = dat_accel[0];
  AcY = dat_accel[1];
  AcZ = dat_accel[2];

  read_mpu9250_gyro(dat_gyro);//获取角速度
  GyX = dat_gyro[0];
  GyY = dat_gyro[1];
  GyZ = dat_gyro[2];

  ax = (AcX - 2050) / 16384.00;
  ay = (AcY - 77) / 16384.00;
  az = (AcZ - 1947) / 16384.00;
  gx = (GyX + 270) / 131.07;
  gy = (GyY - 351) / 131.07;
  gz = (GyZ + 136) / 131.07;

  // calculating Amplitute vactor for 3 axis
  float Raw_Amp = pow(pow(ax, 2) + pow(ay, 2) + pow(az, 2), 0.5);
  int Amp = Raw_Amp * 10;  // Mulitiplied by 10 bcz values are between 0 to 1

  if (Amp <= 4 && trigger2 == false) { //if AM breaks lower threshold (0.4g)     
    trigger1 = true;

  }
  if (trigger1 == true) {
    trigger1count++;
    if (Amp >= 8) { //if AM breaks upper threshold (3g)
      trigger2 = true;

      trigger1 = false;
      trigger1count = 0;
    }
  }
  if (trigger2 == true) {
    trigger2count++;
    angleChange = pow(pow(gx, 2) + pow(gy, 2) + pow(gz, 2), 0.5); //Serial.println(angleChange);
    if (angleChange >= 30 && angleChange <= 400) { //if orientation changes by between 80-100 degrees       
      trigger3 = true;
      trigger2 = false;
      trigger2count = 0;

    }
  }
  if (trigger3 == true) {
    trigger3count++;
    if (trigger3count >= 10) {
      angleChange = pow(pow(gx, 2) + pow(gy, 2) + pow(gz, 2), 0.5);

      if ((angleChange >= 0) && (angleChange <= 10)) { //if orientation changes remains between 0-10 degrees         
        fall = true;
        trigger3 = false;
        trigger3count = 0;

      } else { //user regained normal orientation         
        trigger3 = false;
        trigger3count = 0;

      }
    }
  }
  if (fall == true) { //in event of a fall detection         
    *state = true;
    fall = false;
  }
  if (trigger2count >= 6) { //allow 0.5s for orientation change
    trigger2 = false;
    trigger2count = 0;

  }
  if (trigger1count >= 6) { //allow 0.5s for AM to break upper threshold
    trigger1 = false;
    trigger1count = 0;

  }
}
