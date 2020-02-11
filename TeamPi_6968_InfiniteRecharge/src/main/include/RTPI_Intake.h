/*
-   Created By: Jesper Weijnen
-   Date: 10-02-2020
-   Time: 15:38
-   Class: RTPI_Intake
*/

#pragma once

#include "RTPI_VictorSPX.h"
#include "RTPI_Pneumatics.h"

class RTPI_Intake {
 private:
  RTPI_VictorSPX *victorCylinder;
  RTPI_Pneumatics *pistonLR;
 public:
  RTPI_Intake(RTPI_VictorSPX *intakeCylinder, RTPI_Pneumatics *pistonLR_);
  void ResetIntake();
  void SpinIntake(double speed);
  void movePiston(enum DoubleSolenoid::Value direction);
};