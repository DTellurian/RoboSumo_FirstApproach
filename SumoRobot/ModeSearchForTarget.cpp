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

void ModeSearchForTarget::OnTick()
{
	if (OnboardHardware::sensorStatesController.HasChangedSensorValues())
	{
		if (OnboardHardware::sensorStatesController.IsChangedAndHasSpecificValue(&OnboardHardware::leftSensorTCRT5000, 1) == 1 ||
			OnboardHardware::sensorStatesController.IsChangedAndHasSpecificValue(&OnboardHardware::rightSensorTCRT5000, 1) == 1)
		{
			ModesController::SetCurrentMode(ModesController::borderRotationModePtr);
		}


		//uint8_t newSensorState = 0;

		//if (OnboardHardware::sensorStatesController.IsChanged(&OnboardHardware::leftIRForwardSensor, newSensorState) == 1)
		//{
		//	Serial.print(millis());
		//	Serial.print("Left IR sensor change state. New state");
		//	Serial.println(newSensorState);
		//}

		//if (OnboardHardware::sensorStatesController.IsChanged(&OnboardHardware::rightIRForwardSensor, newSensorState) == 1)
		//{
		//	Serial.print(millis());
		//	Serial.print("Right IR sensor change state. New state");
		//	Serial.println(newSensorState);
		//}		
	}
}
//---------------------------------------------------------------------------

void ModeSearchForTarget::OnEnterMode()
{
	OnboardHardware::movementManager.SetNextAction(
		DIRECTION_FORWARD, VELOCITY_CRUISER_SPEED,
		DIRECTION_FORWARD, VELOCITY_CRUISER_SPEED,
		100000);
}
//---------------------------------------------------------------------------