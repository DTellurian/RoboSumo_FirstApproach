// ModesController.h

#ifndef _MODESCONTROLLER_h
#define _MODESCONTROLLER_h
//---------------------------------------------------------------------------

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
//---------------------------------------------------------------------------

#include "IMode.h"

class ModesController
{
protected:
	static IMode *currentModePtr;

public:
	static IMode *searchForTargetModePtr;
	static IMode *borderRotationModePtr;

	static void SetCurrentMode(IMode* targetModePtr);

	static void OnTick();
private:
	ModesController();
	ModesController(ModesController&);
};
//---------------------------------------------------------------------------
#endif

