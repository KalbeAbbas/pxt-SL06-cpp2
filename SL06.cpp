#include "SL06.h"

using namespace pxt;

int SL06::i2cread(uint8_t reg, uint8_t *data, int len) {
#ifdef CODAL_I2C
    auto sda = LOOKUP_PIN(SDA);
    auto scl = LOOKUP_PIN(SCL);
    codal::I2C *i2c = pxt::getI2C(sda, scl);
#endif
    int i2c_error_status = 0;

#ifdef CODAL_I2C
    i2c_error_status = i2c->write((uint16_t)i2cAddr, (uint8_t *)&reg, 1, true);
#else
    i2c_error_status = uBit.i2c.write(i2cAddr, (const char *)&reg, 1, true);
#endif

#ifdef CODAL_I2C
    if (len == 1)
        return i2c_error_status = i2c->read((uint16_t)i2cAddr, (uint8_t *)&data, len, false);
    else
        return i2c_error_status = i2c->read((uint16_t)i2cAddr, (uint8_t *)&data, len, false);
#else
    return i2c_error_status = uBit.i2c.read(i2cAddr, (char *)data, len, false);
#endif
}


SL06::SL06(uint8_t addr)
{
	i2cAddr = addr << 1;
}

uint8_t* SL06::readBlockData(uint8_t reg, uint8_t len, uint8_t* buf)
{
	for(int i = 0; i < len; i++)
	{
		i2cread(reg, data, 1);
	}
	return data;
}

uint8_t* SL06::retNumber()
{
	uint8_t list_number[] = {1,2,3,4,5};
	return list_number;
}

uint8_t SL06::readId()
{
   i2cread(0x92 , &ID, 1);
   
   return ID;
}


namespace sl06
{
	static SL06* xSL06 = new SL06(APDS9960_ADDRESS);
	
	//%
	int readBytes(uint8_t reg, int len)
	{
		return (xSL06->i2cread(reg, xSL06->data, len));
	}
	
	//%
	uint8_t getID()
	{
		return (xSL06->readId());
	}
}