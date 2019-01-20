// 
// 
// 

#include "OnboardHardware.h"
//---------------------------------------------------------------------------

EngineDriver OnboardHardware::rightEngine(12, 11, 10);
EngineDriver OnboardHardware::leftEngine(7, 8, 9);

SensorTCRT5000 OnboardHardware::leftSensorTCRT5000(15, 400, 400);//615 on white, 70 on dark
SensorTCRT5000 OnboardHardware::rightSensorTCRT5000(14, 400, 400);

SensorTCRT5000 OnboardHardware::rightWheelSensorTCRT5000(18, 400, 200);//770 on white, 70 on dark
SensorTCRT5000 OnboardHardware::leftWheelSensorTCRT5000(19, 400, 200);//770 on white, 70 on dark

DigitalInputSensor OnboardHardware::leftIRForwardSensor(3, 0);
DigitalInputSensor OnboardHardware::rightIRForwardSensor(4, 0);

SensorStatesController OnboardHardware::sensorStatesController(4);
SensorStatesController OnboardHardware::wheelsSensorsStatesController(2);

MovementManager OnboardHardware::movementManager(&OnboardHardware::leftEngine, &OnboardHardware::rightEngine, &OnboardHardware::rightWheelSensorTCRT5000, &OnboardHardware::wheelsSensorsStatesController);

//---------------------------------------------------------------------------

void OnboardHardware::Initialize()
{
	OnboardHardware::sensorStatesController.sensorsPtrArray[0] = &OnboardHardware::leftSensorTCRT5000;
	OnboardHardware::sensorStatesController.sensorsPtrArray[1] = &OnboardHardware::rightSensorTCRT5000;
	OnboardHardware::sensorStatesController.sensorsPtrArray[2] = &OnboardHardware::leftIRForwardSensor;
	OnboardHardware::sensorStatesController.sensorsPtrArray[3] = &OnboardHardware::rightIRForwardSensor;

	OnboardHardware::wheelsSensorsStatesController.sensorsPtrArray[0] = &OnboardHardware::rightWheelSensorTCRT5000;
	OnboardHardware::wheelsSensorsStatesController.sensorsPtrArray[1] = &OnboardHardware::leftWheelSensorTCRT5000;
}
//---------------------------------------------------------------------------