#pragma once

#include "frc/I2C.h"

//In this class, all defines and constants can be found.

class RobotIO {
 public:
  //SparkMax Settings
    //MotorTypes:
      #define BRUSHLESS true
      #define BRUSHED false
    //Yes & No boolean (for inverted, encoder and PID Controller)
      #define YES true
      #define NO false



  //Motorcontroller Config:
    //Drivetrain Motorcontrollers:
      int canDrivetrainLF = 8; //Left Front CANID
        bool drivetrainLFMotorType = BRUSHLESS; //MotorType
        bool drivetrainLFInverted = YES; //Inverted?
        bool drivetrainLFEncoder = NO; //Encoder?
        bool drivetrainLFPIDController = NO; //PID Controller?
      int canDrivetrainLB = 9; //Left Back CANID
        bool drivetrainLBMotorType = BRUSHLESS; //MotorType
        bool drivetrainLBInverted = YES; //Inverted?
        bool drivetrainLBEncoder = NO; //Encoder?
        bool drivetrainLBPIDController = NO; //PID Controller?
      int canDrivetrainRB = 1; //Right Back CANID
        bool drivetrainRBMotorType = BRUSHLESS; //MotorType
        bool drivetrainRBInverted = YES; //Inverted?
        bool drivetrainRBEncoder = NO; //Encoder?
        bool drivetrainRBPIDController = NO; //PID Controller?
      int canDrivetrainRF = 2; //Right Front CANID
        bool drivetrainRFMotorType = BRUSHLESS; //MotorType
        bool drivetrainRFInverted = YES; //Inverted?
        bool drivetrainRFEncoder = NO; //Encoder?
        bool drivetrainRFPIDController = NO; //PID Controller?

    //Intake Motorcontroller:
      int canIntakeCylinder = 10; //Intake Cylinder CANID
        bool intakeCylinderInverted = NO; //Inverted?

    //Storage Motorcontrollers:
      int canStorageRevolver = 3; //Storage Revolver CANID
        bool storageRevolverMotorType = BRUSHLESS; //MotorType
        bool storageRevolverInverted = NO; //Inverted?
        bool storageRevolverEncoder = YES; //Encoder?
        bool storageRevolverPIDController = YES; //PID Controller?
      int canStorageLoader = 5; //Storage Loader CANID
        bool storageLoaderMotorType = BRUSHLESS; //MotorType
        bool storageLoaderInverted = NO; //Inverted?
        bool storageLoaderEncoder = NO; //Encoder?
        bool storageLoaderPIDController = NO; //PID Controller?

    //Outtake Motorcontrollers:
      int canOuttakeUW = 7; //Motor Upper Wheels CANID
        bool outtakeUWMotorType = BRUSHED; //MotorType
        bool outtakeUWInverted = NO; //Inverted?
        bool outtakeUWEncoder = NO; //Encoder?
        bool outtakeUWPIDController = NO; //PID Controller?
      int canOuttakeDW = 6; //Motor Down Wheels CANID
        bool outtakeDWMotorType = BRUSHED; //MotorType
        bool outtakeDWInverted = NO; //Inverted?
        bool outtakeDWEncoder = NO; //Encoder?
        bool outtakeDWPIDController = NO; //PID Controller?

    //Control Panel Motorcontroller:
      int canCPWheels = 4; //Control Panel Wheels CANID
        bool CPWheelsMotorType = BRUSHLESS; //MotorType
        bool CPWheelsInverted = NO; //Inverted?
        bool CPWheelsEncoder = NO; //Encoder?
        bool CPWheelsPIDController = NO; //PID Controller?



  //Encoders:
    //Drivetrain Encoders:
      int drivetrainEncChannelL = 0;
      int drivetrainEncChannelR = 1;
    //Drivetrain Wheels Perimeter
      double drivetrainWheelPerimeter = 478.7787204070; // (in mm)


  //Pneumatics
    //Pneumatic Control Module:
      int canPCM = 11;
    //Power Distribution Panel:
      int canPDP = 0;
    //Pigeon Gyroscope:
      int canPigeon = 12;



  //Sensors
    //ColorSensor:
      frc::I2C::Port portColorSensorCP = frc::I2C::Port::kOnboard;



  //Acceleration Settings
    //Drivetrain Acceleration:
      int accDrivetrain = 0.2;
    //Intake Acceleration:
      int accIntakeCylinder = 0.2;
    //Storage Acceleration:
      int accStorageRevolver = 1;
      int accStorageLoader = 0.4;
    //Outtake Acceleration:
      int accOuttake = 1;
    //Control Panel:
      int accCPWheels = 0.2;



  //Pneumatic Ports (PCM Ports)
    //Intake Pistons:
      int intakeLRPortForward = 0; //Left intake piston forward
      int intakeLRPortReverse = 1; //Left intake piston reverse
    //Control Panel Piston:
      int cpPortForward = 2; //Control panel piston forward
      int cpPortReverse = 3; //Control panel piston reverse



  //Drive Settings: (RTPI_Drivetrain)
    //Drive Mode's
      #define ROCKET_LEAGUE_DRIVE 0
      #define FIRST_PERSON_SHOOTER_DRIVE 1
    //drive Mode
      int driveMode = FIRST_PERSON_SHOOTER_DRIVE; //Standard Drive Mode



  //Intake Settings (RTPI_Intake)
    //Max Intake Speed
      double intakeSpeed = 0.5;
    //Change State Detection Variables
      bool intakeBState0 = 0; //Current Intake Button State, Number 0
      bool lastIntakeBState0 = 0; //last Intake Button State, Number 0
      bool intakePState0 = 0; //Current Intake Piston State, Number 0



  //Storage Settings (RTPI_Storage)
    //Change State Detection Revolver 0
      bool storageRevolverBState0 = 0;
      bool lastStorageRevolverBState0 = 0;
    //Change State Detection Revolver 1
      bool storageRevolverBState1 = 0;
      bool lastStorageRevolverBState1 = 0;


  
  //Control Panel Settings (RTPI_ControlPanel)
    //Manual Control Panel mode enabled
      bool cpManualMode = false;
    //Change State Detection
      bool cpBState0 = 0;
      bool lastCPBState0 = 0;
      bool cpPState0 = 0;



  //Pneumatic Settings: (RTPI_Pneumatics)
    //



  //Autonomous Functions:
    //Autonomous Enabled/Disabled
      bool autoFunction = false;
};