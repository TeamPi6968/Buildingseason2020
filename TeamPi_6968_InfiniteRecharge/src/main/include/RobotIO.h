#pragma once

//In this class, all defines and constants can be found.

class RobotIO {
 public:
  //CANID's
    //Drivetrain Motorcontrollers:
      int canDrivetrainLF = 1; //Left Front
      int canDrivetrainLB = 2; //Left Back
      int canDrivetrainRB = 3; //Right Back
      int canDrivetrainRF = 4; //Right Front
    //Intake Motorcontroller:
      int canIntakeCylinder = 5;
    //Storage Motorcontrollers:
      int canStorageRevolver = 6;
      int canStorageLoader = 7;
    //Outtake Motorcontrollers:
      int canOuttakeUW = 8; //Motor Upper Wheels
      int canOuttakeDW = 9; //Motor Down Wheels
    //Control Panel Motorcontroller:
      int canCPWheels = 10;

  //Acceleration Settings
    //Drivetrain Acceleration:
      int accDrivetrain = 1;
    //Intake Acceleration:
      int accIntakeCylinder = 0.5;
    //Storage Acceleration:
      int accStorageRevolver = 0.5;
      int accStorageLoader = 0.1;
    //Outtake Acceleration:
      int accOuttake = 1;
    //Control Panel:
      int accCPWheels = 0.2;

  //Drive Settings:
    //Drive Mode's
    #define ROCKET_LEAGUE_DRIVE 0
    #define FIRST_PERSON_SHOOTER_DRIVE 1
    //drive Mode
    int driveMode = ROCKET_LEAGUE_DRIVE; //Standard Drive Mode
};