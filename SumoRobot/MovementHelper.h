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
	ROTATION_DEGREES_45 = 1,
	ROTATION_DEGREES_90 = 2,
	ROTATION_DEGREES_135 = 3,
	ROTATION_DEGREES_180 = 4,
} RotationDegrees;
//---------------------------------------------------------------------------

class MovementHelperClass
{
protected:


public:
	static void AddCenterAxisRotation(RotationDirection rotationDirection, RotationDegrees rotationDegrees, uint8_t velocity, uint16_t timeout);

private:
	MovementHelperClass();
	MovementHelperClass(MovementHelperClass&);
};

//---------------------------------------------------------------------------

#endif

