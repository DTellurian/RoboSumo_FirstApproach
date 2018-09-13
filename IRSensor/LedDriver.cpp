// 
// 
// 

#include "LedDriver.h"


void LedDriver::TirnOn()
{
	digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
}

void LedDriver::TirnOff()
{
	digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
}
