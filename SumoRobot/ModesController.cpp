// 
// 
// 

#include "ModesController.h"
#include "ModeSearchForTarget.h"
#include "ModeBorderRotation.h"
#include "ModePushTarget.h"
//---------------------------------------------------------------------------

IMode* ModesController::currentModePtr = 0;

ModeSearchForTarget modeSearchForTarget;
IMode* ModesController::searchForTargetModePtr = &modeSearchForTarget;

ModeBorderRotation modeBorderRotation;
IMode* ModesController::borderRotationModePtr = &modeBorderRotation;

ModePushTarget modePushTarget;
IMode *ModesController::pushTargetPtr = &modePushTarget;
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