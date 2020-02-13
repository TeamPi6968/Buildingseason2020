#include "RTPI_AutoFunctions.h"

RTPI_AutoFunctions::RTPI_AutoFunctions(RobotIO *_robotIO, RTPI_ControllerInput *_input, RTPI_Drivetrain *_drivetrain, RTPI_Intake *_intake, RTPI_Storage *_storage, RTPI_Outtake *_outtake) {
  robotIO = _robotIO;
  input = _input;
  drivetrain = _drivetrain;
  intake = _intake;
  storage = _storage;
  outtake = _outtake;
}

bool RTPI_AutoFunctions::stopAutoFunction() {
  if(input->navigator->GetRawButton(7) || input->driver->GetRawButton(7)) {
    return true;
  }
  else {
    return false;
  }
}

void RTPI_AutoFunctions::moveStorageFifth() {
  robotIO->storageRevolverBState0 = input->navigatorPOVUp->Get();

  if(robotIO->storageRevolverBState0 != robotIO->lastStorageRevolverBState0) {
    if(robotIO->storageRevolverBState0) {
      this->storage->moveFifth();
    }
    robotIO->lastStorageRevolverBState0 = robotIO->storageRevolverBState0;
  }
}
//AUTOSHOOTING:

/*void RTPI_AutoFunctions::AutomaticShooting(){
    float distance = GetSensor();  ELOBOU SENSOR
    double v0 = 0;
    v0 = sqrt((0.525+distance * tan(35) - 9.81 * distance * distance) * (cos(35) * cos(35)) / 2.49);
}
*/
