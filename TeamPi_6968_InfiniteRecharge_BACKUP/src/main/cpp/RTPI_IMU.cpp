#include "RTPI_IMU.h"

RTPI_IMU::RTPI_IMU(int canID)
{
    pidgey = new PigeonIMU(canID);
}

PigeonIMU* RTPI_IMU::getPigeon(){
    return pidgey;
}