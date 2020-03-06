#include "RTPI_Talon.h"

RTPI_Talon::RTPI_Talon(int canID) {
  this->talon = new WPI_TalonSRX(canID);
  talon->ConfigFactoryDefault();
}

WPI_TalonSRX *RTPI_Talon::GetTalon() {
  return this->talon;
}
