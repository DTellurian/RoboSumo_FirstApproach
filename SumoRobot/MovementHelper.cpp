// 
// 
// 

#include "MovementHelper.h"
#include "OnboardHardware.h"
//---------------------------------------------------------------------------

void MovementHelper::AddCenterAxisRotation(RotationDirection rotationDirection, RotationDegrees rotationDegrees, uint8_t velocity, uint32_t timeout)
{
	uint8_t wheelTicksCount = 2 * (uint8_t)rotationDegrees;

	if (rotationDirection == ROTATION_DIRECTION_RIGHT)
	{
		OnboardHardware::movementManager.SetNextAction(
			DIRECTION_FORWARD, velocity,
			DIRECTION_BACK, velocity,
			timeout, wheelTicksCount, wheelTicksCount);
	}
	else
	{
		OnboardHardware::movementManager.SetNextAction(
			DIRECTION_BACK, velocity,
			DIRECTION_FORWARD, velocity,
			timeout, wheelTicksCount, wheelTicksCount);
	}

}
//---------------------------------------------------------------------------

void MovementHelper::AddAroundWheelRotation(RotationDirection rotationDirection, RotationDegrees rotationDegrees, uint8_t velocity, uint32_t timeout)
{
	uint8_t wheelTicksCount = 3 * (uint8_t)rotationDegrees;

	if (rotationDirection == ROTATION_DIRECTION_RIGHT)
	{
		OnboardHardware::movementManager.SetNextAction(
			DIRECTION_FORWARD, velocity,
			DIRECTION_BACK, VELOCITY_VERY_LOW_SPEED,
			timeout, wheelTicksCount, wheelTicksCount);
	}
	else
	{
		OnboardHardware::movementManager.SetNextAction(
			DIRECTION_BACK, VELOCITY_VERY_LOW_SPEED,
			DIRECTION_FORWARD, velocity,
			timeout, wheelTicksCount, wheelTicksCount);
	}

}
//---------------------------------------------------------------------------