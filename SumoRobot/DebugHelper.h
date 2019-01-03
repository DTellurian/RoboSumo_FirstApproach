// DebugHelper.h

#ifndef _DEBUGHELPER_h
#define _DEBUGHELPER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class DebugHelper
{
protected:


public:
	static void DelayForSeconds(uint8_t secondsCount);

private:
	DebugHelper();
	DebugHelper(DebugHelper&);
};

#endif

