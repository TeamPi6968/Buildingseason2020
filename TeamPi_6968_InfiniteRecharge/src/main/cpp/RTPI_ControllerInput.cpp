#include "RTPI_ControllerInput.h"

RTPI_ControllerInput::RTPI_ControllerInput(int DriverID, int NavigatorID){

    this->Driver = new XboxController(DriverID);
    this->Navigator = new XboxController(NavigatorID);
}
