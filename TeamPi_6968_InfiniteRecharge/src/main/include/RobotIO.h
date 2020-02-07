#pragma once

//In this class, all defines and constants can be found.

class RobotIO {
 public:
  //CANID's
    //Drivetrain Motorcontrollers:
    int canDrivetrainLF = 1;
    int canDrivetrainLB = 2;
    int canDrivetrainRB = 3;
    int canDrivetrainRF = 4;
    //Intake Motorcontrollers:
    int canIntakeCylinder = 5;
    //Storage Motorcontrollers:
    int canStorageRevolver = 6;
    int canStorageLoading = 7;
    //Outtake Motorcontrollers:
    int canOuttakeUW = 8; //Motor Upper Wheels
    int canOuttakeDW = 9; //Motor Down Wheels
    //Control Panel Motorcontrollers:

  //Drive Settings:
    //Drive Mode's
    #define ROCKET_LEAGUE_DRIVE 0
    #define FIRST_PERSON_SHOOTER_DRIVE 1
    //drive Mode
    int driveMode = ROCKET_LEAGUE_DRIVE; //Standard Drive Mode
};