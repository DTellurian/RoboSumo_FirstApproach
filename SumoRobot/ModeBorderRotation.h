// ModeBorderRotation.h

#ifndef _MODEBORDERROTATION_h
#define _MODEBORDERROTATION_h
//---------------------------------------------------------------------------

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
//---------------------------------------------------------------------------

#include "IMode.h"
//---------------------------------------------------------------------------

class ModeBorderRotation : public IMode
{
protected:


public:
	ModeBorderRotation();

	virtual void OnTick();//From IMode
	virtual void OnEnterMode();//From IMode
private:
	ModeBorderRotation(ModeBorderRotation&);
};
//---------------------------------------------------------------------------
#endif

