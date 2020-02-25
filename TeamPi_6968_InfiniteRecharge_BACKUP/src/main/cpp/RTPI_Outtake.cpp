#include "RTPI_Outtake.h"
#include <math.h>

RTPI_Outtake::RTPI_Outtake(RTPI_SparkMax *sparkOutUW_, RTPI_SparkMax *sparkOutDW_){
    sparkOutUW = sparkOutUW_;
    sparkOutDW = sparkOutDW_;

    //this->sparkOut2->GetSparkMax()->Follow(*sparkOut1->GetSparkMax());
}

void RTPI_Outtake::Shoot(double shootingspeed){
  this->sparkOutUW->GetSparkMax()->Set(shootingspeed);
  this->sparkOutDW->GetSparkMax()->Set(shootingspeed);
}

void RTPI_Outtake::AutoShoot(double shootingspeed){
  this->sparkOutUW->GetSparkMax()->Set(shootingspeed);
}

void RTPI_Outtake::DiffSpeedShoot(double uwSpeed, double dwSpeed) {
  this->sparkOutUW->GetSparkMax()->Set(uwSpeed);
  this->sparkOutDW->GetSparkMax()->Set(dwSpeed);
}