/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>

#include "RobotIO.h"
#include "RTPI_SparkMax.h"

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

 private:
  //Drivetrain Motorcontrollers:
  RTPI_SparkMax *sparkDrivetrainLF;
  RTPI_SparkMax *sparkDrivetrainLB;
  RTPI_SparkMax *sparkDrivetrainRB;
  RTPI_SparkMax *sparkDrivetrainRF;
};
