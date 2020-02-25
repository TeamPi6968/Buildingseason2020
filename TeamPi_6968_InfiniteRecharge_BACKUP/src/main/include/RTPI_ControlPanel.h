/*
-   Created By: Auke Cras
-   Date: 12/02/2020
-   Time: 13:56
-   Class: RTPI_ControlPanel
*/

#pragma once

#include <frc/smartdashboard/smartdashboard.h>
#include <frc/util/color.h>
#include "rev/ColorMatch.h"

#include "RTPI_ColorSensor.h"
#include "RTPI_SparkMax.h"
#include "RTPI_Pneumatics.h"

using namespace rev;
using namespace std;

class RTPI_ControlPanel{
 private:
  string colorString;
  string preColorString;

  double confidence = 0;
  int colorCount = 0;

  ColorMatch *colorMatcher;

  static constexpr frc::Color kBlueTarget  = frc::Color       (0.116, 0.405, 0.477);
  static constexpr frc::Color kGreenTarget = frc::Color       (0.160, 0.571, 0.267);
  static constexpr frc::Color kRedTarget = frc::Color         (0.530, 0.335, 0.134);
  static constexpr frc::Color kYellowTarget = frc::Color      (0.317, 0.557, 0.136);
  static constexpr frc::Color kFakeYellowTarget1 = frc::Color (0.313, 0.435, 0.251);

  RTPI_ColorSensor *colorSensor;
  RTPI_SparkMax *sparkCP;
  RTPI_Pneumatics *pistonCP;

 public:
  RTPI_ControlPanel(RTPI_SparkMax *_sparkCP, RTPI_ColorSensor *_colorSensor, RTPI_Pneumatics *_pistonCP);
  void spinCPWheels(double speed);
  void moveCPPiston(enum DoubleSolenoid::Value direction);
  void ColorCounter();

  void AutoColourAndCount();
};