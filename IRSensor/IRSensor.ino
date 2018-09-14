/*
 Name:		IRSensor.ino
 Created:	11/19/2017 3:31:10 PM
 Author:	Mihalych
*/

// the setup function runs once when you press reset or power the board
#include "EnginesDriver.h"
#include "LedDriver.h"
#include <inttypes.h>

uint8_t sensorPin = 7;
uint8_t pwmPin = 9;

void setup()
{
	/* add setup code here, setup code runs once when the processor starts */
	pinMode(LED_BUILTIN, OUTPUT);
	pinMode(sensorPin, INPUT);
	pinMode(pwmPin, OUTPUT);

	Serial.begin(9600);           // set up Serial library at 9600 bps

	Serial.println("Hello uint32! Approach3777");  // prints hello with ending line break
	delay(5000);                       // wait for a second
}

// the loop function runs over and over again until power down or reset
void loop()
{
	/* add main program code here, this code starts again each time it ends */
	uint32_t counter = 0;
	int8_t sensorValue;
	uint8_t isOn = 0;

	LedDriver ledDriver;

	analogWrite(pwmPin, 128);

	while (true)
	{
		// put your main code here, to run repeatedly:

		//ledDriver.TirnOn();
		//delay(100);                       // wait for a second
		//ledDriver.TirnOff();
		//delay(100);
		//ledDriver.TirnOn();
		//delay(100);                       // wait for a second
		//ledDriver.TirnOff();
		//delay(100);
		//ledDriver.TirnOn();
		//delay(1000);                       // wait for a second
		//ledDriver.TirnOff();
		//delay(100);

		sensorValue = digitalRead(sensorPin);

		if (sensorValue == 1 && isOn == 0)
		{
			analogWrite(pwmPin, 250);
			isOn = 1;
		}

		if (sensorValue == 0 && isOn == 1)
		{
			analogWrite(pwmPin, 50);
			isOn = 0;
		}

		digitalWrite(LED_BUILTIN, sensorValue);

		//Serial.println(counter++);
		Serial.println(counter++, DEC);

		//Serial.printNumber(counter++);

		delay(100);

		// send data only when you receive data:
		if (Serial.available() > 0)
		{
			// read the incoming byte:
			uint8_t incomingByte = Serial.read();

			// say what you got:
			Serial.print("I received: ");
			Serial.println(incomingByte, DEC);

			analogWrite(pwmPin, incomingByte);
		}
	}
}
