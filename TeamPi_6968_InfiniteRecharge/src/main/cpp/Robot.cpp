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
  //Drivetrain Motorcontrollers:
  this->sparkDrivetrainLF = new RTPI_SparkMax(true, canDrivetrainLF, 1, false);
  this->sparkDrivetrainLB = new RTPI_SparkMax(true, canDrivetrainLB, 1, false);
  this->sparkDrivetrainRB = new RTPI_SparkMax(true, canDrivetrainRB, 1, true);
  this->sparkDrivetrainRF = new RTPI_SparkMax(true, canDrivetrainRF, 1, true);
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

}

void Robot::TestPeriodic() {

}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
