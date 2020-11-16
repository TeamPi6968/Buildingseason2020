/*
-   Created By: Jesper Weijnen
-   Date: 06-02-2020
-   Time: 14:20
-   Class: RTPI_Drivetrain
*/

#pragma once

#include "RTPI_SparkMax.h"
#include "RTPI_SparkAlternateEncoder.h"
#include "RTPI_IMU.h"
#include <frc/drive/DifferentialDrive.h>

//auto trajectory stuff:
#include <frc/ADXRS450_Gyro.h>
#include <frc/Encoder.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/geometry/Pose2d.h>
#include <frc/kinematics/DifferentialDriveOdometry.h>
#include <units/units.h>
#include "ctre/Phoenix.h"

#include "Constants.h"

using namespace frc;

class RTPI_Drivetrain
{
private:
  //the motors
  RTPI_SparkMax *sparkLM;
  RTPI_SparkMax *sparkLS;
  RTPI_SparkMax *sparkRM;
  RTPI_SparkMax *sparkRS;
  //the encoders
  RTPI_SparkAlternateEncoder *encoderL;
  RTPI_SparkAlternateEncoder *encoderR;
  //the imu
  RTPI_IMU *imu;

  //the drive
  DifferentialDrive *diffDrive;

  // The gyro sensor
  frc::ADXRS450_Gyro m_gyro;

  // Odometry class for tracking robot pose
  Rotation2d gyroAngle;
  frc::DifferentialDriveOdometry *m_odometry;
  CANPIDController *LMcontroller;

public:
  RTPI_Drivetrain(RTPI_SparkMax *drivetrainMasterL, RTPI_SparkMax *drivetrainSlaveL, RTPI_SparkMax *drivetrainMasterR, RTPI_SparkMax *drivetrainSlaveR,RTPI_IMU *imu);
  void Drive(double linearSpeed, double rotationSpeed);

  //DESCRIPTION:
  //  This function must be called in the robot::periodic function
  void periodic();

  /**
   * Controls each side of the drive directly with a voltage.
   *
   * @param left the commanded left output
   * @param right the commanded right output
   */
  void TankDriveVolts(units::volt_t left, units::volt_t right);

  /**
   * Gets the average distance of the TWO encoders.
   *
   * @return the average of the TWO encoder readings
   */
  double GetAverageEncoderDistance();

  /**
   * Sets the max output of the drive.  Useful for scaling the drive to drive
   * more slowly.
   *
   * @param maxOutput the maximum output to which the drive will be constrained
   */
  void SetMaxOutput(double maxOutput);

  /**
   * Returns the heading of the robot.
   *
   * @return the robot's heading in degrees, from 180 to 180
   */
  double GetHeading();

  /**
   * Returns the turn rate of the robot.
   *
   * @return The turn rate of the robot, in degrees per second
   */
  double GetTurnRate();

  /**
   * Returns the currently-estimated pose of the robot.
   *
   * @return The pose.
   */
  frc::Pose2d GetPose();

  /**
   * Returns the current wheel speeds of the robot.
   *
   * @return The current wheel speeds.
   */
  frc::DifferentialDriveWheelSpeeds GetWheelSpeeds();

  /**
   * Resets the odometry to the specified pose.
   *
   * @param pose The pose to which to set the odometry.
   */
  void ResetOdometry(frc::Pose2d pose);

  /**
   * Resets the drive encoders to currently read a position of 0.
   */
  void ResetEncoders();

  void InitPID(double Pgain, double Igain, double Dgain);
  void DrivePID();
};