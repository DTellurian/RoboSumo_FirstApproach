// 
// 
// 

#include "SensorTCRT5000.h"
//---------------------------------------------------------------------------

SensorTCRT5000::SensorTCRT5000(uint8_t sensorPin, int lowLimit)
{
	_sensorPin = sensorPin;
	_lowLimit = lowLimit;
}
//---------------------------------------------------------------------------

void SensorTCRT5000::OnTick()
{
	Measure();
}
//---------------------------------------------------------------------------

int SensorTCRT5000::Measure()
{
	int currentValue = analogRead(_sensorPin);

	if (currentValue < _lowLimit)
	{
		if (_occasionsCount < MIN_OCCASION_COUNT)
			_occasionsCount++;
	}
	else
	{
		_occasionsCount = 0;
		_isReset = 0;
	}

	return currentValue;
}
//---------------------------------------------------------------------------

uint8_t SensorTCRT5000::IsSignaled()
{
	return _occasionsCount >= MIN_OCCASION_COUNT && _isReset == 0;
}
//---------------------------------------------------------------------------

void SensorTCRT5000::Reset()
{
	_isReset = 1;
}
//---------------------------------------------------------------------------

