// AtomicMotion.h


#ifndef _ATOMICMOTION_h
#define _ATOMICMOTION_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
//---------------------------------------------------------------------------

class AtomicMotion
{
 protected:


 public:
	 AtomicMotion();

	 uint8_t directionLeftEngine = 0;
	 uint8_t velocityLeftEngine = 0;

	 uint8_t directionRightEngine = 0;
	 uint8_t velocityRightEngine = 0;

	 uint32_t _durationMs = 0;
};
//---------------------------------------------------------------------------
#endif

