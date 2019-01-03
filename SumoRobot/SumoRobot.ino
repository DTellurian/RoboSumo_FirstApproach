/*
 Name:		SumoRobot.ino
 Created:	22-Dec-18 22:53:19
 Author:	Dmytro.Mykhalchuk
*/


#include "DebugHelper.h"
#include "OnboardHardware.h"

uint8_t leftSensorPin = 3;
uint8_t rightSensorPin = 4;

// the setup function runs once when you press reset or power the board
void setup()
{
	//Serial.println("Setup SumoRobot");


	pinMode(LED_BUILTIN, OUTPUT);
	pinMode(leftSensorPin, INPUT);
	pinMode(rightSensorPin, INPUT);

	Serial.begin(9600);

	/*digitalWrite(LED_BUILTIN, HIGH);
	delay(200);
	digitalWrite(LED_BUILTIN, LOW);
	delay(200);
	digitalWrite(LED_BUILTIN, HIGH);
	delay(200);
	digitalWrite(LED_BUILTIN, LOW);
	delay(200);
	digitalWrite(LED_BUILTIN, HIGH);
	delay(200);
	digitalWrite(LED_BUILTIN, LOW);
	delay(200);
	digitalWrite(LED_BUILTIN, HIGH);
	delay(200);
	digitalWrite(LED_BUILTIN, LOW);
	delay(200);
	digitalWrite(LED_BUILTIN, HIGH);
	delay(200);
	digitalWrite(LED_BUILTIN, LOW);
	delay(200);
	digitalWrite(LED_BUILTIN, HIGH);
	delay(200);
	digitalWrite(LED_BUILTIN, LOW);
	delay(200);

	Serial.println("Finish Setup SumoRobot");
	delay(2000);*/
}

// the loop function runs over and over again until power down or reset
void loop()
{
	delay(700);
	DebugHelper::DelayForSeconds(3);

	Serial.println("Launch SumoRobot");

	//EngineDriver leftEngine(12, 11, 10);
	//EngineDriver rightEngine(7, 8, 9);

	//SensorTCRT5000 leftSensorTCRT5000(15, 400);
	//SensorTCRT5000 rightSensorTCRT5000(14, 400);

	//MovementManager movementManager(&OnboardHardware::leftEngine, &OnboardHardware::rightEngine);

	//while (true)
	{
		//uint8_t leftSensorValueIR = digitalRead(leftSensorPin);
		//uint8_t rightSensorValueIR = digitalRead(rightSensorPin);

		//0 - somebody here
		//1 - nothing

		//Serial.print("Left:");
		//`Serial.println(leftSensorValueIR);
		//	Serial.print("Right:");
		//	Serial.println(rightSensorValueIR);

		//	Serial.println();
		//	delay(1000);

		//	continue;
	}



	while (true)
	{
		int leftSensorValue = OnboardHardware::leftSensorTCRT5000.Measure();
		int rifghtSensorValue = OnboardHardware::rightSensorTCRT5000.Measure();

		OnboardHardware::movementManager.OnTick();

		/*if (movementManager.AnyMovementExecuted() == 0)
		{
			movementManager.SetNextAction(
				DIRECTION_FORWARD, VELOCITY_CRUISER_SPEED,
				DIRECTION_FORWARD, VELOCITY_CRUISER_SPEED,
				100000);
		}*/

		//leftEngine.SetMode(DIRECTION_FORWARD, VELOCITY_CRUISER_SPEED);
		//rightEngine.SetMode(DIRECTION_FORWARD, VELOCITY_CRUISER_SPEED);

		if (OnboardHardware::leftSensorTCRT5000.IsSignaled() || OnboardHardware::rightSensorTCRT5000.IsSignaled())
		{

			OnboardHardware::leftSensorTCRT5000.Reset();
			OnboardHardware::rightSensorTCRT5000.Reset();

			Serial.print("L:");
			Serial.println(leftSensorValue);

			Serial.print("R:");
			Serial.println(rifghtSensorValue);

			OnboardHardware::movementManager.ClearQueue();

			Serial.println("Sensors!");
			DebugHelper::DelayForSeconds(5);

		/*	leftEngine.SetMode(DIRECTION_BACK, VELOCITY_CRUISER_SPEED);
			rightEngine.SetMode(DIRECTION_BACK, VELOCITY_CRUISER_SPEED);

			delay(100);

			leftEngine.SetMode(DIRECTION_BACK, VELOCITY_CRUISER_SPEED);
			rightEngine.SetMode(DIRECTION_FORWARD, VELOCITY_CRUISER_SPEED);

			delay(400);*/

			OnboardHardware::movementManager.SetNextAction(
				DIRECTION_BACK, VELOCITY_CRUISER_SPEED,
				DIRECTION_BACK, VELOCITY_CRUISER_SPEED,
				100);

			OnboardHardware::movementManager.SetNextAction(
				DIRECTION_FORWARD, VELOCITY_CRUISER_SPEED,
				DIRECTION_BACK, VELOCITY_CRUISER_SPEED,
				400);
		}

		if (0)
		{
			//0 - somebody here
			//1 - nothing
			uint8_t leftSensorValueIR = digitalRead(leftSensorPin);
			uint8_t rightSensorValueIR = digitalRead(rightSensorPin);

			if (rightSensorValueIR == 0 || leftSensorValueIR == 0)
			{
				uint8_t leftEngineSpeed = VELOCITY_CRUISER_SPEED;

				if (rightSensorValueIR == 0)
					leftEngineSpeed = VELOCITY_MAX_SPEED;

				uint8_t rightEngineSpeed = VELOCITY_CRUISER_SPEED;

				if (leftSensorValueIR == 0)
					rightEngineSpeed = VELOCITY_MAX_SPEED;

				//movementManager.ClearQueue();

				/*movementManager.SetNextAction(
					DIRECTION_FORWARD, leftEngineSpeed,
					DIRECTION_FORWARD, rightEngineSpeed,
					300);*/
			}
		}

	}
}
