// 
// 
// 

#include "TwoStateSensorWithDelay.h"
//---------------------------------------------------------------------------

TwoStateSensorWithDelay::TwoStateSensorWithDelay()
{


}
//---------------------------------------------------------------------------

void TwoStateSensorWithDelay::TrySetIsSignaled(uint8_t newValue)
{
	if (_delayEndTimeMs != 0)
	{
		if (_delayEndTimeMs > millis())
		{
			_delayEndTimeMs = 0;
			TwoStateSensor::TrySetIsSignaled(newValue);
		}
	}
}
//---------------------------------------------------------------------------

void TwoStateSensorWithDelay::DisableForPeriod(uint32_t delayMs)
{
	_delayEndTimeMs = millis() + delayMs;
}
//---------------------------------------------------------------------------