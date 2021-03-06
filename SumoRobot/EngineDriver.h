// EngineDriver.h

#ifndef _ENGINEDRIVER_h
#define _ENGINEDRIVER_h
//---------------------------------------------------------------------------

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
//---------------------------------------------------------------------------

#define DIRECTION_FORWARD 0x1
#define DIRECTION_BACK  0x0

//140
#define VELOCITY_VERY_LOW_SPEED  0x8C

//220
#define VELOCITY_LOW_SPEED  0xDC

#define VELOCITY_MAX_SPEED  0xFF

//220
#define VELOCITY_CRUISER_SPEED  0xDC
//#define VELOCITY_CRUISER_SPEED  140
//---------------------------------------------------------------------------

class EngineDriver
{
private:
	EngineDriver();
	EngineDriver(EngineDriver&);

protected:
	uint8_t _enanble1Pin;
	uint8_t _enanble2Pin;

	uint8_t _pwmPin;

public:
	EngineDriver(uint8_t enanble1Pin, uint8_t enanble2Pin, uint8_t pwmPin);

	void SetMode(uint8_t direction, uint8_t velocity);
	void Stop();
};
//---------------------------------------------------------------------------
#endif

