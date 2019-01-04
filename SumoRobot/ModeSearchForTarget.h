// ModeSearchForTarget.h

#ifndef _MODESEARCHFORTARGET_h
#define _MODESEARCHFORTARGET_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
//---------------------------------------------------------------------------

class ModeSearchForTarget
{
protected:


public:
	ModeSearchForTarget();

	void OnTick();

private:
	ModeSearchForTarget(ModeSearchForTarget&);
};
//---------------------------------------------------------------------------
#endif

