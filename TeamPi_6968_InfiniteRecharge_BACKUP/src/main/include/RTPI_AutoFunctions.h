/*
-   Created By: Jesper Weijnen
-   Date: 11/02/2020
-   Time: 13:57
-   Class: RTPI_AutoFunctions
*/

#pragma once

#include "RobotIO.h"
#include "RTPI_ControllerInput.h"
#include "RTPI_Drivetrain.h"
#include "RTPI_Intake.h"
#include "RTPI_Storage.h"
#include "RTPI_Outtake.h"

class RTPI_AutoFunctions {
 private:
  RobotIO *robotIO;
  RTPI_ControllerInput *input;
  RTPI_Drivetrain *drivetrain;
  RTPI_Intake *intake;
  RTPI_Storage *storage;
  RTPI_Outtake *outtake;
  bool stopAutoFunction(); //Safety Button
 public:
  RTPI_AutoFunctions(RobotIO *_robotIO, RTPI_ControllerInput *_input, RTPI_Drivetrain *_drivetrain, RTPI_Intake *_intake, RTPI_Storage *_storage, RTPI_Outtake *_outtake);
  void moveStorageFifth();
  void AutomaticShooting();
};