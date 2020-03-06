#include "RTPI_Servo.h"

RTPI_Servo::RTPI_Servo(int channel){
    _servo = new frc::Servo(channel);
}

void RTPI_Servo::POSControl(double position){
    _servo->Set(position);
}

void RTPI_Servo::AngleControl(double angle){
    _servo->Set(angle);
}

void RTPI_Servo::TurnC(){
    _servo->Set(1);
}

void RTPI_Servo::TurnCC(){
    _servo->Set(0);
}

double RTPI_Servo::GetPos(){
    return _servo->Get();
}

double RTPI_Servo::GetAngle(){
    return _servo->GetAngle();
}

double RTPI_Servo::Tester(){
    return _servo->GetMaxAngle();
}