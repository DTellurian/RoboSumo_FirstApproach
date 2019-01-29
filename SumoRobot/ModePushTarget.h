// ModePushTarget.h

#ifndef _MODEPUSHTARGET_h
#define _MODEPUSHTARGET_h
//---------------------------------------------------------------------------

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
//---------------------------------------------------------------------------

#include "IMode.h"
//---------------------------------------------------------------------------

class ModePushTarget : public IMode
{
protected:


public:
	ModePushTarget();

	virtual void OnTick();//From IMode
	virtual void OnEnterMode();//From IMode

private:
	ModePushTarget(ModePushTarget&);
};
//---------------------------------------------------------------------------
#endif

