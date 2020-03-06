#pragma once

#include <ctre/Phoenix.h>

class RTPI_Talon {
 private:
  WPI_TalonSRX *talon;
  
 public:
  RTPI_Talon(int canID/*, double acceleration, bool inverted*/);
  WPI_TalonSRX *GetTalon();
};