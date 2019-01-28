// MovementHelper.h

#ifndef _MOVEMENTHELPER_h
#define _MOVEMENTHELPER_h
//---------------------------------------------------------------------------

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
//---------------------------------------------------------------------------

typedef enum
{
	ROTATION_DIRECTION_LEFT = 0,
	ROTATION_DIRECTION_RIGHT = 1,
} RotationDirection;

typedef enum
{
	ROTATION_DEGREES_45 = 2,
	ROTATION_DEGREES_90 = 3,
	ROTATION_DEGREES_135 = 4,
	ROTATION_DEGREES_180 = 5,
} RotationDegrees;
//---------------------------------------------------------------------------

class MovementHelper
{
protected:


public:
	static void AddCenterAxisRotation(RotationDirection rotationDirection, RotationDegrees rotationDegrees, uint8_t velocity, uint32_t timeout);
	static void AddAroundWheelRotation(RotationDirection rotationDirection, RotationDegrees rotationDegrees, uint8_t velocity, uint32_t timeout);

private:
	MovementHelper();
	MovementHelper(MovementHelper&);
};

//---------------------------------------------------------------------------

#endif

