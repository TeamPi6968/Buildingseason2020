#pragma once

#include "RTPI_Drivetrain.h"
#include "RTPI_ControllerInput.h"
#include "RTPI_Climbing.h"
#include "RTPI_Talon.h"

class RTPI_Functions {
    private:
        RTPI_Drivetrain *drivetrain;
        RTPI_ControllerInput *controllerinput;
        RTPI_Climbing *climb;
        RTPI_Talon *PiTalon;
    public:
        RTPI_Functions(RTPI_Drivetrain *_drivetrain, RTPI_ControllerInput *_controllerinput, RTPI_Climbing *_climb);
        void DriveRL();
        void Climbe();
        void AutoDrive();
        void ControlPanel();
};