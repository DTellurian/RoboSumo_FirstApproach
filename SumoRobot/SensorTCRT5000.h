// SensorTCRT5000.h

#ifndef _SENSORTCRT5000_h
#define _SENSORTCRT5000_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#define MIN_OCCASION_COUNT 1

#include "TwoStateSensor.h"

class SensorTCRT5000 : public TwoStateSensor
{
private:
	SensorTCRT5000();

	uint8_t _isReset = 0;
	uint8_t _sensorPin = 0;
	uint8_t _occasionsCount = 0;
	int _lowLimit = 0;
protected:


public:
	SensorTCRT5000(uint8_t sensorPin, int lowLimit);

	virtual void OnTick();
	int Measure();
	virtual uint8_t IsSignaled();
	void Reset();
};

//extern SensorTCRT5000Class SensorTCRT5000;

#endif

