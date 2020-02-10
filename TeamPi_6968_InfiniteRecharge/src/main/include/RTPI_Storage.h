/*
-   Created By: Jesper Weijnen
-   Date: 10-02-2020
-   Time: 16:16
-   Class: RTPI_Intake
*/

#pragma once

#include "RTPI_SparkMax.h"

class RTPI_Storage {
 private:
  RTPI_SparkMax *sparkRevolver;
  RTPI_SparkMax *sparkLoader;
 public:
  RTPI_Storage(RTPI_SparkMax *storageRevolver, RTPI_SparkMax *storageLoader);
  void SpinRevolver(double speed);
  void SpinLoader(double speed);
};