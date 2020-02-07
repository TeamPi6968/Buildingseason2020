/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit() {
  this->robotIO = new RobotIO();
  MotorControllerSetup();
  this->drivetrain = new RTPI_Drivetrain(sparkDrivetrainLF, sparkDrivetrainLB, sparkDrivetrainRB, sparkDrivetrainRF);
  this->input = new RTPI_ControllerInput(0,1);
  this->mFunctions = new RTPI_ManualFunctions(robotIO, drivetrain, input);
}

void Robot::RobotPeriodic() {

}

void Robot::AutonomousInit() {
  
}

void Robot::AutonomousPeriodic() {
  
}

void Robot::TeleopInit() {

}

void Robot::TeleopPeriodic() {
  //MANUALDRIVE:
    //Update Drive Mode
    mFunctions->UpdateDriveMode();
    //Apply Drive Mode
    mFunctions->ManualDrive();
  //END MANUALDRIVE
}

void Robot::TestPeriodic() {

}

void Robot::MotorControllerSetup() {
  //Drivetrain Motorcontrollers:
    this->sparkDrivetrainLF = new RTPI_SparkMax(true, robotIO->canDrivetrainLF, 1, false);
    this->sparkDrivetrainLB = new RTPI_SparkMax(true, robotIO->canDrivetrainLB, 1, false);
    this->sparkDrivetrainRB = new RTPI_SparkMax(true, robotIO->canDrivetrainRB, 1, true);
    this->sparkDrivetrainRF = new RTPI_SparkMax(true, robotIO->canDrivetrainRF, 1, true);
}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
