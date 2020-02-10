#include "RTPI_ManualFunctions.h"

RTPI_ManualFunctions::RTPI_ManualFunctions(RobotIO *_robotIO, RTPI_ControllerInput *_input, RTPI_Drivetrain *_drivetrain, RTPI_Intake *_intake, RTPI_Storage *_storage) {
  this->robotIO = _robotIO;
  this->input = _input;
  this->drivetrain = _drivetrain;
  this->intake = _intake;
  this->storage = _storage;
}

//Drivetrain

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

//Intake:

void RTPI_ManualFunctions::ManualIntake() {
  if(input->navigatorPOVUp->Get()) {
    this->intake->SpinIntake(input->navigator->GetRawAxis(robotIO->intakeSpeed));
  }
  else if (input->navigatorPOVDown->Get()) {
    this->intake->SpinIntake(input->navigator->GetRawAxis(-robotIO->intakeSpeed));
  }
  else {
    this->intake->SpinIntake(0);
  }
}

//Storage:

void RTPI_ManualFunctions::ManualRevolver() {
  if(input->navigator->GetRawButton(9)) {
    this->storage->SpinRevolver(input->navigator->GetRawAxis(0));
  }
  else {
    this->storage->SpinRevolver(0);
  }
}

void RTPI_ManualFunctions::ManualLoading() {
  this->storage->SpinLoader(0);
}