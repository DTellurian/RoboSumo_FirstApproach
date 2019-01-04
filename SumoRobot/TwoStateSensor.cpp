// 
// 
// 

#include "TwoStateSensor.h"
//---------------------------------------------------------------------------

TwoStateSensor::TwoStateSensor()
{
}
//---------------------------------------------------------------------------

void TwoStateSensor::TrySetIsSignaled(uint8_t newValue)
{
	_isSignaled = newValue;
}
//---------------------------------------------------------------------------

uint8_t TwoStateSensor::IsSignaled()
{
	return _isSignaled;
}
//---------------------------------------------------------------------------