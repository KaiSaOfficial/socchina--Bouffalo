#ifndef __I2C_BUS_H__
#define __I2C_BUS_H__

#include "hal_i2c.h"
#include "bflb_platform.h"

void i2c_bus_init(void);

void i2c_Master_write(uint8_t SlaveAddress, uint8_t REG_data);
uint8_t i2c_Master_read(uint8_t SlaveAddress);
void i2c_Mem_write8bit(uint8_t SlaveAddress, uint8_t REG_Address, uint8_t REG_data);
uint8_t i2c_Mem_read8bit(uint8_t SlaveAddress, uint8_t REG_Address);
void i2c_Mem_write(uint8_t SlaveAddress, uint8_t REG_Address, uint8_t* REG_data, uint8_t len);
void i2c_Mem_read(uint8_t SlaveAddress, uint8_t REG_Address, uint8_t* REG_rec_data, uint8_t len);

#endif // !__I2C_BUS_H__
