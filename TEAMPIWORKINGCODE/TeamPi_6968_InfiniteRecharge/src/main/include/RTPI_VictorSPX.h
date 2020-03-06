/*
-   Created By: Jesper Weijnen
-   Date: 10-02-2020
-   Time: 13:03
-   Class: RTPI_VictorSPX
*/

#pragma once

#include <ctre/Phoenix.h>

class RTPI_VictorSPX {
 private:
  WPI_VictorSPX *rtpiVictorSPX;
 public:
  RTPI_VictorSPX(int canID, double acceleration, bool inverted);
  WPI_VictorSPX *GetVictorSPX();
};