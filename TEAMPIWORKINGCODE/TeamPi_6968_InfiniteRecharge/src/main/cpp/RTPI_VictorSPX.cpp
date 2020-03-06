#include "RTPI_VictorSPX.h"

RTPI_VictorSPX::RTPI_VictorSPX(int canID, double acceleration, bool inverted) {
  this->rtpiVictorSPX = new WPI_VictorSPX(canID);
  rtpiVictorSPX->ConfigFactoryDefault();
  rtpiVictorSPX->ConfigOpenloopRamp(acceleration);
  rtpiVictorSPX->SetInverted(inverted);
}

WPI_VictorSPX *RTPI_VictorSPX::GetVictorSPX() {
  return this->rtpiVictorSPX;
}