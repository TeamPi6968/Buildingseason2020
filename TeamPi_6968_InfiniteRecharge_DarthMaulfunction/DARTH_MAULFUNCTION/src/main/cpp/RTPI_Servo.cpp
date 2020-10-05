#include "RTPI_Servo.h"

RTPI_Servo::RTPI_Servo(int channel){
    _servo = new frc::Servo(channel);
}

void RTPI_Servo::POSControl(double position){
    _servo->Set(position);
}

void RTPI_Servo::AngleControl(double angle){
    _servo->SetAngle(angle);
}

double RTPI_Servo::GetServoPos(){
    return _servo->Get();
}

double RTPI_Servo::GetServoAngle(){
    return _servo->GetAngle();
}

double RTPI_Servo::Tester(){
    return _servo->GetMaxAngle();
}