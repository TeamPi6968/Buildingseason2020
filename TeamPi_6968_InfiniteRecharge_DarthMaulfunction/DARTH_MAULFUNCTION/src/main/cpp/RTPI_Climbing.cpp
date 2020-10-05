#include "RTPI_Climbing.h"

RTPI_Climbing::RTPI_Climbing(RTPI_Talon *_climbTalon, RTPI_Talon *_liftTalon){
    climbTalon = _climbTalon;
    liftTalon = _liftTalon;
}

void RTPI_Climbing::Climbing(double speed){
    this->climbTalon->GetTalon()->Set(speed);
}

void RTPI_Climbing::Lifting(double speed) {
    this->liftTalon->GetTalon()->Set(speed);
}