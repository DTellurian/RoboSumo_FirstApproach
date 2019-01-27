// ModeSearchForTarget.h

#ifndef _MODESEARCHFORTARGET_h
#define _MODESEARCHFORTARGET_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
//---------------------------------------------------------------------------

#include "IMode.h"
//---------------------------------------------------------------------------

class ModeSearchForTarget : public IMode
{
protected:


public:
	ModeSearchForTarget();

	virtual void OnTick();//From IMode
	virtual void OnEnterMode();//From IMode

private:
	ModeSearchForTarget(ModeSearchForTarget&);
};
//---------------------------------------------------------------------------
#endif

