/*
-   Created By: Jesper Weijnen
-   Date: 05-02-2020
-   Time: 22:15
-   Class: RTPI_SparkMax
*/

#pragma once

#include "rev/CANSparkMax.h"

using namespace rev;

class RTPI_SparkMax {
 private:
  CANSparkMax *rtpiSparkMax;

 public:
  RTPI_SparkMax(int canID, double acceleration, bool inverted);
  CANSparkMax *GetSparkMax();
};