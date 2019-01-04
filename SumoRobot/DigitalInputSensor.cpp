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
	uint8_t newIsSignaled = digitalRead(_pin) == _signaledDigitalValue;

	TrySetIsSignaled(newIsSignaled);
}
//---------------------------------------------------------------------------