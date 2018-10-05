// EnginesDriver.h

#ifndef _ENGINESDRIVER_h
#define _ENGINESDRIVER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class EnginesDriverClass
{
 protected:


 public:
	void init();
};

extern EnginesDriverClass EnginesDriver;

#endif

