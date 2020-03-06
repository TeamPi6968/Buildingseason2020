/*
-   Created By: Jesper "The Notorious" Weijnen
-   Date: 18/02/2020
-   Time: 20:11
-   Class: RTPI_DutyCycleEncoder
*/

#pragma once

#include <frc/DutyCycleEncoder.h>

using namespace frc;

class RTPI_DutyCycleEncoder {
 private:
  DutyCycleEncoder *rtpiDutyCycleEncoder;
 
 public:
  RTPI_DutyCycleEncoder(int DIOChannel, double distancePerRotation);
  bool IsEncConnected();
  double GetEncFrequency();
  double GetEncPosition();
  double GetEncDistance();
};