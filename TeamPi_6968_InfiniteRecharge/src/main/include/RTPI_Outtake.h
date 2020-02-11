/*
-   Created By: Duncan Kikkert
-   Date: 11/02/2020
-   Time: 12:10
-   Class: RTPI_Outtake
*/

#pragma once

#include "RTPI_VictorSPX.h"

class RTPI_Outtake {
    private:
        RTPI_VictorSPX *VictorOut1;
        RTPI_VictorSPX *VictorOut2;

    public:
    RTPI_Outtake(RTPI_VictorSPX *VictorOut1_, RTPI_VictorSPX *VictorOut2_);
    void Shoot(double speed);
};