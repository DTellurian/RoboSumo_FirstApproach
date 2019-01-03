/*
 Name:		SensorStatesControllerTest.ino
 Created:	03-Jan-19 18:05:28
 Author:	Dmytro.Mykhalchuk
*/

#include "OnboardHardware.h"

uint8_t leftSensorPin = 3;
uint8_t rightSensorPin = 4;

// the setup function runs once when you press reset or power the board
void setup()
{
	pinMode(LED_BUILTIN, OUTPUT);
	pinMode(leftSensorPin, INPUT);
	pinMode(rightSensorPin, INPUT);

	Serial.begin(9600);
}

// the loop function runs over and over again until power down or reset
void loop()
{
	int leftSensorValue = OnboardHardware::leftSensorTCRT5000.Measure();
	int rifghtSensorValue = OnboardHardware::rightSensorTCRT5000.Measure();

	OnboardHardware::sensorStatesController.OnTick();
}
