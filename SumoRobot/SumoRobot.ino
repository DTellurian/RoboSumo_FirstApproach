/*
 Name:		SumoRobot.ino
 Created:	22-Dec-18 22:53:19
 Author:	Dmytro.Mykhalchuk
*/

#include "SensorTCRT5000.h"
#include "EngineDriver.h"
#include "MovementManager.h"

uint8_t leftSensorPin = 3;
uint8_t rightSensorPin = 4;

// the setup function runs once when you press reset or power the board
void setup()
{
	//Serial.println("Setup SumoRobot");


	pinMode(LED_BUILTIN, OUTPUT);
	pinMode(leftSensorPin, INPUT);
	pinMode(rightSensorPin, INPUT);

	//Serial.begin(9600);

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

void DelayForSeconds(uint8_t secondsCount)
{
	while (secondsCount-- > 0)
	{
		//Serial.print(secondsCount + 1);
		//Serial.println(" left");

		delay(1000);
	}
}

// the loop function runs over and over again until power down or reset
void loop()
{
	delay(700);
	//DelayForSeconds(5);	

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

	//Serial.println("Launch SumoRobot");

	EngineDriver leftEngine(12, 11, 10);
	EngineDriver rightEngine(7, 8, 9);

	SensorTCRT5000 leftSensorTCRT5000(15, 400);
	SensorTCRT5000 rightSensorTCRT5000(14, 400);

	//MovementManager movementManager(&leftEngine, &rightEngine);

	//while (true)
	//{
	//	uint8_t leftSensorValueIR = digitalRead(leftSensorPin);
	//	uint8_t rightSensorValueIR = digitalRead(rightSensorPin);

	//	//0 - somebody here
	//	//1 - nothing

	//	Serial.print("Left:");
	//	Serial.println(leftSensorValueIR);
	//	Serial.print("Right:");
	//	Serial.println(rightSensorValueIR);

	//	Serial.println();
	//	delay(1000);

	//	continue;
	//}

	

	while (true)
	{
		int leftSensorValue = leftSensorTCRT5000.Measure();
		int rifghtSensorValue = rightSensorTCRT5000.Measure();

		//movementManager.OnTick();

		/*if (movementManager.AnyMovementExecuted() == 0)
		{
			movementManager.SetNextAction(
				DIRECTION_FORWARD, VELOCITY_CRUISER_SPEED,
				DIRECTION_FORWARD, VELOCITY_CRUISER_SPEED,
				100000);
		}*/

		leftEngine.SetMode(DIRECTION_FORWARD, VELOCITY_CRUISER_SPEED);
		rightEngine.SetMode(DIRECTION_FORWARD, VELOCITY_CRUISER_SPEED);

		if (leftSensorTCRT5000.IsSignaled() || rightSensorTCRT5000.IsSignaled())
		{
			leftSensorTCRT5000.Reset();
			rightSensorTCRT5000.Reset();

			//Serial.print("L:");
			//Serial.println(leftSensorValue);

			//Serial.print("R:");
			//Serial.println(rifghtSensorValue);

			//movementManager.ClearQueue();

			//Serial.println("Sensors!");
			//DelayForSeconds(5);

			leftEngine.SetMode(DIRECTION_BACK, VELOCITY_CRUISER_SPEED);
			rightEngine.SetMode(DIRECTION_BACK, VELOCITY_CRUISER_SPEED);

			delay(100);

			leftEngine.SetMode(DIRECTION_BACK, VELOCITY_CRUISER_SPEED);
			rightEngine.SetMode(DIRECTION_FORWARD, VELOCITY_CRUISER_SPEED);

			delay(400);

			//movementManager.SetNextAction(
			//	DIRECTION_BACK, VELOCITY_CRUISER_SPEED,
			//	DIRECTION_BACK, VELOCITY_CRUISER_SPEED,
			//	100);

			//movementManager.SetNextAction(
			//	DIRECTION_FORWARD, VELOCITY_CRUISER_SPEED,
			//	DIRECTION_BACK, VELOCITY_CRUISER_SPEED,
			//	300);
		}
		
		if(0)
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
