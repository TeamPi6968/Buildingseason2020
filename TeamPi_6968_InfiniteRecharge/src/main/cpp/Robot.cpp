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
  this->sparkLeftFront = new RTPI_SparkMax(drivetrainLeftFrontID, 5, true);
  this->sparkLeftBack = new RTPI_SparkMax(drivetrainLeftBackID, 5, true);
  this->sparkRightBack = new RTPI_SparkMax(drivetrainRightBackID, 5, false);
  this->sparkRightFront = new RTPI_SparkMax(drivetrainRightFrontID, 5, false);
  //--------------------------------------------------------------------------
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
