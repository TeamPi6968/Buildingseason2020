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
  double mapDouble(double input, double minInput, double maxInput, double minOutput, double maxOutput); //Maps a number to another range
  double transmissionTransfer(double input, double transmissionInput, double transmissionOutput); //Calculates the output of a gearbox. Insert the rotation input and give the transmissionInput and Output (transIn:TransOut)
};