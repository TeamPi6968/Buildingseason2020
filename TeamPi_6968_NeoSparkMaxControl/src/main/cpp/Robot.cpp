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
  //First parameter: CANID
  //Second: Ramp
  //Third: Inverted?
  this->sparkTest = new RTPI_SparkMax(1, 5, false);
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
  this->sparkTest->GetSparkMax()->Set(0.5);
}

void Robot::TestPeriodic() {

}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
