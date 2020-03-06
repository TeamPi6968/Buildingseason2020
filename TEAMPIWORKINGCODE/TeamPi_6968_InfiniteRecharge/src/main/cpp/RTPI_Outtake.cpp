#include "RTPI_Outtake.h"
#include <math.h>

RTPI_Outtake::RTPI_Outtake(RTPI_SparkMax *sparkOut1_, RTPI_SparkMax *sparkOut2_, RTPI_SparkMax *_sparkLoad){
    sparkOut1 = sparkOut1_;
    sparkOut2 = sparkOut2_;
    sparkLoad = _sparkLoad;
}

void RTPI_Outtake::Load(double loadSpeed){
    this->sparkLoad->GetSparkMax()->Set(loadSpeed);
}

void RTPI_Outtake::Shoot(double shootingspeed){
    this->sparkOut1->GetSparkMax()->Set(shootingspeed);
    this->sparkOut2->GetSparkMax()->Set(-shootingspeed);
}

void RTPI_Outtake::AutoShoot(double shootingspeed){
    this->sparkOut1->GetSparkMax()->Set(shootingspeed);
}