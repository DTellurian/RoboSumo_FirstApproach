/*
 Name:		SumoRobot.ino
 Created:	22-Dec-18 22:53:19
 Author:	Dmytro.Mykhalchuk
*/

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

	while (true)
	{
		int sensorValue = leftSensorTCRT5000.Measure();
		Serial.print("L:");
		Serial.println(sensorValue);

		sensorValue = rightSensorTCRT5000.Measure();
		Serial.print("R:");
		Serial.println(sensorValue);

		Serial.println();

		delay(1000);
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
