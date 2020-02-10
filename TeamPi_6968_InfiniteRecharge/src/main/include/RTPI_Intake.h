/*
-   Created By: Jesper Weijnen
-   Date: 10-02-2020
-   Time: 15:38
-   Class: RTPI_Intake
*/

#pragma once

#include "RTPI_VictorSPX.h"

class RTPI_Intake {
 private:
  RTPI_VictorSPX *victorCylinder;
 public:
  RTPI_Intake(RTPI_VictorSPX *intakeCylinder);
  void SpinIntake(double speed);
};