/*
-   Created By: Duncan Kikkert
-   Date: 6/02/2020
-   Time: 14:03
-   Class: RTPI_ControllerInput
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

  //Driver Buttons and POV's
  POVButton *driverPOVLeft;
  POVButton *driverPOVDown;
  POVButton *driverPOVRight;
  POVButton *driverPOVUp;

  //Navigator Buttons and POV's
  POVButton *navigatorPOVLeft;
  POVButton *navigatorPOVDown;
  POVButton *navigatorPOVRight;
  POVButton *navigatorPOVUp;
  
    
  RTPI_ControllerInput(int driveID, int navigatorID);

};