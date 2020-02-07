#include "RTPI_ManualFunctions.h"

RTPI_ManualFunctions::RTPI_ManualFunctions(RTPI_Drivetrain *drivetrainF, RTPI_ControllerInput *inputF) {
  drivetrain = drivetrainF;
  input = inputF;
}

void RTPI_ManualFunctions::DriveRL() {
  drivetrain->Drive(input->driver->GetRawAxis(3) - input->driver->GetRawAxis(2), input->driver->GetRawAxis(0));
}

void RTPI_ManualFunctions::DriveFPS() {
  drivetrain->Drive(input->driver->GetRawAxis(1), input->driver->GetRawAxis(4));
}