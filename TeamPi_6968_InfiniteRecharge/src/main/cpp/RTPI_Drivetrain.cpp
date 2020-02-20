#include "RTPI_Drivetrain.h"
#include <frc/geometry/Rotation2d.h>
#include <frc/kinematics/DifferentialDriveWheelSpeeds.h>

RTPI_Drivetrain::RTPI_Drivetrain(RTPI_SparkMax *drivetrainMasterL, RTPI_SparkMax *drivetrainSlaveL, RTPI_SparkMax *drivetrainMasterR, RTPI_SparkMax *drivetrainSlaveR)
{
  sparkLM = drivetrainMasterL;
  sparkLS = drivetrainSlaveL;
  sparkRM = drivetrainMasterR;
  sparkRS = drivetrainSlaveR;

  //this->sparkLS->GetSparkMax()->Follow(*sparkLM->GetSparkMax());
  //this->sparkRS->GetSparkMax()->Follow(*sparkRM->GetSparkMax());

  //set the encoders assuming they are connected to the master speed controllers
  this->encoderL = new RTPI_SparkAlternateEncoder(sparkLM->GetSparkMax());
  this->encoderR = new RTPI_SparkAlternateEncoder(sparkRM->GetSparkMax());

  m_odometry = new frc::DifferentialDriveOdometry(this->gyroAngle);

  encoderL->reset();
  encoderR->reset();

  this->diffDrive = new DifferentialDrive(*sparkLM->GetSparkMax(), *sparkRM->GetSparkMax());
}

void RTPI_Drivetrain::Drive(double linearSpeed, double rotationSpeed)
{
  this->diffDrive->ArcadeDrive(linearSpeed, -rotationSpeed);
}

void RTPI_Drivetrain::periodic()
{
  m_odometry->Update(frc::Rotation2d(units::degree_t(GetHeading())),
                    units::meter_t(encoderL->getDistance()),
                    units::meter_t(encoderR->getDistance()));

    std::cout<<"Rotation: "<<m_odometry->GetPose().Rotation().Degrees()<<"Translation: ";
    std::cout<<m_odometry->GetPose().Translation().X()<<" , "<<m_odometry->GetPose().Translation().Y()<<"\n";         
}

void RTPI_Drivetrain::TankDriveVolts(units::volt_t left, units::volt_t right)
{
  sparkLM->GetSparkMax()->SetVoltage(left);
  sparkRM->GetSparkMax()->SetVoltage(right);
  diffDrive->Feed();
}

void RTPI_Drivetrain::ResetEncoders()
{
  encoderR->reset();
  encoderL->reset();
}

double RTPI_Drivetrain::GetAverageEncoderDistance()
{
  return (encoderL->getDistance() + encoderR->getDistance()) / 2.0;
}

void RTPI_Drivetrain::SetMaxOutput(double maxOutput)
{
  diffDrive->SetMaxOutput(maxOutput);
}

double RTPI_Drivetrain::GetHeading()
{
  double xyz[3];
  imu->getPigeon()->GetAccumGyro(xyz);
  return std::remainder(xyz[2], 360) * (DriveConstants::kGyroReversed ? -1.0 : 1.0);
}

double RTPI_Drivetrain::GetTurnRate()
{
  double xyz[3];
  imu->getPigeon()->GetRawGyro(xyz);
  return xyz[2] * (DriveConstants::kGyroReversed ? -1.0 : 1.0);
}

frc::Pose2d RTPI_Drivetrain::GetPose()
{
  return m_odometry->GetPose();
}

frc::DifferentialDriveWheelSpeeds RTPI_Drivetrain::GetWheelSpeeds()
{
  return {units::meters_per_second_t(encoderL->getRate()),
          units::meters_per_second_t(encoderR->getRate())};
}

void RTPI_Drivetrain::ResetOdometry(frc::Pose2d pose)
{
  ResetEncoders();
  m_odometry->ResetPosition(pose,
                           frc::Rotation2d(units::degree_t(GetHeading())));
}