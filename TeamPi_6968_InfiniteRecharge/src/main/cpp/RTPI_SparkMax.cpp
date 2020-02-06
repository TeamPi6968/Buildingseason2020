#include "RTPI_SparkMax.h"

RTPI_SparkMax::RTPI_SparkMax(bool brushless, int canID, double acceleration, bool inverted) {
  if(brushless) {
    this->rtpiSparkMax = new RTPI_SparkMax(canID, CANSparkMax::MotorType::kBrushless);
  }
  else {
    this->rtpiSparkMax = new RTPI_SparkMax(canID, CANSparkMax::MotorType::kBrushed);
  }
  rtpiSparkMax->RestoreFactoryDefaults();
  rtpiSparkMax->SetOpenLoopRampRate(acceleration);
  rtpiSparkMax->SetInverted(inverted);
}

CANSparkMax *RTPI_SparkMax::GetSparkMax() {
  return this->rtpiSparkMax;
}