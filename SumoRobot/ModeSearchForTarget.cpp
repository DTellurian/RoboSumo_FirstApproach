// 
// 
// 

#include "ModeSearchForTarget.h"
#include "OnboardHardware.h"
#include "ModesController.h"
//---------------------------------------------------------------------------

ModeSearchForTarget::ModeSearchForTarget()
{


}
//---------------------------------------------------------------------------

void ModeSearchForTarget::OnEnterMode()
{
	//Serial.println("ModeSearchForTarget::OnEnterMode");

	OnboardHardware::movementManager.SetNextAction(
		DIRECTION_FORWARD, VELOCITY_CRUISER_SPEED,
		DIRECTION_FORWARD, VELOCITY_CRUISER_SPEED,
		100000);
}
//---------------------------------------------------------------------------

void ModeSearchForTarget::OnTick()
{
	if (OnboardHardware::sensorStatesController.HasChangedSensorValues())
	{
		if (OnboardHardware::sensorStatesController.IsChangedAndHasSpecificValue(&OnboardHardware::leftSensorTCRT5000, 1) == 1 ||
			OnboardHardware::sensorStatesController.IsChangedAndHasSpecificValue(&OnboardHardware::rightSensorTCRT5000, 1) == 1)
		{
			ModesController::SetCurrentMode(ModesController::borderRotationModePtr);
		}
		else if (OnboardHardware::sensorStatesController.IsChangedAndHasSpecificValue(&OnboardHardware::leftIRForwardSensor, 1) == 1 ||
			OnboardHardware::sensorStatesController.IsChangedAndHasSpecificValue(&OnboardHardware::rightIRForwardSensor, 1) == 1)
		{
			ModesController::SetCurrentMode(ModesController::pushTargetPtr);
		}
	}
}
//---------------------------------------------------------------------------