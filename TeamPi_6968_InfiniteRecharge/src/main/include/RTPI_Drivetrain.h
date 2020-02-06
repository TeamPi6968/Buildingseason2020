/*
-   Created By: Jesper Weijnen
-   Date: 06-02-2020
-   Time: 14:20
-   Class: RTPI_Drivetrain
*/

#pragma once

#include "RTPI_SparkMax.h"
#include <frc/drive/DifferentialDrive.h>

using namespace frc;

class RTPI_Drivetrain {
 private:
  RTPI_SparkMax *sparkLF;
  RTPI_SparkMax *sparkLB;
  RTPI_SparkMax *sparkRB;
  RTPI_SparkMax *sparkRF;

  DifferentialDrive *diffDrive;

 public:
  RTPI_Drivetrain(RTPI_SparkMax *sparkDrivetrainLF, RTPI_SparkMax *sparkDrivetrainLB, RTPI_SparkMax *sparkDrivetrainRB, RTPI_SparkMax *sparkDrivetrainRF);
  void Drive(double linearSpeed, double rotationSpeed);
};