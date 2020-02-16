/*
-   Created By: Jesper Weijnen
-   Date: 10-02-2020
-   Time: 21:44
-   Class: RTPI_MathFunctions
*/

#pragma once

class RTPI_MathFunctions {
 private:

 public:
  double MapDouble(double input, double minInput, double maxInput, double minOutput, double maxOutput); //Maps a number to another range
  double TransmissionTransfer(double input, double transmissionInput, double transmissionOutput); //Calculates the output of a gearbox. Insert the rotation input and give the transmissionInput and Output (transmissionInput:transmissionOutpu)
  double TransmissionTransferReversed(double output, double transmissionInput, double transmissionOutput); //Calculates the input of a gearbox. Insert the rotation output and give the transmissionInput and Output (transmissionInput:transmissionOutput)
};