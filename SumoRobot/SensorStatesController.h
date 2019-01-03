// SensorStatesController.h

#ifndef _SENSORSTATESCONTROLLER_h
#define _SENSORSTATESCONTROLLER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
//---------------------------------------------------------------------------

#define SENSORS_COUNT 4
//---------------------------------------------------------------------------

#include "TwoStateSensor.h"
//---------------------------------------------------------------------------

class SensorStatesController
{
protected:
	TwoStateSensor* sensorsPtrArray[SENSORS_COUNT] = {};
	uint8_t handeledSensorsStates[SENSORS_COUNT] = {};
	uint8_t currentSensorsState[SENSORS_COUNT] = {};
	uint8_t hasUnhandledSensorValues = 0;	

	uint8_t IsUnhandled(TwoStateSensor* sensotToCheckPtr, uint8_t& newValue);

public:
	SensorStatesController();

	void OnTick();

private:
	SensorStatesController();
	SensorStatesController(SensorStatesController&);
};
//---------------------------------------------------------------------------
//extern SensorStatesController sensorStatesController;

#endif

