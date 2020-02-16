/*
-   Created By: Jesper Weijnen
-   Date: 15/02/2020
-   Time: 23:31
-   Class: RTPI_ColorSensor
*/

#pragma once

#include "rev/ColorSensorV3.h"

using namespace rev;
using namespace frc;

class RTPI_ColorSensor {
 private:
  ColorSensorV3 *rtpiColorSensor;

 public:
  RTPI_ColorSensor(I2C::Port i2cPort);
  ColorSensorV3 *GetColorSensor();
};