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
        RTPI_SparkMax *sparkOut1;
        RTPI_SparkMax *sparkOut2;
        RTPI_SparkMax *sparkLoad;
        RTPI_PIDControl *shootPID;
        RTPI_Drivetrain *driveShoot;

    public:
    RTPI_Outtake(RTPI_SparkMax *sparkOut1_, RTPI_SparkMax *sparkOut2_, RTPI_SparkMax *_sparkLoad);
    void Shoot(double shootingspeed);
    void AutoShoot(double shootingspeed);
    void Load(double loadSpeed);
};