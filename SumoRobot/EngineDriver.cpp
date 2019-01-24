
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
	digitalWrite(_enanble1Pin, direction);
	digitalWrite(_enanble2Pin, direction ^ 0x1);
	analogWrite(_pwmPin, velocity);
}
//---------------------------------------------------------------------------

void EngineDriver::Stop()
{
	digitalWrite(_enanble1Pin, LOW);
	digitalWrite(_enanble2Pin, LOW);
}
//---------------------------------------------------------------------------