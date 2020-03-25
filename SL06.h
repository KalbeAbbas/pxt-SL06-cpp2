
#pragma once
#ifdef CODAL_I2C
#include "I2C.h"
#include "Pin.h"
#endif
#include "inttypes.h"
#include "pxt.h"

#ifndef SL06_h
#define SL06_h



#define APDS9960_ADDRESS 0x39

class SL06
{
	public:
		SL06(uint8_t addr);
		uint8_t* readBlockData(uint8_t reg, uint8_t length, uint8_t* buf);
		int i2cread(uint8_t reg, uint8_t *data, int len);
		uint8_t* retNumber();
		uint8_t* data;
		
	private:
		uint16_t i2cAddr;
};

#endif