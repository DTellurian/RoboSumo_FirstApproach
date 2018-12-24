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

// the setup function runs once when you press reset or power the board
void setup()
{
	pinMode(LED_BUILTIN, OUTPUT);

	Serial.begin(9600);

	Serial.println("Setup");
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
	Serial.println("Launch");

	uint8_t velocityArray[6] = { 40, 30, 40, 140, 190, VELOCITY_MAX_SPEED };
	uint8_t arrayLength = 6;
	uint8_t index = 0;

	uint32_t currentMillisecondsCount = 0;
	uint32_t nextActionTime = 0;

	EngineDriver leftEngine(12, 11, 10);
	EngineDriver rightEngine(7, 8, 9);

	SensorTCRT5000 leftSensorTCRT5000(15, 400);
	SensorTCRT5000 rightSensorTCRT5000(14, 400);

	DelayForSeconds(5);

	uint8_t currentVelocity = 140;
	//uint8_t currentVelocity = VELOCITY_MAX_SPEED;

	leftEngine.SetMode(DIRECTION_FORWARD, currentVelocity);
	rightEngine.SetMode(DIRECTION_FORWARD, currentVelocity);

	while (true)
	{
		int leftSensorValue = leftSensorTCRT5000.Measure();
		int rifghtSensorValue = rightSensorTCRT5000.Measure();


		if (leftSensorTCRT5000.IsSignaled() || rightSensorTCRT5000.IsSignaled())
		{
			leftEngine.Stop();
			rightEngine.Stop();

			Serial.print("L:");
			Serial.println(leftSensorValue);

			Serial.print("R:");
			Serial.println(rifghtSensorValue);

			DelayForSeconds(10);

			leftSensorTCRT5000.Measure();
			rightSensorTCRT5000.Measure();

			leftEngine.SetMode(DIRECTION_FORWARD, currentVelocity);
			rightEngine.SetMode(DIRECTION_FORWARD, currentVelocity);
		}
	}
	{
		if (++index == arrayLength)
		{
			index = 0;
		}

		uint8_t currentVelocity = velocityArray[index];
		Serial.println(currentVelocity);

		currentMillisecondsCount = millis();
		nextActionTime = currentMillisecondsCount + 5000;

		leftEngine.SetMode(DIRECTION_FORWARD, currentVelocity);
		rightEngine.SetMode(DIRECTION_FORWARD, currentVelocity);

		Serial.println("FORWARD-FORWARD");

		while (nextActionTime > currentMillisecondsCount)
		{
			currentMillisecondsCount = millis();
		}

		digitalWrite(LED_BUILTIN, digitalRead(LED_BUILTIN) ^ 0x1);
		nextActionTime = currentMillisecondsCount + 2000;

		leftEngine.SetMode(DIRECTION_BACK, currentVelocity);
		rightEngine.SetMode(DIRECTION_FORWARD, currentVelocity);

		Serial.println("BACK-FORWARD");

		while (nextActionTime > currentMillisecondsCount)
		{
			currentMillisecondsCount = millis();
		}

		leftEngine.SetMode(DIRECTION_FORWARD, currentVelocity);
		rightEngine.SetMode(DIRECTION_BACK, currentVelocity);

		digitalWrite(LED_BUILTIN, digitalRead(LED_BUILTIN) ^ 0x1);
		nextActionTime = currentMillisecondsCount + 2000;

		Serial.println("FORWARD-BACK");

		while (nextActionTime > currentMillisecondsCount)
		{
			currentMillisecondsCount = millis();
		}

		leftEngine.SetMode(DIRECTION_BACK, currentVelocity);
		rightEngine.SetMode(DIRECTION_BACK, currentVelocity);

		digitalWrite(LED_BUILTIN, digitalRead(LED_BUILTIN) ^ 0x1);
		nextActionTime = currentMillisecondsCount + 4000;

		Serial.println("BACK-BACK");

		while (nextActionTime > currentMillisecondsCount)
		{
			currentMillisecondsCount = millis();
		}

		digitalWrite(LED_BUILTIN, digitalRead(LED_BUILTIN) ^ 0x1);
		nextActionTime = currentMillisecondsCount + 5000;

		digitalWrite(LED_BUILTIN, digitalRead(LED_BUILTIN) ^ 0x1);
		leftEngine.Stop();
		rightEngine.Stop();

		Serial.println("Stop");

		while (nextActionTime > currentMillisecondsCount)
		{
			currentMillisecondsCount = millis();
		}

	}
}
