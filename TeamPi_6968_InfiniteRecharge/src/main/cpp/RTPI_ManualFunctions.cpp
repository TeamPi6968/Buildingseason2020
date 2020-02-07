#include "RTPI_ManualFunctions.h"

RTPI_ManualFunctions::RTPI_ManualFunctions(RobotIO *robotIOF, RTPI_Drivetrain *drivetrainF, RTPI_ControllerInput *inputF) {
  robotIO = robotIOF;
  drivetrain = drivetrainF;
  input = inputF;
}

void RTPI_ManualFunctions::DriveRL() {
  drivetrain->Drive(input->driver->GetRawAxis(3) - input->driver->GetRawAxis(2), input->driver->GetRawAxis(0));
}

void RTPI_ManualFunctions::DriveFPS() {
  drivetrain->Drive(input->driver->GetRawAxis(1), input->driver->GetRawAxis(4));
}

void RTPI_ManualFunctions::ManualDrive() {
  if(robotIO->driveMode == ROCKET_LEAGUE_DRIVE) {
    this->DriveRL();
  }
  else if(robotIO->driveMode == FIRST_PERSON_SHOOTER_DRIVE) {
    this->DriveFPS();
  }
}

void RTPI_ManualFunctions::UpdateDriveMode() {
  if(input->driverPOVLeft->Get()) {
    robotIO->driveMode = ROCKET_LEAGUE_DRIVE;
  }
  else if(input->driverPOVRight->Get())  {
    robotIO->driveMode = FIRST_PERSON_SHOOTER_DRIVE;
  }
}