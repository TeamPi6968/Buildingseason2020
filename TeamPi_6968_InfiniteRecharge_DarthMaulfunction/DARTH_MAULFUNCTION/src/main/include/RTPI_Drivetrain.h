#pragma once

#include "RTPI_Talon.h"
#include "RTPI_ControllerInput.h"
#include "frc/drive/DifferentialDrive.h"
#include "ctre/Phoenix.h"

using namespace frc;

class RTPI_Drivetrain {
    public:

        RTPI_Drivetrain(RTPI_Talon *MasterL, RTPI_Talon *SlaveL, RTPI_Talon *MasterR, RTPI_Talon *SlaveR/*, RTPI_ControllerInput *_input*/);
        void Driving(double driveSpeed, double rotationSpeed);
    private:
        RTPI_Talon *TalonML, *TalonSL, *TalonMR, *TalonSR;
        DifferentialDrive *DDrive;
};