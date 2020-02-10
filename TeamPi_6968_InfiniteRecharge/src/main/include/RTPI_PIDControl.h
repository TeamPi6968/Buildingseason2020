/*
-   Created By: Duncan Kikkert
-   Date: 10/02/2020
-   Time: 14:07
-   Class: PID Control
*/

#pragma once

class RTPI_PIDControl {
    private:
    double p;
    public:
        RTPI_PIDControl(double Kp);
        double GetRotAd(double AngleTolerance, double constForce, double setPoint, double currentPoint);
};