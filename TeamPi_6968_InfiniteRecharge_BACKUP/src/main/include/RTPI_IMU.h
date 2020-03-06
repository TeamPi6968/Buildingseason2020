/*
This class handles the Pigeon IMU stuff

Created by Eduard Cazacu 
2020-02-16

Copyright Team Pi 6968
*/

#pragma once

#include "ctre/Phoenix.h"

class RTPI_IMU
{
public:
    RTPI_IMU(int canID);

    PigeonIMU *getPigeon();

private:
    PigeonIMU *pidgey;
};