/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

//====================================INCLUDES====================================//

#include "Robot.h"

#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>

//====================================MAINPROGRAM=================================//

void Robot::RobotInit() {
  this->robotIO = new RobotIO();
  MotorControllerSetup();
  PneumaticSetup();
  this->input = new RTPI_ControllerInput(0,1);
  ModuleSetup();
  this->mFunctions = new RTPI_ManualFunctions(robotIO, input, drivetrain, intake, storage, outtake);
}

void Robot::RobotPeriodic() {

}

void Robot::AutonomousInit() {
  
}

void Robot::AutonomousPeriodic() {
  
}

void Robot::TeleopInit() {
  intake->ResetIntake();
}

void Robot::TeleopPeriodic() {
  //MANUALDRIVE:
    //Update Drive Mode
      mFunctions->UpdateDriveMode();
    //Apply Drive Mode
      mFunctions->ManualDrive();
  //END MANUALDRIVE

  //MANUALINTAKE:
    //Activate Intake if navigator uses Y-Dir. left joystick
      mFunctions->ManualIntake();
      //this->intakeLRPiston->GetDoubleSolenoid()->Set(DoubleSolenoid::Value::kForward);
  //END MANUALINTAKE

  //MANUALSTORAGE:
    //Rotate Storage Revolver if navigator uses X-Dir. left joystick + Click left joystick
      //mFunctions->ManualRevolver();
    //Spin Storage Loader if navigator uses ...
      //mFunctions->ManualLoading();
  //END MANUALSTORAGE

  //MANUALSHOOTING:
    //Activate Outtake shooter if navigator's "x" button is pressed
      mFunctions->ManualShooting(1);
}

void Robot::TestPeriodic() {

}

//====================================SETUPS======================================//

void Robot::MotorControllerSetup() {
  //Drivetrain Motorcontrollers:
    this->sparkDrivetrainLF = new RTPI_SparkMax(true, robotIO->canDrivetrainLF, robotIO->accDrivetrain, false);
    this->sparkDrivetrainLB = new RTPI_SparkMax(true, robotIO->canDrivetrainLB, robotIO->accDrivetrain, false);
    this->sparkDrivetrainRB = new RTPI_SparkMax(true, robotIO->canDrivetrainRB, robotIO->accDrivetrain, true);
    this->sparkDrivetrainRF = new RTPI_SparkMax(true, robotIO->canDrivetrainRF, robotIO->accDrivetrain, true);

  //Intake Motorcontroller:
    this->victorIntakeCylinder = new RTPI_VictorSPX(robotIO->canIntakeCylinder, robotIO->accIntakeCylinder, false);

  //Storage Motorcontrollers:
    this->sparkStorageRevolver = new RTPI_SparkMax(true, robotIO->canStorageRevolver, robotIO->accStorageRevolver, false);
    this->sparkStorageLoader = new RTPI_SparkMax(true, robotIO->canStorageLoader, robotIO->accStorageLoader, false);

  //Outtake Motorcontrollers:
    this->sparkOuttakeUW = new RTPI_SparkMax(false, robotIO->canOuttakeUW, robotIO->accOuttake, false);
    this->sparkOuttakeDW = new RTPI_SparkMax(false, robotIO->canOuttakeDW, robotIO->accOuttake, false);

  //Control Panel Motorcontroller:
    this->sparkCPWheels = new RTPI_SparkMax(true, robotIO->canCPWheels, robotIO->accCPWheels, false);
}

void Robot::ModuleSetup() {
  this->drivetrain = new RTPI_Drivetrain(sparkDrivetrainLF, sparkDrivetrainLB, sparkDrivetrainRB, sparkDrivetrainRF);
  this->intake = new RTPI_Intake(victorIntakeCylinder, intakeLRPiston);
  this->storage = new RTPI_Storage(sparkStorageRevolver, sparkStorageLoader);
  this->outtake = new RTPI_Outtake(sparkOuttakeUW, sparkOuttakeDW);
}

void Robot::PneumaticSetup() {
  this->compressor = new RTPI_Pneumatics(robotIO->canPCM);
  this->intakeLRPiston = new RTPI_Pneumatics(robotIO->canPCM, robotIO->intakeLRPortForward, robotIO->intakeLRPortReverse);
  this->cpPiston = new RTPI_Pneumatics(robotIO->canPCM, robotIO->cpPortForward, robotIO->cpPortReverse);
}

//====================================END=========================================//holla

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
