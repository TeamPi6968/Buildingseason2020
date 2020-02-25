#include "RTPI_ColorSensor.h"

RTPI_ColorSensor::RTPI_ColorSensor(I2C::Port i2cPort) {
  this->rtpiColorSensor = new ColorSensorV3(i2cPort);
}

ColorSensorV3 *RTPI_ColorSensor::GetColorSensor() {
  return this->rtpiColorSensor;
}