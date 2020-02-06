#include "RTPI_Drivetrain.h"

RTPI_Drivetrain::RTPI_Drivetrain(RTPI_SparkMax *drivetrainLF, RTPI_SparkMax *drivetrainLB, RTPI_SparkMax *drivetrainRB, RTPI_SparkMax *drivetrainRF) {
  sparkLF = drivetrainLF;
  sparkLB = drivetrainLB;
  sparkRB = drivetrainRB;
  sparkRF = drivetrainRF;

  this->sparkLB->GetSparkMax()->Follow(*sparkLF->GetSparkMax());
  this->sparkRB->GetSparkMax()->Follow(*sparkRF->GetSparkMax());

  this->diffDrive = new DifferentialDrive(*sparkLF->GetSparkMax(), *sparkRF->GetSparkMax());
}

void RTPI_Drivetrain::Drive(double linearSpeed, double rotationSpeed) {
  this->diffDrive->ArcadeDrive(linearSpeed, rotationSpeed);
}