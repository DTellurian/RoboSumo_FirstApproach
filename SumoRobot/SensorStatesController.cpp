// 
// 
// 

#include "SensorStatesController.h"
#include "OnboardHardware.h"
//---------------------------------------------------------------------------

//SensorStatesController sensorStatesController;
//---------------------------------------------------------------------------

SensorStatesController::SensorStatesController()
{
	sensorsPtrArray[0] = &OnboardHardware::leftSensorTCRT5000;
	sensorsPtrArray[1] = &OnboardHardware::rightSensorTCRT5000;
	sensorsPtrArray[2] = &OnboardHardware::leftIRForwardSensor;
	sensorsPtrArray[3] = &OnboardHardware::rightIRForwardSensor;
}
//---------------------------------------------------------------------------

void SensorStatesController::OnTick()
{
	hasChangedSensorValues = 0;

	for (uint8_t i = 0; i < SENSORS_COUNT; i++)
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
	for (uint8_t i = 0; i < SENSORS_COUNT; i++)
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
	for (uint8_t i = 0; i < SENSORS_COUNT; i++)
	{
		handeledSensorsStates[i] = sensorsPtrArray[i]->IsSignaled();
	}
}
//---------------------------------------------------------------------------
