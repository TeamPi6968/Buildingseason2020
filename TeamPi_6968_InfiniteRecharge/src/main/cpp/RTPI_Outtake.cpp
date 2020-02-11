#include "RTPI_Outtake.h"

RTPI_Outtake::RTPI_Outtake(RTPI_VictorSPX *VictorOut1_, RTPI_VictorSPX *VictorOut2_){
    VictorOut1 = VictorOut1_;
    VictorOut2 = VictorOut2_;

this->VictorOut2->GetVictorSPX()->Follow(*VictorOut1->GetVictorSPX());
}

void RTPI_Outtake::Shoot(double speed){
    this->VictorOut1->GetVictorSPX()->Set(speed);
}