// SensorStatesController.h

#ifndef _SENSORSTATESCONTROLLER_h
#define _SENSORSTATESCONTROLLER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
//---------------------------------------------------------------------------

#define SENSORS_COUNT 2
//---------------------------------------------------------------------------

#include "TwoStateSensor.h"
//---------------------------------------------------------------------------

class SensorStatesController
{
protected:
	TwoStateSensor* sensorsPtrArray[SENSORS_COUNT] = {};
	uint8_t handeledSensorsStates[SENSORS_COUNT] = {};	
	uint8_t hasChangedSensorValues = 0;	

	

public:
	SensorStatesController();

	void OnTick();
	uint8_t IsChanged(TwoStateSensor* sensotToCheckPtr, uint8_t& newValue);
	uint8_t HasChangedSensorValues();
	void HandleAllSensors();

private:
	SensorStatesController(SensorStatesController&);
};
//---------------------------------------------------------------------------
//extern SensorStatesController sensorStatesController;

#endif

