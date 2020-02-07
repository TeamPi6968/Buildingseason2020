#include "RTPI_ControllerInput.h"

RTPI_ControllerInput::RTPI_ControllerInput(int driverID, int navigatorID) {
  //Config Controllers
  this->driver = new XboxController(driverID);
  this->navigator = new XboxController(navigatorID);

  //Driver POV Buttons
  this->driverPOVLeft = new POVButton(*driver, 270);
  this->driverPOVDown = new POVButton(*driver, 180);
  this->driverPOVRight = new POVButton(*driver, 90);
  this->driverPOVUp = new POVButton(*driver, 0);
}
