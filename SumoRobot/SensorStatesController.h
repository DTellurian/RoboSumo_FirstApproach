// SensorStatesController.h

#ifndef _SENSORSTATESCONTROLLER_h
#define _SENSORSTATESCONTROLLER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
//---------------------------------------------------------------------------

//#define SENSORS_COUNT 4
//---------------------------------------------------------------------------

#include "TwoStateSensor.h"
//---------------------------------------------------------------------------

class SensorStatesController
{
protected:
	//TwoStateSensor* sensorsPtrArray[SENSORS_COUNT] = {};
	//uint8_t handeledSensorsStates[SENSORS_COUNT] = {};	
	
	uint8_t* handeledSensorsStates;

	uint8_t hasChangedSensorValues = 0;	
	
public:
	SensorStatesController(uint8_t sensorsCount);

	TwoStateSensor** sensorsPtrArray;

	void OnTick();
	uint8_t IsChanged(TwoStateSensor* sensotToCheckPtr, uint8_t& newValue);
	uint8_t IsChangedAndHasSpecificValue(TwoStateSensor* sensotToCheckPtr, uint8_t valueToCheck);
	uint8_t HasChangedSensorValues();
	void HandleAllSensors();

private:
	SensorStatesController(SensorStatesController&);
	uint8_t _sensorsCount;
};
//---------------------------------------------------------------------------
//extern SensorStatesController sensorStatesController;

#endif

