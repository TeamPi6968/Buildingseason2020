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
  this->mFunctions = new RTPI_ManualFunctions(robotIO, input, drivetrain, intake, storage, outtake, controlPanel);
  this->aFunctions = new RTPI_AutoFunctions(robotIO, input, drivetrain, intake, storage, outtake);
}

void Robot::RobotPeriodic() {

}

void Robot::AutonomousInit() {
  
}

void Robot::AutonomousPeriodic() {
  
}

void Robot::TeleopInit() {
  intake->ResetIntake();
  controlPanel->ColourMatcher();
  }

void Robot::TeleopPeriodic() {
//Manual Functions -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//if(!robotIO->autoFunction) {
  //MANUALDRIVE:
    //Update Drive Mode
      mFunctions->UpdateDriveMode();
    //Apply Drive Mode
      mFunctions->ManualDrive();
  //END MANUALDRIVE

  //MANUALINTAKE:
    //Activate Intake if navigator uses Y-Dir. left joystick
      mFunctions->ManualIntake();
  //END MANUALINTAKE

  //MANUALSTORAGE:
    //Rotate Storage Revolver if navigator uses X-Dir. left joystick + Click left joystick
      mFunctions->ManualRevolver();
    //Spin Storage Loader if navigator uses ...
      mFunctions->ManualLoading();
  //END MANUALSTORAGE

  //MANUALSHOOTING:
    //Activate Outtake shooter if navigator's "x" button is pressed
      mFunctions->ManualShooting();

  //MANUALCONTROLPANEL
    //Activate Controlpanel if navigator's "B" button is pressed
      mFunctions->ManualCP();
//}
//End Manual Functions -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

//Autonomous Functions -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

  //Non Stopable Auto Functions:
    //AUTO STORAGE
      //Move Storage 1/5 (1 slot)
        //aFunctions->moveStorageFifth();

  //Stopable Auto Functions: (Functions stops when BACK Button is pressed on Driver or Navigator Controller)
    
//End Autonomous Functions -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
}

void Robot::TestPeriodic() {

}

//====================================SETUPS======================================//

void Robot::MotorControllerSetup() {
  //Drivetrain Motorcontrollers:
    this->sparkDrivetrainLF = new RTPI_SparkMax(robotIO->drivetrainLFMotorType, robotIO->canDrivetrainLF, robotIO->accDrivetrain, robotIO->drivetrainLFInverted, robotIO->drivetrainLFEncoder, false);
    this->sparkDrivetrainLB = new RTPI_SparkMax(robotIO->drivetrainLBMotorType, robotIO->canDrivetrainLB, robotIO->accDrivetrain, robotIO->drivetrainLBInverted, robotIO->drivetrainLBEncoder, false);
    this->sparkDrivetrainRB = new RTPI_SparkMax(robotIO->drivetrainRBMotorType, robotIO->canDrivetrainRB, robotIO->accDrivetrain, robotIO->drivetrainRBInverted, robotIO->drivetrainRBEncoder, false);
    this->sparkDrivetrainRF = new RTPI_SparkMax(robotIO->drivetrainRFMotorType, robotIO->canDrivetrainRF, robotIO->accDrivetrain, robotIO->drivetrainRFInverted, robotIO->drivetrainRFEncoder, false);

  //Intake Motorcontroller:
    this->victorIntakeCylinder = new RTPI_VictorSPX(robotIO->canIntakeCylinder, robotIO->accIntakeCylinder, robotIO->intakeCylinderInverted);

  //Storage Motorcontrollers:
    this->sparkStorageRevolver = new RTPI_SparkMax(robotIO->storageRevolverMotorType, robotIO->canStorageRevolver, robotIO->accStorageRevolver, robotIO->storageRevolverInverted, robotIO->storageRevolverEncoder, true);
    this->sparkStorageLoader = new RTPI_SparkMax(robotIO->storageLoaderMotorType, robotIO->canStorageLoader, robotIO->accStorageLoader, robotIO->storageLoaderInverted, robotIO->storageLoaderEncoder, false);

  //Outtake Motorcontrollers:
    this->sparkOuttakeUW = new RTPI_SparkMax(robotIO->outtakeUWMotorType, robotIO->canOuttakeUW, robotIO->accOuttake, robotIO->outtakeUWInverted, robotIO->outtakeUWEncoder, false);
    this->sparkOuttakeDW = new RTPI_SparkMax(robotIO->outtakeDWMotorType, robotIO->canOuttakeDW, robotIO->accOuttake, robotIO->outtakeDWInverted, robotIO->outtakeDWEncoder, false);

  //Control Panel Motorcontroller:
    this->sparkCPWheels = new RTPI_SparkMax(robotIO->CPWheelsMotorType, robotIO->canCPWheels, robotIO->accCPWheels, robotIO->CPWheelsInverted, robotIO->CPWheelsEncoder, false);
}

void Robot::ModuleSetup() {
  this->drivetrain = new RTPI_Drivetrain(sparkDrivetrainLF, sparkDrivetrainLB, sparkDrivetrainRB, sparkDrivetrainRF);
  this->intake = new RTPI_Intake(victorIntakeCylinder, intakeLRPiston);
  this->storage = new RTPI_Storage(sparkStorageRevolver, sparkStorageLoader);
  this->outtake = new RTPI_Outtake(sparkOuttakeUW, sparkOuttakeDW);
  this->controlPanel = new RTPI_ControlPanel(sparkCPWheels);
}

void Robot::PneumaticSetup() {
  this->compressor = new RTPI_Pneumatics(robotIO->canPCM);
  this->intakeLRPiston = new RTPI_Pneumatics(robotIO->canPCM, robotIO->intakeLRPortForward, robotIO->intakeLRPortReverse);
  this->cpPiston = new RTPI_Pneumatics(robotIO->canPCM, robotIO->cpPortForward, robotIO->cpPortReverse);
}

//====================================END=========================================//

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif