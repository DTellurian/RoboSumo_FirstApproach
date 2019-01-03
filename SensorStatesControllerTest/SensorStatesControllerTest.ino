/*
 Name:		SensorStatesControllerTest.ino
 Created:	03-Jan-19 18:05:28
 Author:	Dmytro.Mykhalchuk
*/

#include "OnboardHardware.h"
#include "DebugHelper.h"

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
	Serial.println("SensorStatesControllerTest Launched!");
	Serial.println();

	DebugHelper::DelayForSeconds(5);

	while (true)
	{
		//int leftSensorValue = OnboardHardware::leftSensorTCRT5000.Measure();
		//int rifghtSensorValue = OnboardHardware::rightSensorTCRT5000.Measure();

		OnboardHardware::sensorStatesController.OnTick();

		if (OnboardHardware::sensorStatesController.HasChangedSensorValues())
		{
			uint8_t newSensorState = 0;
			
			if (OnboardHardware::sensorStatesController.IsChanged(&OnboardHardware::leftSensorTCRT5000, newSensorState) == 1)
			{
				Serial.print(millis());
				Serial.print("Left sensor change state. New state");
				Serial.println(newSensorState);
			}

			if (OnboardHardware::sensorStatesController.IsChanged(&OnboardHardware::rightSensorTCRT5000, newSensorState) == 1)
			{
				Serial.print(millis());
				Serial.print("Right sensor change state. New state");
				Serial.println(newSensorState);
			}

			if (OnboardHardware::sensorStatesController.IsChanged(&OnboardHardware::leftIRForwardSensor, newSensorState) == 1)
			{
				Serial.print(millis());
				Serial.print("Left IR sensor change state. New state");
				Serial.println(newSensorState);
			}

			if (OnboardHardware::sensorStatesController.IsChanged(&OnboardHardware::rightIRForwardSensor, newSensorState) == 1)
			{
				Serial.print(millis());
				Serial.print("Right IR sensor change state. New state");
				Serial.println(newSensorState);
			}
			
			OnboardHardware::sensorStatesController.HandleAllSensors();
		}
		else
		{
			//Serial.println("No changed states");
		}

		//DebugHelper::DelayForSeconds(5);
	}
}
