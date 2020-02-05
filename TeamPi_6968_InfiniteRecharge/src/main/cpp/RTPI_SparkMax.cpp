#include "RTPI_SparkMax.h"

RTPI_SparkMax::RTPI_SparkMax(int canID, double acceleration, bool inverted) {
  this->rtpiSparkMax = new CANSparkMax(canID, CANSparkMax::MotorType::kBrushless);
  rtpiSparkMax->RestoreFactoryDefaults();
  rtpiSparkMax->SetOpenLoopRampRate(acceleration);
  rtpiSparkMax->SetInverted(inverted);
}

CANSparkMax *RTPI_SparkMax::GetSparkMax() {
  return this->rtpiSparkMax;
}