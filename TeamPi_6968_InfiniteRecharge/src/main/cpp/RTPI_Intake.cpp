#include "RTPI_Intake.h"

RTPI_Intake::RTPI_Intake(RTPI_VictorSPX *intakeCylinder) {
  victorCylinder = intakeCylinder;
}

void RTPI_Intake::SpinIntake(double speed) {
  this->victorCylinder->GetVictorSPX()->Set(speed);
}