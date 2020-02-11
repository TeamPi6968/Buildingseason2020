/*
-   Created By: Duncan Kikkert
-   Date: 10/02/2020
-   Time: 14:07
-   Class: RTPI_PIDControl
*/

#pragma once

class RTPI_PIDControl {
    private:
    double p;
    public:
        RTPI_PIDControl(double Kp);
        double GetRotAd(double tolerance, double constForce, double setPoint, double currentPoint);
};