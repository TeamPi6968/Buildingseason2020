/*
-   Created By: Auke Cras
-   Date: 12/02/2020
-   Time: 13:56
-   Class: RTPI_Outtake
*/

#pragma once

#include "RTPI_SparkMax.h"
#include <frc/smartdashboard/smartdashboard.h>
#include <frc/util/color.h>
#include "rev/ColorMatch.h"

#include "RTPI_ColorSensor.h"

class RTPI_ControlPanel{
 private:
  std::string colorString;
  double confidence = 0.0;

  static constexpr frc::Color kBlueTarget  = frc::Color    (0.116, 0.405, 0.477);
  static constexpr frc::Color kGreenTarget = frc::Color   (0.160, 0.571, 0.267);
  static constexpr frc::Color kRedTarget = frc::Color     (0.530, 0.335, 0.134);
  static constexpr frc::Color kYellowTarget = frc::Color  (0.317, 0.557, 0.136);
  static constexpr frc::Color kFakeYellowTarget1 = frc::Color(0.313, 0.435, 0.251);

  RTPI_ColorSensor *colorSensor;
  RTPI_SparkMax *sparkCP;

 public:
  void ColourMatcher();
  rev::ColorMatch m_colorMatcher;

  std::string preColorString;
  int colorCount = 0;

  void ColourAndCount(double triggerSum);
  void AutoColourAndCount();
  RTPI_ControlPanel(RTPI_SparkMax *_sparkCP, RTPI_ColorSensor *_colorSensor);
    
};