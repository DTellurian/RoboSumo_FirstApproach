// 
// 
// 

#include "ModeBorderRotation.h"
#include "OnboardHardware.h"
//---------------------------------------------------------------------------

ModeBorderRotation::ModeBorderRotation()
{
}
//---------------------------------------------------------------------------

void ModeBorderRotation::OnTick()
{
	Serial.println("ModeBorderRotation::OnTick()");
}
//---------------------------------------------------------------------------

void ModeBorderRotation::OnEnterMode()
{
	OnboardHardware::movementManager.ClearQueue();
	Serial.println("ModeBorderRotation::OnEnterMode()");
}
//---------------------------------------------------------------------------