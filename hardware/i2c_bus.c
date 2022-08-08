#include "i2c_bus.h"

struct device* i2c;

void i2c_bus_init(void) {
    i2c_register(I2C0_INDEX, "i2c");
    i2c = device_find("i2c");

    if (i2c) {
        device_open(i2c, 0);
    }
}

void i2c_Master_write(uint8_t SlaveAddress, uint8_t REG_data) {
    i2c_msg_t msg;

    msg.slaveaddr = SlaveAddress;
    msg.subaddr = 0;
    msg.buf = &REG_data;
    msg.flags = SUB_ADDR_0BYTE | I2C_WR;
    msg.len = 1;

    i2c_transfer(i2c, &msg, 1);
}

uint8_t i2c_Master_read(uint8_t SlaveAddress) {
    i2c_msg_t msg;
    uint8_t rec = 0;

    msg.slaveaddr = SlaveAddress;
    msg.subaddr = 0;
    msg.buf = &rec;
    msg.flags = SUB_ADDR_0BYTE | I2C_RD;
    msg.len = 1;

    i2c_transfer(i2c, &msg, 1);
	
	return rec;
}

void i2c_Mem_write8bit(uint8_t SlaveAddress, uint8_t REG_Address, uint8_t REG_data) {
    i2c_msg_t msg;

    msg.slaveaddr = SlaveAddress;
    msg.subaddr = REG_Address;
    msg.buf = &REG_data;
    msg.flags = SUB_ADDR_1BYTE | I2C_WR;
    msg.len = 1;

    i2c_transfer(i2c, &msg, 1);
}

uint8_t i2c_Mem_read8bit(uint8_t SlaveAddress, uint8_t REG_Address) {
    uint8_t rec = 0;
    i2c_msg_t msg;

    msg.slaveaddr = SlaveAddress;
    msg.subaddr = REG_Address;
    msg.buf = &rec;
    msg.flags = SUB_ADDR_1BYTE | I2C_RD;
    msg.len = 1;

    i2c_transfer(i2c, &msg, 1);

    return rec;
}

void i2c_Mem_write(uint8_t SlaveAddress, uint8_t REG_Address, uint8_t* REG_data, uint8_t len) {
    i2c_msg_t msg;

    msg.slaveaddr = SlaveAddress;
    msg.subaddr = REG_Address;
    msg.buf = REG_data;
    msg.flags = SUB_ADDR_1BYTE | I2C_WR;
    msg.len = len;

    i2c_transfer(i2c, &msg, 1);
}

void i2c_Mem_read(uint8_t SlaveAddress, uint8_t REG_Address, uint8_t* REG_rec_data, uint8_t len) {
    i2c_msg_t msg;

    msg.slaveaddr = SlaveAddress;
    msg.subaddr = REG_Address;
    msg.buf = REG_rec_data;
    msg.flags = SUB_ADDR_1BYTE | I2C_RD;
    msg.len = len;

    i2c_transfer(i2c, &msg, 1);
}