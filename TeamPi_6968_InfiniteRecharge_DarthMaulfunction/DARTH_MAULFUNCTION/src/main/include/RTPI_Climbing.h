#pragma once

#include "RTPI_Talon.h"

class RTPI_Climbing {
    private:
        RTPI_Talon *climbTalon, *liftTalon;
    public:
        void Climbing(double speed);
        void Lifting(double speed);
        RTPI_Climbing(RTPI_Talon *_climbTalon, RTPI_Talon *_liftTalon);
};