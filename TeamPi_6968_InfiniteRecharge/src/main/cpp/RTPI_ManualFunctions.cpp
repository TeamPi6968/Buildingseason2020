#include "RTPI_ManualFunctions.h"

RTPI_ManualFunctions::RTPI_ManualFunctions(RTPI_Drivetrain *drivetrainF, RTPI_ControllerInput *inputF) {
  drivetrain = drivetrainF;
  input = inputF;
}

void RTPI_ManualFunctions::ManualMovement(double driveForward, double driveBackward){
  double driveSpeed = 0 + driveForward - driveBackward;
  drivetrain->Drive(driveSpeed, input->driver->GetRawAxis(0));
}