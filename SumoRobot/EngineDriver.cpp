
#include "EngineDriver.h"
//---------------------------------------------------------------------------

EngineDriver::EngineDriver(uint8_t enanble1Pin, uint8_t enanble2Pin, uint8_t pwmPin)
{
	_enanble1Pin = enanble1Pin;
	_enanble2Pin = enanble2Pin;
	_pwmPin = pwmPin;

	pinMode(_enanble1Pin, OUTPUT);
	pinMode(_enanble2Pin, OUTPUT);
	pinMode(_pwmPin, OUTPUT);

	Stop();
}
//---------------------------------------------------------------------------

void EngineDriver::SetMode(uint8_t direction, uint8_t velocity)
{
	analogWrite(_pwmPin, velocity);

	if (direction == DIRECTION_FORWARD)
	{
		digitalWrite(_enanble1Pin, HIGH);
		digitalWrite(_enanble2Pin, LOW);
	}
	else
	{
		digitalWrite(_enanble1Pin, LOW);
		digitalWrite(_enanble2Pin, HIGH);
	}	
}
//---------------------------------------------------------------------------

void EngineDriver::Stop()
{
	digitalWrite(_enanble1Pin, LOW);
	digitalWrite(_enanble2Pin, LOW);
}
//---------------------------------------------------------------------------