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
    this->Input = new RTPI_ControllerInput(0,1);
    this->MasterL = new RTPI_Talon(1);
    this->SlaveL = new RTPI_Talon(3);
    this->MasterR = new RTPI_Talon(2);
    this->SlaveR = new RTPI_Talon(4);
    this->climbTalon = new RTPI_Talon(5);
    this->controlTalon = new RTPI_Talon(7);
    this->climbing = new RTPI_Climbing(climbTalon);
    this->drivetrain = new RTPI_Drivetrain(MasterL, SlaveL, MasterR, SlaveR);
    this->function = new RTPI_Functions(drivetrain, Input, climbing);
    this->servo = new RTPI_Servo(1);
    this->timer = new Timer();
}

void Robot::RobotPeriodic() {
}

void Robot::AutonomousInit() {
    timer->Reset();
    timer->Start();
}

void Robot::AutonomousPeriodic() {
    if(timer->Get()<2){
    function->AutoDrive();
    }
}

void Robot::TeleopInit() {
}

void Robot::TeleopPeriodic() {
    function->DriveRL();
    function->Climbe();
    function->ControlPanel();
}

void Robot::TestPeriodic() {
}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
