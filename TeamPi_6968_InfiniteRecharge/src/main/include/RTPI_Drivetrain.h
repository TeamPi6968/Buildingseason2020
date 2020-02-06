/*
-   Created By: Jesper Weijnen
-   Date: 06-02-2020
-   Time: 14:20
-   Class: RTPI_Drivetrain
*/

#pragma once

#include "RTPI_SparkMax.h"

class RTPI_Drivetrain {
 private:


 public:
  RTPI_Drivetrain(RTPI_SparkMax *sparkDrivetrainLF, RTPI_SparkMax *sparkDrivetrainLB, RTPI_SparkMax *sparkDrivetrainRB, RTPI_SparkMax *sparkDrivetrainRF);

};