#include "RTPI_MathFunctions.h"

double RTPI_MathFunctions::MapDouble(double input, double minInput, double maxInput, double minOutput, double maxOutput) {
  return (input - minInput) * (maxOutput - minOutput) / (maxInput - minInput) + minOutput;
}

double RTPI_MathFunctions::TransmissionTransfer(double rotationInput, double transmissionInput, double transmissionOutput) {
  return (rotationInput * transmissionOutput) / transmissionInput;
}

double RTPI_MathFunctions::TransmissionTransferReversed(double output, double transmissionInput, double transmissionOutput) {
  return (output * transmissionInput) / transmissionOutput;
}