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

  //Navigator POV Buttons
  this->navigatorPOVLeft = new POVButton(*navigator, 270);
  this->navigatorPOVDown = new POVButton(*navigator, 180);
  this->navigatorPOVRight = new POVButton(*navigator, 90);
  this->navigatorPOVUp = new POVButton(*navigator, 0);
}
