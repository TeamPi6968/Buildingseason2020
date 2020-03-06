#include "RTPI_Pneumatics.h"

RTPI_Pneumatics::RTPI_Pneumatics(int canID_PCM) { //Creates Compressor Object
  this->rtpiCompressor = new Compressor(canID_PCM);
}

RTPI_Pneumatics::RTPI_Pneumatics(int canID_PCM, int portNumber) { //Creates Single Solenoid Object
  this->rtpiSingleSolenoid = new Solenoid(canID_PCM, portNumber);
}

RTPI_Pneumatics::RTPI_Pneumatics(int canID_PCM, int portNumberForward, int portNumberReverse) { //Creates Double Solenoid Object
  this->rtpiDoubleSolenoid = new DoubleSolenoid(canID_PCM, portNumberForward, portNumberReverse);
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