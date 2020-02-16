/*
-   Created By: Jesper Weijnen
-   Date: 10-02-2020
-   Time: 16:16
-   Class: RTPI_Intake
*/

#pragma once

#include "RTPI_SparkMax.h"
#include "RTPI_MathFunctions.h"

class RTPI_Storage {
 private:
  RTPI_SparkMax *sparkRevolver;
  RTPI_SparkMax *sparkLoader;
  RTPI_MathFunctions *mathFunctions;
  double currentRevolverPosition;
 public:
  RTPI_Storage(RTPI_SparkMax *storageRevolver, RTPI_SparkMax *storageLoader);
  void SpinRevolver(double speed);
  void SpinLoader(double speed);
  void moveFifth(double direction);
};