#include "RTPI_Climbing.h"

RTPI_Climbing::RTPI_Climbing(RTPI_Talon *_climbTalon){
    climbTalon = _climbTalon;
}

void RTPI_Climbing::Climbing(){
    this->climbTalon->GetTalon()->Set(1);
}

void RTPI_Climbing::ClimbDown(){
    this->climbTalon->GetTalon()->Set(-1);
}

void RTPI_Climbing::DoNothing(){
    this->climbTalon->GetTalon()->Set(0);
}