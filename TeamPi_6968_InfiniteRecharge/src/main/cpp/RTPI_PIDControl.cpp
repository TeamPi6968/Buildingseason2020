#include "RTPI_PIDControl.h"

RTPI_PIDControl::RTPI_PIDControl(double Kp){
    p = Kp;
}

double RTPI_PIDControl::GetRotAd(double AngleTolerance, double constForce, double setPoint, double currentPoint){
    double output;
    double error = setPoint - currentPoint;

    if(error < -AngleTolerance) {
        output = p * error - constForce;
    }
    else if(error > AngleTolerance){
        output = p * error + constForce;
    }
    else{
        output = 0;
    }

    return output;
}