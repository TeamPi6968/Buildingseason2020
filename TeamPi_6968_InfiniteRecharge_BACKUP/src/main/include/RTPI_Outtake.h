/*
-   Created By: Duncan Kikkert
-   Date: 11/02/2020
-   Time: 12:10
-   Class: RTPI_Outtake
*/

#pragma once

#include "RTPI_SparkMax.h"
#include "RTPI_PIDControl.h"
#include "RTPI_Drivetrain.h"

class RTPI_Outtake {
    private:
        RTPI_SparkMax *sparkOutUW;
        RTPI_SparkMax *sparkOutDW;
        RTPI_PIDControl *shootPID;
        RTPI_Drivetrain *driveShoot;

    public:
    RTPI_Outtake(RTPI_SparkMax *sparkOutUW_, RTPI_SparkMax *sparkOutDW_);
    void Shoot(double shootingspeed);
    void AutoShoot(double shootingspeed);
    void DiffSpeedShoot(double uwSpeed, double dwSpeed);
};