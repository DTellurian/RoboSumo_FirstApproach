// 
// 
// 

#include "SensorStatesController.h"
#include "OnboardHardware.h"
//---------------------------------------------------------------------------

//SensorStatesController sensorStatesController;
//---------------------------------------------------------------------------

SensorStatesController::SensorStatesController(uint8_t sensorsCount)
{
	_sensorsCount = sensorsCount;

	sensorsPtrArray = (TwoStateSensor**)calloc(_sensorsCount, sizeof(TwoStateSensor*));
	handeledSensorsStates = (uint8_t*)calloc(_sensorsCount, sizeof(uint8_t*));
}
//---------------------------------------------------------------------------

void SensorStatesController::OnTick()
{
	hasChangedSensorValues = 0;

	for (uint8_t i = 0; i < _sensorsCount; i++)
	{
		sensorsPtrArray[i]->OnTick();
		uint8_t sensorState = sensorsPtrArray[i]->IsSignaled();

		if (sensorState != handeledSensorsStates[i])
			hasChangedSensorValues |= 1;
	}
}
//---------------------------------------------------------------------------

uint8_t SensorStatesController::IsChanged(TwoStateSensor* sensotToCheckPtr, uint8_t & newValue)
{
	for (uint8_t i = 0; i < _sensorsCount; i++)
	{
		if (sensorsPtrArray[i] == sensotToCheckPtr)
		{
			newValue = sensorsPtrArray[i]->IsSignaled();

			if (handeledSensorsStates[i] != newValue)
			{				
				return 1;
			}
			else			
				return 0;
		}
	}
}
//---------------------------------------------------------------------------

uint8_t SensorStatesController::HasChangedSensorValues()
{
	return hasChangedSensorValues;
}
//---------------------------------------------------------------------------

void SensorStatesController::HandleAllSensors()
{
	for (uint8_t i = 0; i < _sensorsCount; i++)
	{
		handeledSensorsStates[i] = sensorsPtrArray[i]->IsSignaled();
	}
}
//---------------------------------------------------------------------------
