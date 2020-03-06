#include "RTPI_Intake.h"

RTPI_Intake::RTPI_Intake(RTPI_VictorSPX *intakeCylinder, RTPI_Pneumatics *pistonLR_) {
  victorCylinder = intakeCylinder;
  pistonLR = pistonLR_;
}

void RTPI_Intake::ResetIntake() {
  movePiston(DoubleSolenoid::Value::kReverse);
}

void RTPI_Intake::SpinIntake(double speed) {
  this->victorCylinder->GetVictorSPX()->Set(speed);
}

void RTPI_Intake::movePiston(enum DoubleSolenoid::Value direction) {
  this->pistonLR->GetDoubleSolenoid()->Set(direction);
}