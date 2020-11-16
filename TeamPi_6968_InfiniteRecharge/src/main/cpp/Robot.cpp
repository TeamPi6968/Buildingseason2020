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
  EncoderSetup();
  PneumaticSetup();
  SensorSetup();
  this->input = new RTPI_ControllerInput(0, 1);
  ModuleSetup();
  this->mFunctions = new RTPI_ManualFunctions(robotIO, input, drivetrain, intake, storage, outtake, controlPanel);
  this->aFunctions = new RTPI_AutoFunctions(robotIO, input, drivetrain, intake, storage, outtake);
  this->driveAwayTimer = new Timer();
  

  // PID course add
  IMU_CAN_ID = 1;
  this->IMU = new RTPI_IMU(IMU_CAN_ID);
}

void Robot::RobotPeriodic() {

}

void Robot::AutonomousInit() {
  driveAwayTimer->Reset();
  driveAwayTimer->Start();
  double kP_cam = 1;
  double kI_cam = 0.1;
  double kD_cam = 0; 
  double Setpoint_cam = 200;
  double measured_cam;
  double absolute_tolerance_cam = 5;
  double derivative_tolerance_cam =10; 
  double integratorRange_cam = 50;
  double clamp_cam = 5676; //NEO max speed in RPM
  this->PID_course_cam = new PIDController(kP_cam, kI_cam, kD_cam);
  PID_course_cam->SetTolerances(absolute_tolerance_cam, derivative_tolerance_cam);
  PID_course_cam->SetIntegratorRange(-integratorRange, integratorRange)
}

void Robot::AutonomousPeriodic() {
  bool PIControl_course = 1;
  
  if PIControl_course == 1){
    if (this->input->driverPOVUp->Get()){ // when up POV of driver is presed set Start PID
      double Rot_speed_pid = PID_course_cam->SetEnable();
      double cam_data = 1; // input of camera
      Rot_speed_pid = PID_course_cam->Calculate(cam_data,this->Setpoint_cam)
      this->aFunctions->drivetrain->Drive(0,Rot_speed_pid);
    }
    if (this->input->driverPOVDown->get()) {// when down POV of dirver is pressed cancel PID
      double Rot_speed_pid = PID_course_cam->SetDisable();
      this->aFunctions->drivetrain->Drive(0,0);
    }
  }
  else{
    if(driveAwayTimer->Get() < 2) {
      drivetrain->Drive(0.7, 0);
      // nice place for pi PID. 
      IMU->getPigeon();
    }    
  }

}

void Robot::TeleopInit() {
  intake->ResetIntake();
}

void Robot::TeleopPeriodic() {
//update the odometry
//drivetrain->periodic();

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
        aFunctions->moveStorageFifth();
        SmartDashboard::PutNumber("Storage Position", this->sparkStorageRevolver->GetSparkMaxEncoder()->GetPosition());
    //AUTO OUTTAKE
      //Shooting Automatic without auto Aiming
        aFunctions->shootAutomatic();
      

        
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

void Robot::EncoderSetup() {
  this->drivetrainEncoderL = new RTPI_DutyCycleEncoder(robotIO->drivetrainEncChannelL, robotIO->drivetrainWheelPerimeter);
  this->drivetrainEncoderR = new RTPI_DutyCycleEncoder(robotIO->drivetrainEncChannelR, robotIO->drivetrainWheelPerimeter);
}

void Robot::PneumaticSetup() {
  this->compressor = new RTPI_Pneumatics(robotIO->canPCM);
  this->intakeLRPiston = new RTPI_Pneumatics(robotIO->canPCM, robotIO->intakeLRPortForward, robotIO->intakeLRPortReverse);
  this->cpPiston = new RTPI_Pneumatics(robotIO->canPCM, robotIO->cpPortForward, robotIO->cpPortReverse);
}

void Robot::SensorSetup() {
  this->imu = new RTPI_IMU(robotIO->canPigeon);
  this->colorSensorCP = new RTPI_ColorSensor(robotIO->portColorSensorCP);
}

void Robot::ModuleSetup() {
  this->drivetrain = new RTPI_Drivetrain(sparkDrivetrainLF, sparkDrivetrainLB, sparkDrivetrainRB, sparkDrivetrainRF,imu);
  this->intake = new RTPI_Intake(victorIntakeCylinder, intakeLRPiston);
  this->storage = new RTPI_Storage(sparkStorageRevolver, sparkStorageLoader);
  this->outtake = new RTPI_Outtake(sparkOuttakeUW, sparkOuttakeDW, sparkStorageLoader);
  this->controlPanel = new RTPI_ControlPanel(sparkCPWheels, colorSensorCP, cpPiston);
}

//====================================END=========================================//

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif