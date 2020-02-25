#include "RTPI_ManualFunctions.h"

RTPI_ManualFunctions::RTPI_ManualFunctions(RobotIO *_robotIO, RTPI_ControllerInput *_input, RTPI_Drivetrain *_drivetrain, RTPI_Intake *_intake, RTPI_Storage *_storage, RTPI_Outtake *_outtake, RTPI_ControlPanel *_controlPanel) {
  this->robotIO = _robotIO;
  this->input = _input;
  this->drivetrain = _drivetrain;
  this->intake = _intake;
  this->storage = _storage;
  this->outtake = _outtake;
  this->controlPanel = _controlPanel;

  SmartDashboard::PutNumber("uwSpeed", 0);
  SmartDashboard::PutNumber("dwSpeed", 0);
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
  //Spin Cylinder
  if(input->navigator->GetRawButton(5)) {
    this->intake->SpinIntake(robotIO->intakeSpeed);
  }
  else if (input->navigator->GetRawButton(6)) {
    this->intake->SpinIntake(-robotIO->intakeSpeed);
  }
  else {
    this->intake->SpinIntake(0);
  }

  //Move Intake Piston
  //Change State Detection

  robotIO->intakeBState0 = input->navigatorPOVLeft->Get();

  if(robotIO->intakeBState0 != robotIO->lastIntakeBState0) {
    if(robotIO->intakeBState0) {
      if(!robotIO->intakePState0) {
        this->intake->movePiston(DoubleSolenoid::Value::kForward);
        robotIO->intakePState0 = 1;
      }
      else if(robotIO->intakePState0) {
        this->intake->movePiston(DoubleSolenoid::Value::kReverse);
        robotIO->intakePState0 = 0;
      }
    }
    robotIO->lastIntakeBState0 = robotIO->intakeBState0;
  }
}

//Outtake:

void RTPI_ManualFunctions::ManualShooting() {
  double shootForward = input->navigator->GetRawAxis(3);
  double shootBackward = input->navigator->GetRawAxis(2);
  double shoot = 0 + shootForward - shootBackward;
  this->outtake->Shoot(shoot);
}

void RTPI_ManualFunctions::ManualDiffShooting() {
  this->outtake->DiffSpeedShoot(
    SmartDashboard::GetNumber("uwSpeed", 0),
    SmartDashboard::GetNumber("dwSpeed", 0)
  );
}

//Storage:

void RTPI_ManualFunctions::ManualRevolver() {
  if(!robotIO->cpManualMode) {
    this->storage->SpinRevolver(input->navigator->GetRawAxis(0));
  }
}

void RTPI_ManualFunctions::ManualLoading() {
  this->storage->SpinLoader(input->navigator->GetRawAxis(5));
}

// ControlPanel

void RTPI_ManualFunctions::ManualCP() {
  if(input->navigator->GetRawButton(1)) {
    this->controlPanel->spinCPWheels(input->navigator->GetRawAxis(1));
  }
  //Change State Detection
  robotIO->cpBState0 = input->navigatorPOVRight->Get();

  if(robotIO->cpBState0 != robotIO->lastCPBState0) {
    if(robotIO->cpBState0) {
      if(!robotIO->cpPState0) {
        this->controlPanel->moveCPPiston(DoubleSolenoid::Value::kForward);
        robotIO->cpManualMode = true;
        robotIO->cpPState0 = 1;
      }
      else if(robotIO->cpPState0) {
        this->controlPanel->moveCPPiston(DoubleSolenoid::Value::kReverse);
        robotIO->cpManualMode = false;
        robotIO->cpPState0 = 0;
      }
    }
    robotIO->lastCPBState0 = robotIO->cpBState0;
  }

  if(robotIO->cpManualMode) {
    this->controlPanel->spinCPWheels(input->navigator->GetRawAxis(0));
    this->controlPanel->ColorCounter();
  }
}