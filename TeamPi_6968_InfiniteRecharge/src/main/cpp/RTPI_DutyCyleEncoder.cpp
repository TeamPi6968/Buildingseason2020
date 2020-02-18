#include "RTPI_DutyCycleEncoder.h"

RTPI_DutyCycleEncoder::RTPI_DutyCycleEncoder(int DIOChannel, double distancePerRotation) {
  this->rtpiDutyCycleEncoder = new DutyCycleEncoder(DIOChannel);
  rtpiDutyCycleEncoder->SetDistancePerRotation(distancePerRotation);
}

bool RTPI_DutyCycleEncoder::IsEncConnected() {
  return this->rtpiDutyCycleEncoder->IsConnected();
}

double RTPI_DutyCycleEncoder::GetEncFrequency() {
  return this->rtpiDutyCycleEncoder->GetFrequency();
}

double RTPI_DutyCycleEncoder::GetEncPosition() {
  return this->rtpiDutyCycleEncoder->Get().to<double>();
}

double RTPI_DutyCycleEncoder::GetEncDistance() {
  return this->rtpiDutyCycleEncoder->GetDistance();
}