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
    frc::CameraServer::GetInstance()->StartAutomaticCapture();
    //frc::CameraServer::GetInstance()->writeRotation()
    this->input = new RTPI_ControllerInput(0,1);
    this->masterL = new RTPI_Talon(1);
    this->slaveL = new RTPI_Talon(3);
    this->masterR = new RTPI_Talon(2);
    this->slaveR = new RTPI_Talon(4);
    this->climbTalon = new RTPI_Talon(5);
    this->liftTalon = new RTPI_Talon(6);
    this->controlTalon = new RTPI_Talon(7);
    this->servoRight = new RTPI_Servo(1);
    this->climbing = new RTPI_Climbing(climbTalon, liftTalon);
    this->drivetrain = new RTPI_Drivetrain(masterL, slaveL, masterR, slaveR);
    this->function = new RTPI_Functions(drivetrain, input, climbing, servoRight);
    this->timerAutoBaseline = new Timer();
    this->timerMoveServos = new Timer();

    function->initStorage(29);

    this->test = new RTPI_Test();

    test->testf1();
}

void Robot::RobotPeriodic() {
    //function->initStorage(30);
}

void Robot::AutonomousInit() {
    timerAutoBaseline->Reset();
    timerAutoBaseline->Start();

    function->initStorage(29);
}

void Robot::AutonomousPeriodic() {
    function->initStorage(29);
    if(timerAutoBaseline->Get()<1.5){
        function->Drive(0.5, 0);
    }
}

void Robot::TeleopInit() {
    function->initStorage(29);
    timerMoveServos->Reset();
    timerMoveServos->Start();
}

void Robot::TeleopPeriodic() {
    //Normal TeleOp mode
    if(!input->navigator->GetRawButton(8)) {
        function->DriveRL();
        function->Climber(4, 1);
        function->Lifter(2, 3);
        function->ControlPanel();
        function->MoveStorage(timerMoveServos->Get());
    }
    //Climbing System Config/Setup
    else {
        function->Climber(4, 1);
        function->Lifter(2, 3);
    }
}

void Robot::TestPeriodic() {
}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
