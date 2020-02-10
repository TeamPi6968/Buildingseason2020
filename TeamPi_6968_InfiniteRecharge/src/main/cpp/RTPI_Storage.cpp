#include "RTPI_Storage.h"

RTPI_Storage::RTPI_Storage(RTPI_SparkMax *storageRevolver, RTPI_SparkMax *storageLoader) {
  sparkRevolver = storageRevolver;
  sparkLoader = storageLoader;
}

void RTPI_Storage::SpinRevolver(double speed) {
  sparkRevolver->GetSparkMax()->Set(speed);
}

void RTPI_Storage::SpinLoader(double speed) {
  sparkLoader->GetSparkMax()->Set(speed);
}