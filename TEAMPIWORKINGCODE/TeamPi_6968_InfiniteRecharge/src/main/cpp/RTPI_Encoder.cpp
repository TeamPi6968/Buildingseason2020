#include "RTPI_Encoder.h"

RTPI_Encoder::RTPI_Encoder(rev::CANSparkMax *encoderHostSpark){
//TODO: all the necessary setup
    enc = new rev::CANEncoder(*encoderHostSpark, rev::CANEncoder::AlternateEncoderType::kQuadrature, 8192);

}

rev::CANEncoder* RTPI_Encoder::getEncoder(){
    return enc;
}

void RTPI_Encoder::reset()
{
    enc->SetPosition(0);
}

double RTPI_Encoder::getDistance()
{
    return enc->GetPosition()*dPerRot;
}

void RTPI_Encoder::setDistPerRot(double dPerRot)
{
    this->dPerRot = dPerRot;
}

double RTPI_Encoder::getDistPerRot()
{
    return this->dPerRot;
}

double RTPI_Encoder::getRate()
{
    return enc->GetVelocity()*dPerRot/60;
}