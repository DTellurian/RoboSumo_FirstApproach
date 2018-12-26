// EngineDriver.h

#ifndef _ENGINEDRIVER_h
#define _ENGINEDRIVER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#define DIRECTION_FORWARD 0x1
#define DIRECTION_BACK  0x0

#define VELOCITY_MAX_SPEED  0xFF
#define VELOCITY_MAX_SPEED  0xFF
#define VELOCITY_CRUISER_SPEED  0xDC

class EngineDriver
{
private:
	EngineDriver();

protected:
	uint8_t _enanble1Pin;
	uint8_t _enanble2Pin;

	uint8_t _pwmPin;

public:
	EngineDriver(uint8_t enanble1Pin, uint8_t enanble2Pin, uint8_t pwmPin);

	void SetMode(uint8_t direction, uint8_t velocity);
	void Stop();
};

//extern EnginesDriver EnginesDriverInstance;

#endif

