// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
	Name:       TCRT5000.ino
	Created:	14-Sep-18 00:45:50
	Author:     DESKTOP-FD466U3\Dmytro.Mykhalchuk
*/

// Define User Types below here or use a .h file
//


// Define Function Prototypes that use User Types below here or use a .h file
//


// Define Functions below here or use other .ino or cpp files
//
#include "SensorTCRT5000.h"
#include "EngineDriver.h"
#include "MovementManager.h"

// the setup function runs once when you press reset or power the board
void setup()
{
	pinMode(LED_BUILTIN, OUTPUT);

	Serial.begin(9600);

	Serial.println("Setup TCRT5000");
	delay(2000);
}

void DelayForSeconds(uint8_t secondsCount)
{
	while (secondsCount-- > 0)
	{
		Serial.print(secondsCount + 1);
		Serial.println(" left");

		delay(1000);
	}
}

// the loop function runs over and over again until power down or reset
void loop()
{
	Serial.println("Launch TCRT5000");

	uint8_t velocityArray[6] = { 80, 100, 120, 140, 190, VELOCITY_MAX_SPEED };
	uint8_t arrayLength = 6;
	uint8_t index = 0;

	uint32_t currentMillisecondsCount = 0;
	uint32_t nextActionTime = 0;

	EngineDriver leftEngine(12, 11, 10);
	EngineDriver rightEngine(7, 8, 9);

	SensorTCRT5000 leftSensorTCRT5000(15, 400);
	SensorTCRT5000 rightSensorTCRT5000(14, 400);

	MovementManager movementManager(&leftEngine, &rightEngine);

	DelayForSeconds(5);

	//uint8_t currentVelocity = 140;
	uint8_t currentVelocity = velocityArray[1];
	//uint8_t currentVelocity = VELOCITY_CRUISER_SPEED;//220;


	movementManager.SetNextAction(
		DIRECTION_FORWARD, currentVelocity,
		DIRECTION_FORWARD, currentVelocity,
		1000);

	movementManager.SetNextAction(
		DIRECTION_BACK, velocityArray[1],
		DIRECTION_BACK, velocityArray[1],
		2000);

	while (movementManager.AnyMovementExecuted() != 0)
	{
		movementManager.OnTick();
	}

	movementManager.SetNextAction(
		DIRECTION_FORWARD, currentVelocity,
		DIRECTION_FORWARD, currentVelocity,
		100000);

	while (true)
	{
		int leftSensorValue = leftSensorTCRT5000.Measure();
		int rifghtSensorValue = rightSensorTCRT5000.Measure();

		movementManager.OnTick();

		if (movementManager.AnyMovementExecuted() == 0)
		{
			Serial.println("AnyMovementExecuted() == 0");
			DelayForSeconds(5);

			movementManager.SetNextAction(
				DIRECTION_FORWARD, currentVelocity,
				DIRECTION_FORWARD, currentVelocity,
				100000);
		}

		if (leftSensorTCRT5000.IsSignaled() || rightSensorTCRT5000.IsSignaled())
		{
			Serial.print("L:");
			Serial.println(leftSensorValue);

			Serial.print("R:");
			Serial.println(rifghtSensorValue);

			movementManager.ClearQueue();

			Serial.println("Sensors!");
			DelayForSeconds(5);

			movementManager.SetNextAction(
				DIRECTION_BACK, velocityArray[1],
				DIRECTION_BACK, velocityArray[2],
				1000);

			movementManager.SetNextAction(
				DIRECTION_BACK, velocityArray[2],
				DIRECTION_BACK, velocityArray[1],
				1000);
		}
	}
}
