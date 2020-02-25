#include "RTPI_SparkAlternateEncoder.h"

RTPI_SparkAlternateEncoder::RTPI_SparkAlternateEncoder(rev::CANSparkMax *encoderHostSpark){
//TODO: all the necessary setup
    enc = new rev::CANEncoder(*encoderHostSpark, rev::CANEncoder::AlternateEncoderType::kQuadrature, 8192);
}

rev::CANEncoder* RTPI_SparkAlternateEncoder::getEncoder(){
    return enc;
}

void RTPI_SparkAlternateEncoder::reset()
{
    enc->SetPosition(0);
}

double RTPI_SparkAlternateEncoder::getDistance()
{
    return enc->GetPosition()*dPerRot;
}

void RTPI_SparkAlternateEncoder::setDistPerRot(double dPerRot)
{
    this->dPerRot = dPerRot;
}

double RTPI_SparkAlternateEncoder::getDistPerRot()
{
    return this->dPerRot;
}

double RTPI_SparkAlternateEncoder::getRate()
{
    return enc->GetVelocity()*dPerRot/60;
}