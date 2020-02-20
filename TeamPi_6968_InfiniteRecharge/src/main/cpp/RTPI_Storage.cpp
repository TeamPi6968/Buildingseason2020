#include "RTPI_Storage.h"

RTPI_Storage::RTPI_Storage(RTPI_SparkMax *storageRevolver, RTPI_SparkMax *storageLoader) {
  sparkRevolver = storageRevolver;
  sparkLoader = storageLoader;
  this->mathFunctions = new RTPI_MathFunctions();
  currentRevolverPosition = this->sparkRevolver->GetSparkMaxEncoder()->GetPosition();
  this->sparkRevolver->SetPIDValues(1.5e-1, 0, 0, -0.25, 0.25);
}

void RTPI_Storage::SpinRevolver(double speed) {
  if(speed > 0.1) {
    speed = mathFunctions->MapDouble(speed, 0.1, 1, 0.15, 0.4);
  }
  else if(speed < -0.1) {
    speed = mathFunctions->MapDouble(speed, -0.1, -1, -0.15, -0.4);
  }
  else {
    speed = 0;
  }
  sparkRevolver->GetSparkMax()->Set(speed);
}

void RTPI_Storage::SpinLoader(double speed) {
  sparkLoader->GetSparkMax()->Set(speed);
}

void RTPI_Storage::moveFifth(double direction) {
  //currentRevolverPosition = this->sparkRevolver->GetSparkMaxEncoder()->GetPosition();
  currentRevolverPosition += (mathFunctions->TransmissionTransferReversed(0.2, 100, 1) * direction);
  sparkRevolver->GetSparkMaxPIDController()->SetReference(currentRevolverPosition, ControlType::kPosition);
}