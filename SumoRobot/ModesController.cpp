// 
// 
// 

#include "ModesController.h"
#include "ModeSearchForTarget.h"
#include "ModeBorderRotation.h"
//---------------------------------------------------------------------------

IMode* ModesController::currentModePtr = 0;

ModeSearchForTarget modeSearchForTarget;
IMode* ModesController::searchForTargetModePtr = &modeSearchForTarget;

ModeBorderRotation modeBorderRotation;
IMode* ModesController::borderRotationModePtr = &modeBorderRotation;
//---------------------------------------------------------------------------

void ModesController::SetCurrentMode(IMode* targetModePtr)
{
	ModesController::currentModePtr = targetModePtr;

	targetModePtr->OnEnterMode();
}
//---------------------------------------------------------------------------

void ModesController::OnTick()
{
	currentModePtr->OnTick();
}
//---------------------------------------------------------------------------