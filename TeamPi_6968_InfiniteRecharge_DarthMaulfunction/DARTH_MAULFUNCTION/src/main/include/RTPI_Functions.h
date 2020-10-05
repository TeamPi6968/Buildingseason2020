#pragma once

#include "RTPI_Drivetrain.h"
#include "RTPI_ControllerInput.h"
#include "RTPI_Climbing.h"
#include "RTPI_Talon.h"
#include "RTPI_Servo.h"

class RTPI_Functions {
    private:
        RTPI_Drivetrain *drivetrain;
        RTPI_ControllerInput *controllerinput;
        RTPI_Climbing *climb;
        RTPI_Talon *PiTalon;
        RTPI_Servo *servoR;
        double lastTimerValue = 0;
        double servoSpeed = 0.00001; //(seconds)
    public:
        RTPI_Functions(RTPI_Drivetrain *_drivetrain, RTPI_ControllerInput *_controllerinput, RTPI_Climbing *_climb, RTPI_Servo *_servoR);
        void DriveRL();
        void Climber(int climbUpB, int climbDownB);
        void Lifter(int liftUpB, int liftDownB);
        void Drive(double linearSpeed, double rotationSpeed);
        void ControlPanel();
        void initStorage(double startPosition);
        void MoveStorage(double servoTimer);
};