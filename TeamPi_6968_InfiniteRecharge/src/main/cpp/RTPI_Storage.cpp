#include "RTPI_Storage.h"

RTPI_Storage::RTPI_Storage(RTPI_SparkMax *storageRevolver, RTPI_SparkMax *storageLoader) {
  sparkRevolver = storageRevolver;
  sparkLoader = storageLoader;
  currentRevolverPosition = this->sparkRevolver->GetSparkMaxEncoder()->GetPosition();
  this->sparkRevolver->SetPIDValues(1.5e-1, 0, 0, -0.15, 0.15);
}

void RTPI_Storage::SpinRevolver(double speed) {
  sparkRevolver->GetSparkMax()->Set(speed);
}

void RTPI_Storage::SpinLoader(double speed) {
  sparkLoader->GetSparkMax()->Set(speed);
}

void RTPI_Storage::moveFifth(double direction) {
  //currentRevolverPosition = this->sparkRevolver->GetSparkMaxEncoder()->GetPosition();
  currentRevolverPosition += (20 * direction);
  sparkRevolver->GetSparkMaxPIDController()->SetReference(currentRevolverPosition, ControlType::kPosition);
}