/*
-   Created By: Jesper Weijnen
-   Date: 10-02-2020
-   Time: 23:10
-   Class: RTPI_Pneumatics
*/

#pragma once

#include <frc/Compressor.h>
#include <frc/Solenoid.h>
#include <frc/DoubleSolenoid.h>

#include "RobotIO.h"

using namespace frc;

class RTPI_Pneumatics {
 private:
  Compressor *rtpiCompressor;
  Solenoid *rtpiSingleSolenoid;
  DoubleSolenoid *rtpiDoubleSolenoid;
 public:
  RTPI_Pneumatics(int canID /*Compressor*/);
  RTPI_Pneumatics(int canID, int portNumber /*Single Solenoid*/);
  RTPI_Pneumatics(int canID, int portNumberForward, int portNumberReverse /*Double Solenoid*/);

  Compressor *GetCompressor();
  Solenoid *GetSingleSolenoid();
  DoubleSolenoid *GetDoubleSolenoid();
};