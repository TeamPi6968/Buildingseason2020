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
#include <frc/timer.h>

#include "RTPI_Talon.h"
#include "RTPI_ControllerInput.h"
#include "RTPI_Drivetrain.h"
#include "RTPI_Functions.h"
#include "RTPI_Climbing.h"
#include "RTPI_Servo.h"

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

 private:
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;

  RTPI_ControllerInput *Input;
  RTPI_Talon *MasterL, *SlaveL, *MasterR, *SlaveR, *climbTalon, *controlTalon;
  RTPI_Drivetrain *drivetrain;
  RTPI_Functions *function;
  RTPI_Climbing *climbing;
  RTPI_Servo *servo;
  Timer *timer;
};
