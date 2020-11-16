/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

//Pre-Written libraries
#include <string>
#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/Timer.h>
#include <PIDController.h>

//Selfmade libraries
#include "RobotIO.h"
#include "RTPI_SparkMax.h"
#include "RTPI_VictorSPX.h"
#include "RTPI_Pneumatics.h"
#include "RTPI_ColorSensor.h"
#include "RTPI_ControllerInput.h"
#include "RTPI_Drivetrain.h"
#include "RTPI_Intake.h"
#include "RTPI_Storage.h"
#include "RTPI_ManualFunctions.h"
#include "RTPI_AutoFunctions.h"
#include "RTPI_PIDControl.h"
#include "RTPI_Outtake.h"
#include "RTPI_ControlPanel.h"
#include "RTPI_DutyCycleEncoder.h"


using namespace frc;

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

  void MotorControllerSetup();
  void EncoderSetup();
  void PneumaticSetup();
  void SensorSetup();
  void ModuleSetup();

 private:
  //Drivetrain Motorcontrollers:
    RTPI_SparkMax *sparkDrivetrainLF;
    RTPI_SparkMax *sparkDrivetrainLB;
    RTPI_SparkMax *sparkDrivetrainRB;
    RTPI_SparkMax *sparkDrivetrainRF;
  //Drivetrain Encoders:
    RTPI_DutyCycleEncoder *drivetrainEncoderL;
    RTPI_DutyCycleEncoder *drivetrainEncoderR;

  //Intake Motorcontroller:
    RTPI_VictorSPX *victorIntakeCylinder;
  
  //Storage Motorcontrollers:
    RTPI_SparkMax *sparkStorageRevolver;
    RTPI_SparkMax *sparkStorageLoader;

  //Outtake Motorcontrollers:
    RTPI_SparkMax *sparkOuttakeUW;
    RTPI_SparkMax *sparkOuttakeDW;

  //Control Panel Motorcontroller:
    RTPI_SparkMax *sparkCPWheels;

  //Pneumatics:
    //Compressor
      RTPI_Pneumatics *compressor;
    //Pistons with 'Double Solenoids'
      RTPI_Pneumatics *intakeLRPiston;
      RTPI_Pneumatics *cpPiston;

  //Sensor:
    //imu
      RTPI_IMU *imu;
    //ColorSensor CP
      RTPI_ColorSensor *colorSensorCP;

  //RobotIO:
    RobotIO *robotIO;

  //ControllerInput:
    RTPI_ControllerInput *input;

  //Drivetrain
    RTPI_Drivetrain *drivetrain;

  //Intake
    RTPI_Intake *intake;
    
  //Outtake
    RTPI_Outtake *outtake;

  //Storage
    RTPI_Storage *storage;

  //Control Panel
    RTPI_ControlPanel *controlPanel;

  //ManualFunctions
    RTPI_ManualFunctions *mFunctions;

  //AutonomousFunctions
    RTPI_AutoFunctions *aFunctions;

  //PIDControl
    RTPI_PIDControl *PID;

  //Autonomous Drive Away Timer
    Timer *driveAwayTimer;

  //PI control course PID controller
    PIDController *PID_course_cam; 
};
