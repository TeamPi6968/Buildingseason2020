#include "RTPI_Intake.h"

RTPI_Intake::RTPI_Intake(RTPI_VictorSPX *intakeCylinder, RTPI_Pneumatics *pistonLeft_, RTPI_Pneumatics *pistonRight_) {
  victorCylinder = intakeCylinder;
  pistonLeft = pistonLeft_;
  pistonRight = pistonRight_;
}

void RTPI_Intake::ResetIntake() {
  movePiston(DoubleSolenoid::Value::kReverse);
}

void RTPI_Intake::SpinIntake(double speed) {
  this->victorCylinder->GetVictorSPX()->Set(speed);
}

void RTPI_Intake::movePiston(enum DoubleSolenoid::Value direction) {
  this->pistonLeft->GetDoubleSolenoid()->Set(direction);
  this->pistonRight->GetDoubleSolenoid()->Set(direction);
}