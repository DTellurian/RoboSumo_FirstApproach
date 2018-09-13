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
#include <inttypes.h>

uint8_t sensorPin = 14;

// The setup() function runs once each time the micro-controller starts
void setup()
{
	pinMode(LED_BUILTIN, OUTPUT);
	Serial.begin(9600);

	Serial.println("Hello uint32! Approach3777");  // prints hello with ending line break
	delay(5000);
}

// Add the main program code into the continuous loop() function
void loop()
{
	uint8_t val = analogRead(sensorPin);     // read the input pin
	Serial.println(val);
	delay(500);
}
