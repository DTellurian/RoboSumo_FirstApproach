// 
// 
// 

#include "MovementManager.h"
//---------------------------------------------------------------------------

MovementManager::MovementManager(EngineDriver* leftEngineDriverPtr, EngineDriver* rightEngineDriverPtr)
{
	lastMotionToExecuteIndex = -1;
	nextMotionIndex = 0;

	nextItemStartTimeMS = 0;

	_leftEngineDriverPtr = leftEngineDriverPtr;
	_rightEngineDriverPtr = rightEngineDriverPtr;

	motionsPtrArray[0] = &firstMotion;
	motionsPtrArray[1] = &secondMotion;
	motionsPtrArray[2] = &thirdMotion;
}
//---------------------------------------------------------------------------

void MovementManager::SetNextAction(uint8_t directionLeftEngine, uint8_t velocityLeftEngine, uint8_t directionRightEngine, uint8_t velocityRightEngine, uint32_t duration)
{
	AtomicMotion* targetMotion = motionsPtrArray[++lastMotionToExecuteIndex];

	targetMotion->directionLeftEngine = directionLeftEngine;
	targetMotion->directionRightEngine = directionRightEngine;

	targetMotion->velocityLeftEngine = velocityLeftEngine;
	targetMotion->velocityRightEngine = velocityRightEngine;

	targetMotion->_durationMs = duration;

	if (lastMotionToExecuteIndex == 0)
		OnTick();
}
//---------------------------------------------------------------------------

void MovementManager::OnTick()
{
	if (lastMotionToExecuteIndex >= 0)
	{
		uint32_t currentTimeMS = millis();

		if (currentTimeMS > nextItemStartTimeMS)
		{
			if (nextMotionIndex > lastMotionToExecuteIndex)
			{
				ClearQueue();
			}
			else
			{
				AtomicMotion* currentMotion = motionsPtrArray[nextMotionIndex++];

				_leftEngineDriverPtr->SetMode(currentMotion->directionLeftEngine, currentMotion->velocityLeftEngine);
				_rightEngineDriverPtr->SetMode(currentMotion->directionRightEngine, currentMotion->velocityRightEngine);

				nextItemStartTimeMS = currentTimeMS + currentMotion->_durationMs;							
			}
		}
	}
}
//---------------------------------------------------------------------------

void MovementManager::ClearQueue()
{
	lastMotionToExecuteIndex = -1;
	nextMotionIndex = 0;
	nextItemStartTimeMS = 0;

	_leftEngineDriverPtr->Stop();
	_rightEngineDriverPtr->Stop();
}
//---------------------------------------------------------------------------

uint8_t MovementManager::AnyMovementExecuted()
{
	return lastMotionToExecuteIndex != -1;
}
//---------------------------------------------------------------------------