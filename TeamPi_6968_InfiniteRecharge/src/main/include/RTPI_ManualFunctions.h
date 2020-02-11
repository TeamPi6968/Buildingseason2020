#pragma once

#include "RobotIO.h"
#include "RTPI_ControllerInput.h"
#include "RTPI_Drivetrain.h"
#include "RTPI_Intake.h"
#include "RTPI_Storage.h"
#include "RTPI_Outtake.h"

using namespace frc;

class RTPI_ManualFunctions {
 private:
  RobotIO *robotIO;
  RTPI_ControllerInput *input;
  RTPI_Drivetrain *drivetrain;
  RTPI_Intake *intake;
  RTPI_Storage *storage;
  RTPI_Outtake *outtake;

 public:
  RTPI_ManualFunctions(RobotIO *_robotIO, RTPI_ControllerInput *_input, RTPI_Drivetrain *_drivetrain, RTPI_Intake *_intake, RTPI_Storage *_storage, RTPI_Outtake *_outtake);
  void DriveRL(); //Drive like Rocket League
  void DriveFPS(); //Drive like First Person Shooter
  void ManualDrive(); //Manual Drive the robot in selected mode
  void UpdateDriveMode(); //Updates Drive Mode
  void ManualIntake(); //Checks if the intake needs to be activated, and activates intake
  void ManualRevolver();
  void ManualLoading();
  void ManualShooting(double shootingspeed);
};