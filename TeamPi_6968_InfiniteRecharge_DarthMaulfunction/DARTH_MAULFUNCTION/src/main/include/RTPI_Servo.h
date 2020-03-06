#pragma once

#include <frc/Servo.h>

class RTPI_Servo {
    public:
        RTPI_Servo(int channel);
        void POSControl(double position);
        void AngleControl(double angle);
        void TurnC();
        void TurnCC();
        double GetPos();
        double GetAngle();
        double Tester();

    private:
    frc::Servo *_servo;

};