/*
 Name:		ModeSearchForTargetTest.ino
 Created:	05-Jan-19 00:07:43
 Author:	Dmytro.Mykhalchuk
*/
//---------------------------------------------------------------------------

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
	Serial.println("ModeSearchForTargetTest Launched!");
	Serial.println();

	DebugHelper::DelayForSeconds(2);
	ModeSearchForTarget modeSearchForTarget;

	OnboardHardware::movementManager.SetNextAction(
		DIRECTION_FORWARD, VELOCITY_CRUISER_SPEED,
		DIRECTION_FORWARD, VELOCITY_CRUISER_SPEED,
		100000);

	while (true)
	{
		OnboardHardware::sensorStatesController.OnTick();
		OnboardHardware::movementManager.OnTick();

		modeSearchForTarget.OnTick();

		OnboardHardware::sensorStatesController.HandleAllSensors();
	}
}
//---------------------------------------------------------------------------