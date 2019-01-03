// 
// 
// 

#include "DebugHelper.h"
//---------------------------------------------------------------------------

void DebugHelper::DelayForSeconds(uint8_t secondsCount)
{
	while (secondsCount-- > 0)
	{
		Serial.print(secondsCount + 1);
		Serial.println(" left");

		delay(1000);
	}
}
//---------------------------------------------------------------------------