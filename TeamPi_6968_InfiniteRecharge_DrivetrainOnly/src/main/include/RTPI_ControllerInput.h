/*
-   Created By: Duncan Kikkert
-   Date: 6/02/2020
-   Time: 14:03
-   Class: Manual Functions
*/

#pragma once

#include <frc/XboxController.h>
#include <frc/GenericHID.h>

using namespace frc;

class RTPI_ControllerInput {

    private:
    
    public:
    XboxController *driver;
    XboxController *navigator;
    
    RTPI_ControllerInput(int driveID, int navigatorID);

};