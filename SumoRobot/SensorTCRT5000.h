// SensorTCRT5000.h

#ifndef _SENSORTCRT5000_h
#define _SENSORTCRT5000_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#define MIN_OCCASION_COUNT 1

#include "TwoStateSensorWithDelay.h"

class SensorTCRT5000 : public TwoStateSensorWithDelay
{
private:
	SensorTCRT5000();
	
	uint8_t _sensorPin = 0;

	uint8_t _lowOccasionsCount = 0;
	uint8_t _hightOccasionsCount = 0;

	int _lowLimit = 0;
	int _hightLimit = 0;

protected:


public:
	SensorTCRT5000(uint8_t sensorPin, int lowLimit, int hightLimit);

	virtual void OnTick();
	int Measure();	
};

//extern SensorTCRT5000Class SensorTCRT5000;

#endif

