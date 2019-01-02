// SensorStatesController.h

#ifndef _SENSORSTATESCONTROLLER_h
#define _SENSORSTATESCONTROLLER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#define SENSORS_COUNT 4

#include "TwoStateSensor.h"

class SensorStatesController
{
 protected:
	 TwoStateSensor* sensorsPtrArra[SENSORS_COUNT];

 public:
	
};

//extern SensorStatesController sensorStatesController;

#endif

