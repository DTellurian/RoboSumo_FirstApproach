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

#define MovementManager_QUEUE_LENGTH 3

class MovementManager
{
private:
	EngineDriver* _leftEngineDriverPtr;
	EngineDriver* _rightEngineDriverPtr;

	AtomicMotion firstMotion;
	AtomicMotion secondMotion;
	AtomicMotion thirdMotion;

	AtomicMotion* motionsPtrArray[MovementManager_QUEUE_LENGTH];

	int8_t lastMotionToExecuteIndex = -1;
	uint8_t nextMotionIndex = 0;

	uint32_t nextItemStartTimeMS = 0;
protected:


public:
	MovementManager(EngineDriver* leftEngineDriverPtr, EngineDriver* rightEngineDriverPtr);

	void OnTick();
	void SetNextAction(uint8_t directionLeftEngine, uint8_t velocityLeftEngine, uint8_t directionRightEngine, uint8_t velocityRightEngine, uint32_t duration);
	void ClearQueue();

	uint8_t AnyMovementExecuted();
};

#endif

