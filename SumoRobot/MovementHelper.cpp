// 
// 
// 

#include "MovementHelper.h"
#include "OnboardHardware.h"
//---------------------------------------------------------------------------

void MovementHelperClass::AddCenterAxisRotation(RotationDirection rotationDirection, RotationDegrees rotationDegrees, uint8_t velocity, uint16_t timeout)
{
	uint8_t wheelTicksCount = 3 * (uint8_t)rotationDegrees;

	OnboardHardware::movementManager.SetNextAction(
		!rotationDirection, velocity,
		rotationDirection, velocity,
		timeout, wheelTicksCount, wheelTicksCount);
}
//---------------------------------------------------------------------------