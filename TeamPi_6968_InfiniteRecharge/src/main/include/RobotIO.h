#pragma once

//In this class, all defines and constants can be found.

class RobotIO {
 public:
  //CANID's
    //Pneumatic Control Module:
      int canPCM = 11;
    //Power Distribution Panel:
      int canPDP = 0;
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
      int accIntakeCylinder = 1;
    //Storage Acceleration:
      int accStorageRevolver = 0.5;
      int accStorageLoader = 0.1;
    //Outtake Acceleration:
      int accOuttake = 1;
    //Control Panel:
      int accCPWheels = 0.2;

  //Pneumatic Ports (PCM Ports)
    //Intake Pistons:
      int intakeLPortForward = 0; //Left intake piston forward
      int intakeLPortReverse = 1; //Left intake piston reverse
      int intakeRPortForward = 2; //Right intake piston forward
      int intakeRPortReverse = 3; //Right intake pitson reverse
    //Control Panel Piston:
      int cpPortForward = 4; //Control panel piston forward
      int cpPortReverse = 5; //Control panel piston reverse

  //Drive Settings: (RTPI_Drivetrain)
    //Drive Mode's
      #define ROCKET_LEAGUE_DRIVE 0
      #define FIRST_PERSON_SHOOTER_DRIVE 1
    //drive Mode
      int driveMode = ROCKET_LEAGUE_DRIVE; //Standard Drive Mode

  //Intake Settings (RTPI_Intake)
    //Max Intake Speed
      double intakeSpeed = 0.5;

  //Pneumatic Settings: (RTPI_Pneumatics)
    //
};