// MovementManager.h

#ifndef _MOVEMENTMANAGER_h
#define _MOVEMENTMANAGER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "EngineDriver.h"
#include "AtomicMotion.h"
#include "SensorTCRT5000.h"
#include "SensorStatesController.h"

#define MovementManager_QUEUE_LENGTH 3

class MovementManager
{
private:
	EngineDriver* _leftEngineDriverPtr;
	EngineDriver* _rightEngineDriverPtr;

	SensorTCRT5000* _rightWheelSensorPtr;
	SensorTCRT5000* _leftWheelSensorPtr;
	SensorStatesController* _wheelsSensorsStatesControllerPtr;

	AtomicMotion firstMotion;
	AtomicMotion secondMotion;
	AtomicMotion thirdMotion;

	AtomicMotion* _motionsPtrArray[MovementManager_QUEUE_LENGTH];

	int8_t _lastMotionToExecuteIndex = -1;
	uint8_t _nextMotionIndex = 0;

	uint32_t _nextItemStartTimeMS = 0;

	uint32_t _nextItemStartRightWheelTicksCount = 0;
	uint32_t _nextItemStartLeftWheelTicksCount = 0;

	uint32_t _rightWheelTicksCount = 0;
	uint32_t _leftWheelTicksCount = 0;
protected:


public:
	MovementManager(EngineDriver* leftEngineDriverPtr, EngineDriver* rightEngineDriverPtr, SensorTCRT5000* leftWheelSensorPtr, SensorTCRT5000* rightWheelSensorPtr, SensorStatesController* wheelsSensorsStatesControllerPtr);

	void OnTick();
	void SetNextAction(uint8_t directionLeftEngine, uint8_t velocityLeftEngine, uint8_t directionRightEngine, uint8_t velocityRightEngine, uint32_t duration, uint32_t leftWheelTicks = 0, uint32_t rightWheelTicks = 0);
	void ClearQueue();

	uint8_t AnyMovementExecuted();
};

#endif

