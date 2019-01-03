// 
// 
// 

#include "SensorStatesController.h"
//---------------------------------------------------------------------------

//SensorStatesController sensorStatesController;
//---------------------------------------------------------------------------

SensorStatesController::SensorStatesController()
{
}
//---------------------------------------------------------------------------

void SensorStatesController::OnTick()
{
	hasUnhandledSensorValues = 0;

	for (uint8_t i = 0; i < SENSORS_COUNT; i++)
	{
		currentSensorsState[i] = sensorsPtrArray[i]->IsSignaled();

		if (currentSensorsState[i] != handeledSensorsStates[i])
			hasUnhandledSensorValues |= 1;
	}
}
//---------------------------------------------------------------------------

uint8_t SensorStatesController::IsUnhandled(TwoStateSensor* sensotToCheckPtr, uint8_t & newValue)
{
	for (uint8_t i = 0; i < SENSORS_COUNT; i++)
	{
		if (sensorsPtrArray[i] == sensotToCheckPtr)
		{
			if (handeledSensorsStates[i] != sensorsPtrArray[i]->IsSignaled())
			{
				newValue = sensorsPtrArray[i]->IsSignaled();
				return 1;
			}
			else
				return 0;
		}
	}
}
//---------------------------------------------------------------------------
