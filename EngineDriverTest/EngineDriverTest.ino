/*
 Name:		EngineDriverTest.ino
 Created:	27-Jan-19 22:09:10
 Author:	Dmytro.Mykhalchuk
*/

#include "EngineDriver.h"
#include "DebugHelper.h"

// the setup function runs once when you press reset or power the board
void setup()
{
	pinMode(LED_BUILTIN, OUTPUT);

	Serial.begin(9600);
}

// the loop function runs over and over again until power down or reset
void loop()
{

	Serial.println("EngineDriverTest Launched!");
	Serial.println();

	EngineDriver leftEngine(12, 11, 9);
	//pinMode(12, OUTPUT);
	//pinMode(11, OUTPUT);
	//pinMode(10, OUTPUT);
	//digitalWrite(10, HIGH);

	EngineDriver rightEngine(7, 8, 10);
	//pinMode(7, OUTPUT);
	//pinMode(8, OUTPUT);
	//pinMode(9, OUTPUT);
	//digitalWrite(9, HIGH);

	DebugHelper::DelayForSeconds(2);

	//leftEngine.SetMode(DIRECTION_FORWARD, VELOCITY_CRUISER_SPEED);
	//rightEngine.SetMode(DIRECTION_FORWARD, VELOCITY_CRUISER_SPEED);
	//delay(3000);

	//leftEngine.SetMode(DIRECTION_BACK, VELOCITY_CRUISER_SPEED);
	//rightEngine.SetMode(DIRECTION_BACK, VELOCITY_CRUISER_SPEED);
	//delay(3000);

//	leftEngine.Stop();
//	rightEngine.Stop();

	leftEngine.SetMode(DIRECTION_FORWARD, VELOCITY_CRUISER_SPEED);
	//digitalWrite(12, HIGH);
	//digitalWrite(11, LOW);
	Serial.println("L_F");
	delay(3000);
	leftEngine.Stop();
	//digitalWrite(12, LOW);
	//digitalWrite(11, LOW);

	rightEngine.SetMode(DIRECTION_FORWARD, VELOCITY_CRUISER_SPEED);
	//digitalWrite(7, HIGH);
	//digitalWrite(8, LOW);
	Serial.println("R_F");
	delay(3000);
	rightEngine.Stop();
	//digitalWrite(7, LOW);
	//digitalWrite(8, LOW);

	leftEngine.SetMode(DIRECTION_BACK, VELOCITY_CRUISER_SPEED);
	//digitalWrite(12, LOW);
	//digitalWrite(11, HIGH);
	Serial.println("L_B");
	delay(3000);
	leftEngine.Stop();
	//digitalWrite(12, LOW);
	//digitalWrite(11, LOW);

	rightEngine.SetMode(DIRECTION_BACK, VELOCITY_CRUISER_SPEED);
	//digitalWrite(7, LOW);
	//digitalWrite(8, HIGH);
	Serial.println("R_B");
	delay(3000);
	rightEngine.Stop();
	//digitalWrite(7, LOW);
	//digitalWrite(8, LOW);

	delay(10000);

	while (true)
	{
		delay(10000);
	}
}
