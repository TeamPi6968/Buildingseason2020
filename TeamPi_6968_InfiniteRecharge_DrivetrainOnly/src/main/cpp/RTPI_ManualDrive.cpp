#include "RTPI_ManualDrive.h"

RTPI_ManualDrive::RTPI_ManualDrive(RTPI_Drivetrain *drivetrainF, RTPI_ControllerInput *inputF) {
  drivetrain = drivetrainF;
  input = inputF;
}

void RTPI_ManualDrive::ManualMovement(double driveForward, double driveBackward){
    double driveSpeed = 0 + driveForward - driveBackward;

    drivetrain->Drive(driveSpeed, input->driver->GetRawAxis(0));
}