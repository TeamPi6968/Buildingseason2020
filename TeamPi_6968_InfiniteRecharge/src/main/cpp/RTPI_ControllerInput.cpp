#include "RTPI_ControllerInput.h"

RTPI_ControllerInput::RTPI_ControllerInput(int DriverID, int NavigatorID){

    this->DriveController = new XboxController(DriverID);
    this->NavController = new XboxController(NavigatorID);
}
