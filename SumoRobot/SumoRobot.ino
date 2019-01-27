/*
 Name:		SumoRobot.ino
 Created:	22-Dec-18 22:53:19
 Author:	Dmytro.Mykhalchuk
*/


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
		ModesController::OnTick();

		OnboardHardware::wheelsSensorsStatesController.HandleAllSensors();
		OnboardHardware::sensorStatesController.HandleAllSensors();
	}
}
