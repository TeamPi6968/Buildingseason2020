#include "RTPI_Functions.h"

RTPI_Functions::RTPI_Functions(RTPI_Drivetrain *_drivetrain, RTPI_ControllerInput *_controllerinput, RTPI_Climbing *_climb){
    this->drivetrain = _drivetrain;
    this->controllerinput = _controllerinput;
    this->climb = _climb;
    this->PiTalon = new RTPI_Talon(7);
}

void RTPI_Functions::DriveRL(){
    drivetrain->Driving(controllerinput->driver->GetRawAxis(3) - controllerinput->driver->GetRawAxis(2), controllerinput->driver->GetRawAxis(0));
}

void RTPI_Functions::Climbe(){
    if(controllerinput->navigator->GetRawButton(4)){
        climb->Climbing();
    }
    else if(controllerinput->navigator->GetRawButton(1)){
        climb->ClimbDown();
    }
    else {
        climb->DoNothing();
    }
}

void RTPI_Functions::AutoDrive(){
    drivetrain->Driving(1,0);
}

void RTPI_Functions::ControlPanel(){
    if(controllerinput->navigator->GetRawButton(2)) {
        this->PiTalon->GetTalon()->Set(1);
    }
    else if(controllerinput->navigator->GetRawButton(3)){
        this->PiTalon->GetTalon()->Set(-1);
    }
    else {
        this->PiTalon->GetTalon()->Set(0);
    }
}