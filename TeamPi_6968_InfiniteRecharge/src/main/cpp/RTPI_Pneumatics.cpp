#include "RTPI_Pneumatics.h"

RTPI_Pneumatics::RTPI_Pneumatics(int canID) { //Creates Compressor Object
  this->rtpiCompressor = new Compressor(canID);
}

RTPI_Pneumatics::RTPI_Pneumatics(int canID, int portNumber) { //Creates Single Solenoid Object
  this->rtpiSingleSolenoid = new Solenoid(canID, portNumber);
}

RTPI_Pneumatics::RTPI_Pneumatics(int canID, int portNumberForward, int portNumberReverse) { //Creates Double Solenoid Object
  this->rtpiDoubleSolenoid = new DoubleSolenoid(canID, portNumberForward, portNumberReverse);
}



Compressor *RTPI_Pneumatics::GetCompressor() {
  return this->rtpiCompressor;
}

Solenoid *RTPI_Pneumatics::GetSingleSolenoid() {
  return this->rtpiSingleSolenoid;
}

DoubleSolenoid *RTPI_Pneumatics::GetDoubleSolenoid() {
  return this->rtpiDoubleSolenoid;
}