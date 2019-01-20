/*
 Name:		MovementManagerTest.ino
 Created:	09-Jan-19 22:40:06
 Author:	Dmytro.Mykhalchuk
*/

#include "ModeSearchForTarget.h"
#include "OnboardHardware.h"
#include "DebugHelper.h"
//---------------------------------------------------------------------------

// the setup function runs once when you press reset or power the board
void setup()
{
	pinMode(LED_BUILTIN, OUTPUT);

	Serial.begin(9600);
}
//---------------------------------------------------------------------------

// the loop function runs over and over again until power down or reset
void loop()
{
	//770 on white (Rotation sensor)
	//70 on dark (Rotation sensor)

	//615 on white (Line sensor)
	//70 on dark (Line sensor)

	//int currentValue = analogRead(18);
	//Serial.println(currentValue);

	//currentValue = analogRead(14);
	//Serial.println(currentValue);

	//delay(500);

	Serial.println("MovementManagerTest Launched!");
	Serial.println();

	DebugHelper::DelayForSeconds(2);
	OnboardHardware::Initialize();
	//ModeSearchForTarget modeSearchForTarget;

	//OnboardHardware::movementManager.SetNextAction(
	//	DIRECTION_FORWARD, VELOCITY_CRUISER_SPEED,
	//	DIRECTION_FORWARD, VELOCITY_CRUISER_SPEED,
	//	100000);

	while (true)
	{
		Serial.println(analogRead(18));
		Serial.println(analogRead(19));
		Serial.println();

		delay(500);
		continue;

		OnboardHardware::sensorStatesController.OnTick();
		OnboardHardware::wheelsSensorsStatesController.OnTick();
		//OnboardHardware::movementManager.OnTick();

		if (OnboardHardware::wheelsSensorsStatesController.HasChangedSensorValues())
		{
		/*	uint8_t rightWheelSensorTCRT5000NewValue = 0;
			uint8_t rightWheelSensorTCRT5000IsChanged = 0;

			rightWheelSensorTCRT5000IsChanged = OnboardHardware::wheelsSensorsStatesController.IsChanged(&OnboardHardware::rightWheelSensorTCRT5000, rightWheelSensorTCRT5000NewValue) == 1;

			if (rightWheelSensorTCRT5000IsChanged == 1)
			{
				Serial.print(millis());
				Serial.print("Right wheel sensor change state. New state");
				Serial.println(rightWheelSensorTCRT5000NewValue);
			}*/

			uint8_t leftWheelSensorTCRT5000NewValue = 0;
			uint8_t leftWheelSensorTCRT5000IsChanged = 0;

			leftWheelSensorTCRT5000IsChanged = OnboardHardware::wheelsSensorsStatesController.IsChanged(&OnboardHardware::leftWheelSensorTCRT5000, leftWheelSensorTCRT5000NewValue) == 1;

			if (leftWheelSensorTCRT5000IsChanged == 1)
			{
				Serial.print(millis());
				Serial.print("Left wheel sensor change state. New state");
				Serial.print(analogRead(19));
				Serial.println(leftWheelSensorTCRT5000NewValue);
			}

			OnboardHardware::wheelsSensorsStatesController.HandleAllSensors();
		}

		continue;

		//modeSearchForTarget.OnTick();
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

			uint8_t leftIRSensorNewValue = 0;
			uint8_t leftIRSensorIsChanged = 0;

			uint8_t rightIRSensorNewValue = 0;
			uint8_t rightIRSensorIsChanged = 0;

			leftIRSensorIsChanged = OnboardHardware::sensorStatesController.IsChanged(&OnboardHardware::leftIRForwardSensor, leftIRSensorNewValue) == 1;

			if (leftIRSensorIsChanged == 1)
			{
				if (leftIRSensorNewValue == 1)
				{
					OnboardHardware::movementManager.ClearQueue();
					OnboardHardware::movementManager.SetNextAction(
						DIRECTION_BACK, 0,
						DIRECTION_BACK, VELOCITY_MAX_SPEED,
						10000, 6, 6);

					//OnboardHardware::leftIRForwardSensor.
				}

				Serial.print(millis());
				Serial.print("Left IR sensor change state. New state");
				Serial.println(leftIRSensorNewValue);
			}

			rightIRSensorIsChanged = OnboardHardware::sensorStatesController.IsChanged(&OnboardHardware::rightIRForwardSensor, rightIRSensorNewValue) == 1;

			if (rightIRSensorIsChanged == 1)
			{
				if (rightIRSensorNewValue == 1)
				{
					OnboardHardware::movementManager.ClearQueue();
					OnboardHardware::movementManager.SetNextAction(
						DIRECTION_FORWARD, 0,
						DIRECTION_FORWARD, VELOCITY_MAX_SPEED,
						10000, 6, 6);
				}

				Serial.print(millis());
				Serial.print("Right IR sensor change state. New state");
				Serial.println(rightIRSensorNewValue);
			}
		}

		OnboardHardware::sensorStatesController.HandleAllSensors();
	}
}
//---------------------------------------------------------------------------