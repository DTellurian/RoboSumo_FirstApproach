/*
 Name:		SumoRobot.ino
 Created:	22-Dec-18 22:53:19
 Author:	Dmytro.Mykhalchuk
*/


#include "ModePushTarget.h"
#include "ModeBorderRotation.h"
#include "IMode.h"
#include "ModesController.h"
#include "MovementHelper.h"
#include "ModeSearchForTarget.h"
#include "TwoStateSensorWithDelay.h"
#include "DebugHelper.h"
#include "OnboardHardware.h"

// the setup function runs once when you press reset or power the board
void setup()
{
	//Serial.println("Setup SumoRobot");


	pinMode(LED_BUILTIN, OUTPUT);

	Serial.begin(9600);
}

// the loop function runs over and over again until power down or reset
void loop()
{
	//delay(700);
	DebugHelper::DelayForSeconds(3);

	Serial.println("Launch SumoRobot");

	OnboardHardware::Initialize();

	Serial.println("ModesController::SetCurrentMode");
	ModesController::SetCurrentMode(ModesController::searchForTargetModePtr);
	Serial.println("~ModesController::SetCurrentMode");


	while (true)
	{

		OnboardHardware::sensorStatesController.OnTick();
		OnboardHardware::wheelsSensorsStatesController.OnTick();
		OnboardHardware::movementManager.OnTick();

		//if (OnboardHardware::wheelsSensorsStatesController.HasChangedSensorValues())
		//{
		//	uint8_t rightWheelSensorTCRT5000NewValue = 0;
		//	uint8_t rightWheelSensorTCRT5000IsChanged = 0;

		//	rightWheelSensorTCRT5000IsChanged = OnboardHardware::wheelsSensorsStatesController.IsChanged(&OnboardHardware::rightWheelSensorTCRT5000, rightWheelSensorTCRT5000NewValue) == 1;

		//	if (rightWheelSensorTCRT5000IsChanged == 1)
		//	{
		//		Serial.print(millis());
		//		Serial.print("Right wheel sensor change state. New state");
		//		Serial.println(rightWheelSensorTCRT5000NewValue);
		//	}

		//	uint8_t leftWheelSensorTCRT5000NewValue = 0;
		//	uint8_t leftWheelSensorTCRT5000IsChanged = 0;

		//	leftWheelSensorTCRT5000IsChanged = OnboardHardware::wheelsSensorsStatesController.IsChanged(&OnboardHardware::leftWheelSensorTCRT5000, leftWheelSensorTCRT5000NewValue) == 1;

		//	if (leftWheelSensorTCRT5000IsChanged == 1)
		//	{
		//		Serial.print(millis());
		//		Serial.print("Left wheel sensor change state. New state");
		//		Serial.println(leftWheelSensorTCRT5000NewValue);
		//	}
		//}

		ModesController::OnTick();

		OnboardHardware::wheelsSensorsStatesController.HandleAllSensors();
		OnboardHardware::sensorStatesController.HandleAllSensors();
	}
}
