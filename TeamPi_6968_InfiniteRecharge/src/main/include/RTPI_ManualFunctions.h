#pragma once

#include "RobotIO.h"
#include "RTPI_ControllerInput.h"
#include "RTPI_Drivetrain.h"
#include "RTPI_Intake.h"

using namespace frc;

class RTPI_ManualFunctions {
 private:
  RobotIO *robotIO;
  RTPI_ControllerInput *input;
  RTPI_Drivetrain *drivetrain;
  RTPI_Intake *intake;

 public:
  RTPI_ManualFunctions(RobotIO *_robotIO, RTPI_ControllerInput *_input, RTPI_Drivetrain *_drivetrain, RTPI_Intake *_intake);
  void DriveRL(); //Drive like Rocket League
  void DriveFPS(); //Drive like First Person Shooter
  void ManualDrive(); //Manual Drive the robot in selected mode
  void UpdateDriveMode(); //Updates Drive Mode
  void ManualIntake(); //Checks if the intake needs to be activated, and activates intake
};