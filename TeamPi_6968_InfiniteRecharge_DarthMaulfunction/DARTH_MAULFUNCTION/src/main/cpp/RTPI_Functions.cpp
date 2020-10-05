#include "RTPI_Functions.h"

RTPI_Functions::RTPI_Functions(RTPI_Drivetrain *_drivetrain, RTPI_ControllerInput *_controllerinput, RTPI_Climbing *_climb, RTPI_Servo *_servoR){
    this->drivetrain = _drivetrain;
    this->controllerinput = _controllerinput;
    this->climb = _climb;
    this->servoR = _servoR;
    this->PiTalon = new RTPI_Talon(7);
}

void RTPI_Functions::DriveRL(){
    drivetrain->Driving(controllerinput->driver->GetRawAxis(3) - controllerinput->driver->GetRawAxis(2), controllerinput->driver->GetRawAxis(0));
}

void RTPI_Functions::Drive(double linearSpeed, double rotationSpeed) {
    drivetrain->Driving(linearSpeed, rotationSpeed);
}

void RTPI_Functions::Climber(int climbUpB, int climbDownB){
    if(controllerinput->navigator->GetRawButton(climbUpB)){
        climb->Climbing(-1);
    }
    else if(controllerinput->navigator->GetRawButton(climbDownB)){
        climb->Climbing(1);
    }
    else {
        climb->Climbing(0);
    }
}

void RTPI_Functions::Lifter(int liftUpB, int liftDownB) {
    if(controllerinput->navigator->GetRawButton(liftUpB)) {
        climb->Lifting(-1);
    }
    else if(controllerinput->navigator->GetRawButton(liftDownB)) {
        climb->Lifting(1);
    }
    else {
        climb->Lifting(0);
    }
}

void RTPI_Functions::ControlPanel(){
    double speedJoystick = controllerinput->navigator->GetRawAxis(0);
    if(speedJoystick > 0.1 || speedJoystick < -0.1) {
        PiTalon->GetTalon()->Set(speedJoystick);
    }
    else {
        PiTalon->GetTalon()->Set(0);
    }
}

void RTPI_Functions::initStorage(double startPosition) {
    servoR->AngleControl(startPosition);
}

void RTPI_Functions::MoveStorage(double servoTimer) {
    if(controllerinput->navigator->GetRawButton(5)) {
        /*
        if((servoTimer - lastTimerValue) > servoSpeed) {
            if(servoR->GetServoAngle() > 0) {
                servoR->AngleControl(servoR->GetServoAngle() - 1);
            }
            lastTimerValue = servoTimer;
        }
        */
       initStorage(29);
    }
    else if(controllerinput->navigator->GetRawButton(6)) {
        /*
        if((servoTimer - lastTimerValue) > servoSpeed) {
            if(servoR->GetServoAngle() < 170) {
                servoR->AngleControl(servoR->GetServoAngle() + 1);
            }
            lastTimerValue = servoTimer;
        }
        */
       initStorage(0);
    }
}