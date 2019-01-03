// 
// 
// 

#include "OnboardHardware.h"
//---------------------------------------------------------------------------

EngineDriver OnboardHardware::leftEngine(12, 11, 10);
EngineDriver OnboardHardware::rightEngine(7, 8, 9);

SensorTCRT5000 OnboardHardware::leftSensorTCRT5000(15, 400);
SensorTCRT5000 OnboardHardware::rightSensorTCRT5000(14, 400);

DigitalInputSensor OnboardHardware::leftIRForwardSensor(3, 0);
DigitalInputSensor OnboardHardware::rightIRForwardSensor(4, 0);

MovementManager OnboardHardware::movementManager(&OnboardHardware::leftEngine, &OnboardHardware::rightEngine);
SensorStatesController OnboardHardware::sensorStatesController;
//---------------------------------------------------------------------------

