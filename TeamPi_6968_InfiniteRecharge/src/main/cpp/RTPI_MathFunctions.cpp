#include "RTPI_MathFunctions.h"

double RTPI_MathFunctions::mapDouble(double input, double minInput, double maxInput, double minOutput, double maxOutput) {
  return (input - minInput) * (maxOutput - minOutput) / (maxInput - minInput) + minOutput;
}

double RTPI_MathFunctions::transmissionTransfer(double rotationInput, double transmissionInput, double transmissionOutput) {
  return (rotationInput * transmissionOutput) / transmissionInput;
}