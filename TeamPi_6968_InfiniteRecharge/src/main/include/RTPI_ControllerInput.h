/*
-   Created By: Duncan Kikkert
-   Date: 6/02/2020
-   Time: 14:03
-   Class: Manual Functions
*/

#pragma once

#include <frc/XboxController.h>
#include "frc/buttons/POVButton.h"

using namespace frc;

class RTPI_ControllerInput {
 private:
    
 public:
  XboxController *driver;
  XboxController *navigator;

  //Driver Buttons
  POVButton *driverPOVLeft;
  POVButton *driverPOVDown;
  POVButton *driverPOVRight;
  POVButton *driverPOVUp;
    
  RTPI_ControllerInput(int driveID, int navigatorID);

};