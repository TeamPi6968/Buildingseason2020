#include "RTPI_SparkMax.h"

RTPI_SparkMax::RTPI_SparkMax(bool brushless, int canID, double acceleration, bool inverted, bool encoder, bool pidController) {
  if(brushless) {
    this->rtpiSparkMax = new CANSparkMax(canID, CANSparkMax::MotorType::kBrushless);
  }
  else {
    this->rtpiSparkMax = new CANSparkMax(canID, CANSparkMax::MotorType::kBrushed);
  }
  rtpiSparkMax->RestoreFactoryDefaults();
  rtpiSparkMax->SetOpenLoopRampRate(acceleration);
  rtpiSparkMax->SetInverted(inverted);

  if(encoder) {
    rtpiSparkMaxEncoder = new CANEncoder(rtpiSparkMax->GetEncoder());
  }
  if(pidController) {
    rtpiSparkMaxPIDController = new CANPIDController(rtpiSparkMax->GetPIDController());
  }
}

CANSparkMax *RTPI_SparkMax::GetSparkMax() {
  return this->rtpiSparkMax;
}

CANEncoder *RTPI_SparkMax::GetSparkMaxEncoder() {
  return this->rtpiSparkMaxEncoder;
}

CANPIDController *RTPI_SparkMax::GetSparkMaxPIDController() {
  return this->rtpiSparkMaxPIDController;
}