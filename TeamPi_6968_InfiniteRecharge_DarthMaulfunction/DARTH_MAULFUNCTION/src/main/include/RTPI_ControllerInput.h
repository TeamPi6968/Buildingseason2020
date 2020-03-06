#pragma once

#include <frc/XboxController.h>
//#include "frc/buttons/POVButton.h"

using namespace frc;

class RTPI_ControllerInput {
    public:
    XboxController *driver;
    XboxController *navigator;

    RTPI_ControllerInput(int DriverID, int NavigatorID);
    private:
};