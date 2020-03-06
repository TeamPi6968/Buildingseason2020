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
  MotorControllerSetup();
  this->drivetrain = new RTPI_Drivetrain(sparkDrivetrainLF, sparkDrivetrainLB, sparkDrivetrainRB, sparkDrivetrainRF);
  this->input = new RTPI_ControllerInput(0,1);
  this->MDrive = new RTPI_ManualDrive(drivetrain, input);
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
  //drivetrain->Drive(input->driver->GetRawAxis(1), input->driver->GetRawAxis(2));
  MDrive->ManualMovement(input->driver->GetRawAxis(3), input->driver->GetRawAxis(2));
}

void Robot::TestPeriodic() {

}

void Robot::MotorControllerSetup() {
  //Drivetrain Motorcontrollers:
    this->sparkDrivetrainLF = new RTPI_SparkMax(true, canDrivetrainLF, 1, false);
    this->sparkDrivetrainLB = new RTPI_SparkMax(true, canDrivetrainLB, 1, false);
    this->sparkDrivetrainRB = new RTPI_SparkMax(true, canDrivetrainRB, 1, true);
    this->sparkDrivetrainRF = new RTPI_SparkMax(true, canDrivetrainRF, 1, true);
}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
