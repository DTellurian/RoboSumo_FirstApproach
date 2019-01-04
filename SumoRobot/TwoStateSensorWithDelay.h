// TwoStateSensorWithDelay.h

#ifndef _TWOSTATESENSORWITHDELAY_h
#define _TWOSTATESENSORWITHDELAY_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
//---------------------------------------------------------------------------

#include "TwoStateSensor.h"

class TwoStateSensorWithDelay : public TwoStateSensor
{
protected:
	TwoStateSensorWithDelay();
	virtual void TrySetIsSignaled(uint8_t newValue);

public:
	void DisableForPeriod(uint32_t delayMs);

private:
	TwoStateSensorWithDelay(TwoStateSensorWithDelay&);

	uint32_t _delayEndTimeMs = 0;	
};
//---------------------------------------------------------------------------
#endif

