#include "RTPI_Drivetrain.h"

RTPI_Drivetrain::RTPI_Drivetrain(RTPI_SparkMax *sparkDrivetrainLF, RTPI_SparkMax *sparkDrivetrainLB, RTPI_SparkMax *sparkDrivetrainRB, RTPI_SparkMax *sparkDrivetrainRF) {
  this->sparkLF = sparkDrivetrainLF;
  this->sparkLB = sparkDrivetrainLB;
  this->sparkRB = sparkDrivetrainRB;
  this->sparkRF = sparkDrivetrainRF;

  this->sparkLB->GetSparkMax()->Follow(*this->sparkLF->GetSparkMax());
  this->sparkRB->GetSparkMax()->Follow(*this->sparkRF->GetSparkMax());

  this->diffDrive = new DifferentialDrive(*sparkLF->GetSparkMax(), *sparkRF->GetSparkMax());
}

void RTPI_Drivetrain::Drive(double linearSpeed, double rotationSpeed) {
  this->diffDrive->ArcadeDrive(linearSpeed, rotationSpeed);
}