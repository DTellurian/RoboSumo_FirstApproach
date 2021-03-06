// DigitalInputSensor.h

#ifndef _DIGITALINPUTSENSOR_h
#define _DIGITALINPUTSENSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
//---------------------------------------------------------------------------

#include "TwoStateSensor.h"
//---------------------------------------------------------------------------

class DigitalInputSensor : public TwoStateSensor
{
 protected:


 public:
	 DigitalInputSensor(uint8_t pin, uint8_t signaledDigitalValue);

	 virtual void OnTick();	 
private:
	DigitalInputSensor();
	DigitalInputSensor(DigitalInputSensor&);

	uint8_t _pin;
	uint8_t _signaledDigitalValue;	
};
//---------------------------------------------------------------------------

#endif

