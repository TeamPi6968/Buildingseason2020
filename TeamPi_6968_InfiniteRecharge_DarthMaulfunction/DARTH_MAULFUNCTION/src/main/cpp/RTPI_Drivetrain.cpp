#include "RTPI_Drivetrain.h"

RTPI_Drivetrain::RTPI_Drivetrain(RTPI_Talon *MasterL, RTPI_Talon *SlaveL, RTPI_Talon *MasterR, RTPI_Talon *SlaveR/*, RTPI_ControllerInput *_input*/){
    TalonML = MasterL;
    TalonSL = SlaveL;
    TalonMR = MasterR;
    TalonSR = SlaveR;

    this->TalonSL->GetTalon()->Follow(*TalonML->GetTalon());
    this->TalonSR->GetTalon()->Follow(*TalonMR->GetTalon());

    this->DDrive = new DifferentialDrive(*TalonML->GetTalon(), *TalonMR->GetTalon());
}

void RTPI_Drivetrain::Driving(double driveSpeed, double rotationSpeed){
    this->DDrive->ArcadeDrive(driveSpeed, rotationSpeed);
}