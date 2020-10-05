#pragma once

#include <frc/Servo.h>

class RTPI_Servo {
    public:
        RTPI_Servo(int channel);
        void POSControl(double position);
        void AngleControl(double angle);
        double GetServoPos();
        double GetServoAngle();
        double Tester();

    private:
    frc::Servo *_servo;

};