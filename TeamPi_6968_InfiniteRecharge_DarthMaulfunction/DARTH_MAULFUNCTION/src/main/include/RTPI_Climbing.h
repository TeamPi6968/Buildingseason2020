#pragma once

#include "RTPI_Talon.h"

class RTPI_Climbing {
    private:
        RTPI_Talon *climbTalon;
    public:
        void Climbing();
        void ClimbDown();
        void DoNothing();
        RTPI_Climbing(RTPI_Talon *_climbTalon);
};