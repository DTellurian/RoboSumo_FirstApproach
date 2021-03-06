// 
// 
// 

#include "MovementManager.h"
//---------------------------------------------------------------------------

MovementManager::MovementManager(EngineDriver* leftEngineDriverPtr, EngineDriver* rightEngineDriverPtr, SensorTCRT5000* leftWheelSensorPtr, SensorTCRT5000* rightWheelSensorPtr, SensorStatesController* wheelsSensorsStatesControllerPtr)
{
	_lastMotionToExecuteIndex = -1;
	_nextMotionIndex = 0;

	_nextItemStartTimeMS = 0;

	_leftEngineDriverPtr = leftEngineDriverPtr;
	_rightEngineDriverPtr = rightEngineDriverPtr;

	_leftWheelSensorPtr = leftWheelSensorPtr;
	_rightWheelSensorPtr = rightWheelSensorPtr;
	_wheelsSensorsStatesControllerPtr = wheelsSensorsStatesControllerPtr;

	_motionsPtrArray[0] = &firstMotion;
	_motionsPtrArray[1] = &secondMotion;
	_motionsPtrArray[2] = &thirdMotion;
}
//---------------------------------------------------------------------------

void MovementManager::SetNextAction(uint8_t directionLeftEngine, uint8_t velocityLeftEngine, uint8_t directionRightEngine, uint8_t velocityRightEngine, uint32_t duration, uint32_t leftWheelTicks, uint32_t rightWheelTicks)
{
	AtomicMotion* targetMotion = _motionsPtrArray[++_lastMotionToExecuteIndex];

	targetMotion->directionLeftEngine = directionLeftEngine;
	targetMotion->directionRightEngine = directionRightEngine;

	targetMotion->velocityLeftEngine = velocityLeftEngine;
	targetMotion->velocityRightEngine = velocityRightEngine;

	targetMotion->_durationMs = duration;

	targetMotion->leftWheelTicks = leftWheelTicks;
	targetMotion->rightWheelTicks = rightWheelTicks;

	if (_lastMotionToExecuteIndex == 0)
		OnTick();
}
//---------------------------------------------------------------------------

void MovementManager::OnTick()
{
	if (_lastMotionToExecuteIndex >= 0)
	{
		uint32_t currentTimeMS = millis();

		if (_wheelsSensorsStatesControllerPtr->HasChangedSensorValues())
		{
			uint8_t rightWheelSensorTCRT5000NewValue = 0;
			if (_wheelsSensorsStatesControllerPtr->IsChanged(_rightWheelSensorPtr, rightWheelSensorTCRT5000NewValue) == 1)
			{
				_rightWheelTicksCount++;
			}

			uint8_t leftWheelSensorTCRT5000NewValue = 0;
			if (_wheelsSensorsStatesControllerPtr->IsChanged(_leftWheelSensorPtr, leftWheelSensorTCRT5000NewValue) == 1)
			{
				_leftWheelTicksCount++;
			}
		}

		uint8_t needToStartNextAction = 0;

		if (_nextItemStartRightWheelTicksCount > 0 && _rightWheelTicksCount >= _nextItemStartRightWheelTicksCount)
		{
			needToStartNextAction = 1;
			//TODO: In current realization after first wheel reaching goal next action will be started!
		}

		if (_nextItemStartLeftWheelTicksCount > 0 && _leftWheelTicksCount >= _nextItemStartLeftWheelTicksCount)
		{
			needToStartNextAction = 1;
			//TODO: In current realization after first wheel reaching goal next action will be started!
		}

		if (currentTimeMS > _nextItemStartTimeMS)
		{
			needToStartNextAction = 1;
		}

		if (needToStartNextAction == 1)
		{
			if (_nextMotionIndex > _lastMotionToExecuteIndex)
			{
				ClearQueue();
				//Serial.println("Queue ended");
			}
			else
			{
				AtomicMotion* currentMotion = _motionsPtrArray[_nextMotionIndex++];

				//Serial.println("NewAction");
				//Serial.print("Left engine:");
				//Serial.println(currentMotion->directionLeftEngine);
				//Serial.print("Right engine:");
				//Serial.println(currentMotion->directionRightEngine);
				//Serial.println();

				_leftEngineDriverPtr->SetMode(currentMotion->directionLeftEngine, currentMotion->velocityLeftEngine);
				_rightEngineDriverPtr->SetMode(currentMotion->directionRightEngine, currentMotion->velocityRightEngine);

				_nextItemStartTimeMS = currentTimeMS + currentMotion->_durationMs;
				_nextItemStartRightWheelTicksCount = currentMotion->rightWheelTicks;
				_nextItemStartLeftWheelTicksCount = currentMotion->leftWheelTicks;
				_rightWheelTicksCount = 0;
				_leftWheelTicksCount = 0;
			}
		}
	}
}
//---------------------------------------------------------------------------

void MovementManager::ClearQueue()
{
	_lastMotionToExecuteIndex = -1;
	_nextMotionIndex = 0;
	_nextItemStartTimeMS = 0;

	_leftEngineDriverPtr->Stop();
	_rightEngineDriverPtr->Stop();
}
//---------------------------------------------------------------------------

uint8_t MovementManager::AnyMovementExecuted()
{
	return _lastMotionToExecuteIndex != -1;
}
//---------------------------------------------------------------------------