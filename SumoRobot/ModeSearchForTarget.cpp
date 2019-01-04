// 
// 
// 

#include "ModeSearchForTarget.h"
#include "OnboardHardware.h"
//---------------------------------------------------------------------------

ModeSearchForTarget::ModeSearchForTarget()
{


}
//---------------------------------------------------------------------------

void ModeSearchForTarget::OnTick()
{
	if (OnboardHardware::sensorStatesController.HasChangedSensorValues())
	{
		uint8_t leftSensorTCRT5000NewValue = 0;
		uint8_t leftSensorTCRT5000IsChanged = 0;

		uint8_t rightSensorTCRT5000NewValue = 0;
		uint8_t rightSensorTCRT5000IsChanged = 0;

		leftSensorTCRT5000IsChanged = OnboardHardware::sensorStatesController.IsChanged(&OnboardHardware::leftSensorTCRT5000, leftSensorTCRT5000NewValue) == 1;

		if (leftSensorTCRT5000IsChanged == 1)
		{
			Serial.print(millis());
			Serial.print("Left sensor change state. New state");
			Serial.println(leftSensorTCRT5000NewValue);

			OnboardHardware::leftSensorTCRT5000.DisableForPeriod(100);
		}

		rightSensorTCRT5000IsChanged = OnboardHardware::sensorStatesController.IsChanged(&OnboardHardware::rightSensorTCRT5000, rightSensorTCRT5000NewValue) == 1;

		if (rightSensorTCRT5000IsChanged == 1)
		{
			Serial.print(millis());
			Serial.print("Right sensor change state. New state");
			Serial.println(rightSensorTCRT5000NewValue);

			OnboardHardware::rightSensorTCRT5000.DisableForPeriod(100);
		}

		if (leftSensorTCRT5000IsChanged == 1 || rightSensorTCRT5000IsChanged == 1)
		{
			if (leftSensorTCRT5000NewValue == 1 || rightSensorTCRT5000NewValue == 1)
			{
				OnboardHardware::movementManager.ClearQueue();

				OnboardHardware::movementManager.SetNextAction(
					DIRECTION_BACK, VELOCITY_CRUISER_SPEED,
					DIRECTION_BACK, VELOCITY_CRUISER_SPEED,
					100);

				OnboardHardware::movementManager.SetNextAction(
					DIRECTION_FORWARD, VELOCITY_CRUISER_SPEED,
					DIRECTION_BACK, VELOCITY_CRUISER_SPEED,
					400);

				OnboardHardware::movementManager.SetNextAction(
					DIRECTION_FORWARD, VELOCITY_CRUISER_SPEED,
					DIRECTION_FORWARD, VELOCITY_CRUISER_SPEED,
					100000);
			}
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