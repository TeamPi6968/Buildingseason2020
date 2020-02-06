#pragma once

#include "RTPI_Drivetrain.h"
#include "RTPI_ControllerInput.h"

using namespace frc;

class RTPI_ManualDrive {
    private:
    RTPI_ControllerInput *input;
    RTPI_Drivetrain *drivetrain;

    public:
    void ManualMovement(double driveForward, double driveBackward);
    RTPI_ManualDrive(RTPI_Drivetrain *drivetrainF, RTPI_ControllerInput *inputF);
};