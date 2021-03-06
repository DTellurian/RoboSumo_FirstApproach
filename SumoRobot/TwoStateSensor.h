// TwoStateSensor.h

#ifndef _TWOSTATESENSOR_h
#define _TWOSTATESENSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
//---------------------------------------------------------------------------

class TwoStateSensor
{
protected:
	TwoStateSensor();
	virtual void TrySetIsSignaled(uint8_t newValue);


public:
	virtual void OnTick() {};
	uint8_t IsSignaled();


private:
	TwoStateSensor(TwoStateSensor&);
	uint8_t _isSignaled = 0;
};
//---------------------------------------------------------------------------
#endif

