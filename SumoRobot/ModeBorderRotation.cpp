// 
// 
// 

#include "ModeBorderRotation.h"
#include "OnboardHardware.h"
#include "MovementHelper.h"
#include "ModesController.h"
//---------------------------------------------------------------------------

ModeBorderRotation::ModeBorderRotation()
{
}
//---------------------------------------------------------------------------

void ModeBorderRotation::OnTick()
{
	if (OnboardHardware::sensorStatesController.HasChangedSensorValues())
	{
		if (OnboardHardware::sensorStatesController.IsChangedAndHasSpecificValue(&OnboardHardware::leftSensorTCRT5000, 1) == 1 ||
			OnboardHardware::sensorStatesController.IsChangedAndHasSpecificValue(&OnboardHardware::rightSensorTCRT5000, 1) == 1)
		{
			SetActions();
		}
	}

	if (OnboardHardware::movementManager.AnyMovementExecuted() == 0)
	{
		ModesController::SetCurrentMode(ModesController::searchForTargetModePtr);
	}
}
//---------------------------------------------------------------------------

void ModeBorderRotation::OnEnterMode()
{
	//Serial.println("ModeBorderRotation::OnEnterMode");
	SetActions();
}
//---------------------------------------------------------------------------

void ModeBorderRotation::SetActions()
{
	//Serial.println("SetActions()");
	

	uint8_t leftSensorValue = 0;
	uint8_t rightSensorValue = 0;

	OnboardHardware::sensorStatesController.IsChanged(&OnboardHardware::leftSensorTCRT5000, leftSensorValue);
	OnboardHardware::sensorStatesController.IsChanged(&OnboardHardware::rightSensorTCRT5000, rightSensorValue);

	OnboardHardware::movementManager.ClearQueue();

	OnboardHardware::movementManager.SetNextAction(
		DIRECTION_BACK, VELOCITY_CRUISER_SPEED,
		DIRECTION_BACK, VELOCITY_CRUISER_SPEED,
		100000, 2, 2);

	if (leftSensorValue == 1 && rightSensorValue == 1)
	{
		//Serial.println("leftSensorValue == 1 && rightSensorValue == 1");
		MovementHelper::AddCenterAxisRotation(ROTATION_DIRECTION_LEFT, ROTATION_DEGREES_180, VELOCITY_CRUISER_SPEED, 10000);
	}
	else if (leftSensorValue == 1 && rightSensorValue == 0)
	{
		//Serial.println("leftSensorValue == 1 && rightSensorValue == 0");
		MovementHelper::AddCenterAxisRotation(ROTATION_DIRECTION_RIGHT, ROTATION_DEGREES_135, VELOCITY_CRUISER_SPEED, 10000);
	}
	else if (leftSensorValue == 0 && rightSensorValue == 1)
	{
		//Serial.println("leftSensorValue == 0 && rightSensorValue == 1");
		MovementHelper::AddCenterAxisRotation(ROTATION_DIRECTION_LEFT, ROTATION_DEGREES_135, VELOCITY_CRUISER_SPEED, 10000);
	}
}
//---------------------------------------------------------------------------