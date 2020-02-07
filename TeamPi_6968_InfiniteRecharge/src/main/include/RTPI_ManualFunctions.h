#pragma once

#include "RobotIO.h"
#include "RTPI_Drivetrain.h"
#include "RTPI_ControllerInput.h"

using namespace frc;

class RTPI_ManualFunctions {
 private:
  RobotIO *robotIO;
  RTPI_ControllerInput *input;
  RTPI_Drivetrain *drivetrain;

 public:
  RTPI_ManualFunctions(RobotIO *robotIOF, RTPI_Drivetrain *drivetrainF, RTPI_ControllerInput *inputF);
  void DriveRL(); //Drive like Rocket League
  void DriveFPS(); //Drive like First Person Shooter
  void ManualDrive(); //Manual Drive the robot in selected mode
  void UpdateDriveMode(); //Updates Drive Mode
};