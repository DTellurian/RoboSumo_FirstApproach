// LedDriver.h

#ifndef _LEDDRIVER_h
#define _LEDDRIVER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class LedDriver
{
public:
	void TirnOn();
	void TirnOff();
};

#endif

