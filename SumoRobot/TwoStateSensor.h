// TwoStateSensor.h

#ifndef _TWOSTATESENSOR_h
#define _TWOSTATESENSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class TwoStateSensor
{
protected:
	TwoStateSensor();

public:
	virtual void OnTick() {};
	virtual uint8_t IsSignaled() { };
};

#endif

