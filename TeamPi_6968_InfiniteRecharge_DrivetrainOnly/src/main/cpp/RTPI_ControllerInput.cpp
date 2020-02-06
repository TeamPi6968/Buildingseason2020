#include "RTPI_ControllerInput.h"

RTPI_ControllerInput::RTPI_ControllerInput(int driverID, int navigatorID){

    this->driver = new XboxController(driverID);
    this->navigator = new XboxController(navigatorID);
}
