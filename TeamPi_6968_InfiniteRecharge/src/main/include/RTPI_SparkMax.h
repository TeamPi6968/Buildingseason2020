/*
-   Created By: Jesper Weijnen
-   Date: 06-02-2020
-   Time: 13:07
-   Class: RTPI_SparkMax



    dependencies:
    Vendor library: http://www.revrobotics.com/content/sw/max/sdk/REVRobotics.json
*/

#pragma once

#include "rev/CANSparkMax.h"

using namespace rev;

class RTPI_SparkMax {
 private:
  CANSparkMax *rtpiSparkMax;
  CANEncoder *rtpiSparkMaxEncoder;
  CANPIDController rtpiSparkMaxPIDController;
 public:
  RTPI_SparkMax(bool brushless, int canID, double acceleration, bool inverted, bool encoder, bool pidController);
  CANSparkMax *GetSparkMax();
  CANEncoder *GetSparkMaxEncoder();
  CANPIDController *GetSparkMaxPIDController();
  void SetP(double gain);
  void SetPIDValues(double kP, double kI, double kD, double kMinOutput, double kMaxOutput);
};