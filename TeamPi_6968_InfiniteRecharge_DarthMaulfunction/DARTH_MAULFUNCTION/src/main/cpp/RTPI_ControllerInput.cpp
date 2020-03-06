#include "RTPI_ControllerInput.h"

RTPI_ControllerInput::RTPI_ControllerInput(int DriverID, int NavigatorID){
    this->driver = new XboxController(DriverID);
    this->navigator = new XboxController(NavigatorID);
}