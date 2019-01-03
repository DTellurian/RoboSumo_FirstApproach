// OnboardHardware.h

#ifndef _ONBOARDHARDWARE_h
#define _ONBOARDHARDWARE_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "EngineDriver.h"
#include "SensorTCRT5000.h"
#include "MovementManager.h"
#include "SensorStatesController.h"

class OnboardHardware
{
protected:


public:
	static EngineDriver leftEngine;
	static EngineDriver rightEngine;

	static SensorTCRT5000 leftSensorTCRT5000;
	static SensorTCRT5000 rightSensorTCRT5000;

	static MovementManager movementManager;
	static SensorStatesController sensorStatesController;
private:
	OnboardHardware(void);
	OnboardHardware(OnboardHardware&);

};

#endif

