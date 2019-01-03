// 
// 
// 

#include "DigitalInputSensor.h"
//---------------------------------------------------------------------------

DigitalInputSensor::DigitalInputSensor(uint8_t pin, uint8_t signaledDigitalValue)
{
	_pin = pin;
	_signaledDigitalValue = signaledDigitalValue;
	pinMode(pin, INPUT);
}
//---------------------------------------------------------------------------

void DigitalInputSensor::OnTick()
{
	_isSignaled = digitalRead(_pin) == _signaledDigitalValue;	
}
//---------------------------------------------------------------------------

uint8_t DigitalInputSensor::IsSignaled()
{
	return _isSignaled;
}
//---------------------------------------------------------------------------