/*
This class defines the encoder object

Created by Eduard Cazacu 
2020-02-15

Copyright Team PI 6968
*/

#pragma once

#include "rev/CANSparkMax.h"
#include "rev/CANEncoder.h"

class RTPI_Encoder{
public:
    //DESCRIPTION: 
    //  Constructor
    //INPUT:
    //  encoderHostSpark [rev::CANSparkMax] - the spark max controller to which the encoder
    //  is connected    
    RTPI_Encoder(rev::CANSparkMax *encoderHostSpark);

    //DESCRIPTION:
    //  returns a pointer to the CANEncoder object.
    rev::CANEncoder* getEncoder();

    //DESCRIPTION:
    //  returns the distance in m traveled since the last reset
    double getDistance();

    //DESCRIPTION:
    //  resets the absolute position of the encoder to 0
    void reset();

    //DESCRIPTION:
    //  sets the distance in m that one encoder rotation amounts to
    void setDistPerRot(double dPerRot);
    //DESCRIPTION:
    //  returns the distance in m that one encoder rotation amounts to
    double getDistPerRot();

    //DESCRIPTION:
    //  returns the speed in m/s as set by the distance/rotation variable
    double getRate();


private:
    rev::CANEncoder* enc;
    double dPerRot = 0.4787787204; //meters per roation
};