// 
// 
// 

#include "ModePushTarget.h"
#include "OnboardHardware.h"
#include "ModesController.h"
//---------------------------------------------------------------------------

ModePushTarget::ModePushTarget()
{
}
//---------------------------------------------------------------------------

void ModePushTarget::OnEnterMode()
{
	Serial.println(" ModePushTarget::OnEnterMode");

	OnboardHardware::movementManager.ClearQueue();

	OnboardHardware::movementManager.SetNextAction(
		DIRECTION_FORWARD, VELOCITY_MAX_SPEED,
		DIRECTION_FORWARD, VELOCITY_MAX_SPEED,
		100000);
}
//---------------------------------------------------------------------------

void ModePushTarget::OnTick()
{
	if (OnboardHardware::sensorStatesController.HasChangedSensorValues())
	{
		if (OnboardHardware::sensorStatesController.IsChangedAndHasSpecificValue(&OnboardHardware::leftSensorTCRT5000, 1) == 1 ||
			OnboardHardware::sensorStatesController.IsChangedAndHasSpecificValue(&OnboardHardware::rightSensorTCRT5000, 1) == 1)
		{
			ModesController::SetCurrentMode(ModesController::borderRotationModePtr);
		}
	}
	else if (OnboardHardware::leftIRForwardSensor.IsSignaled() == 0 && OnboardHardware::rightIRForwardSensor.IsSignaled() == 0)
	{
		ModesController::SetCurrentMode(ModesController::searchForTargetModePtr);
	}
}
//---------------------------------------------------------------------------