// 
// 
// 

#include "SensorTCRT5000.h"
//---------------------------------------------------------------------------

SensorTCRT5000::SensorTCRT5000(uint8_t sensorPin, int lowLimit, int hightLimit)
{
	_sensorPin = sensorPin;
	_lowLimit = lowLimit;
	_hightLimit = hightLimit;
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
		_hightOccasionsCount = 0;

		if (_lowOccasionsCount < MIN_OCCASION_COUNT)
			_lowOccasionsCount++;

		if (_lowOccasionsCount == MIN_OCCASION_COUNT)
			TrySetIsSignaled(1);
	}

	if (currentValue > _hightLimit)
	{
		_lowOccasionsCount = 0;

		if (_hightOccasionsCount < MIN_OCCASION_COUNT)
			_hightOccasionsCount++;

		if (_hightOccasionsCount == MIN_OCCASION_COUNT)
			TrySetIsSignaled(0);
	}

	return currentValue;
}
//---------------------------------------------------------------------------

