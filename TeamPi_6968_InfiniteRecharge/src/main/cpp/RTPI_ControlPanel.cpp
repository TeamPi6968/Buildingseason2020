#include "RTPI_ControlPanel.h"

RTPI_ControlPanel::RTPI_ControlPanel(RTPI_SparkMax *_sparkCP, RTPI_ColorSensor *_colorSensor, RTPI_Pneumatics *_pistonCP)
{
  sparkCP = _sparkCP;
  colorSensor = _colorSensor;
  pistonCP = _pistonCP;

  this->colorMatcher = new ColorMatch();

  colorMatcher->AddColorMatch(kBlueTarget);
  colorMatcher->AddColorMatch(kGreenTarget);
  colorMatcher->AddColorMatch(kRedTarget);
  colorMatcher->AddColorMatch(kYellowTarget);
  colorMatcher->AddColorMatch(kFakeYellowTarget1);
  preColorString = "Unknown";
}

void RTPI_ControlPanel::spinCPWheels(double speed)
{
  this->sparkCP->GetSparkMax()->Set(speed);
}

void RTPI_ControlPanel::moveCPPiston(enum DoubleSolenoid::Value direction)
{
  this->pistonCP->GetDoubleSolenoid()->Set(direction);
}

void RTPI_ControlPanel::ColorCounter()
{
  frc::Color detectedColor = colorSensor->GetColorSensor()->GetColor();
  frc::Color matchedColor = colorMatcher->MatchClosestColor(detectedColor, confidence);

  if (matchedColor == kBlueTarget)
  {
    if (preColorString == "Yellow")
    {
      colorCount++;
    }
    else if (preColorString == "Green")
    {
      colorCount--;
    }
    colorString = "Blue";
    preColorString = "Blue";
  }

  else if (matchedColor == kRedTarget)
  {
    if (preColorString == "Green")
    {
      colorCount++;
    }
    else if (preColorString == "Yellow")
    {
      colorCount--;
    }
    preColorString = "Red";
    colorString = "Red";
  }

  else if (matchedColor == kGreenTarget)
  {
    if (preColorString == "Blue")
    {
      colorCount++;
    }
    else if (preColorString == "Red")
    {
      colorCount--;
    }
    preColorString = "Green";
    colorString = "Green";
  }

  else if (matchedColor == kYellowTarget)
  {
    if (preColorString == "Red")
    {
      colorCount++;
    }
    else if (preColorString == "Blue")
    {
      colorCount--;
    }
    preColorString = "Yellow";
    colorString = "Yellow";
  }

  else if (matchedColor == kFakeYellowTarget1)
  {
    colorString = "fake yellow";
  }

  else
  {
    colorString = "Unknown";
  }

  frc::SmartDashboard::PutNumber("Red", detectedColor.red);
  frc::SmartDashboard::PutNumber("Green", detectedColor.green);
  frc::SmartDashboard::PutNumber("Blue", detectedColor.blue);
  frc::SmartDashboard::PutNumber("colourcount", colorCount);
  frc::SmartDashboard::PutNumber("Confidence", confidence);
  frc::SmartDashboard::PutString("Detected Color", colorString);
  frc::SmartDashboard::PutString("precolourstring", preColorString);
  frc::SmartDashboard::PutString("colourstring", colorString);
}

void RTPI_ControlPanel::AutoColourAndCount()
{
  while (colorCount <= 12)
  {
    frc::Color detectedColor = colorSensor->GetColorSensor()->GetColor();
    frc::Color matchedColor = colorMatcher->MatchClosestColor(detectedColor, confidence);

    if (matchedColor == kBlueTarget)
    {
      if (preColorString == "Yellow")
      {
        colorCount++;
      }
      else if (preColorString == "Green")
      {
        colorCount--;
      }

      colorString = "Blue";
      preColorString = "Blue";
    }

    else if (matchedColor == kRedTarget)
    {
      if (preColorString == "Green")
      {
        colorCount++;
      }
      else if (preColorString == "Yellow")
      {
        colorCount--;
      }

      preColorString = "Red";
      colorString = "Red";
    }

    else if (matchedColor == kGreenTarget)
    {
      if (preColorString == "Blue")
      {
        colorCount++;
      }
      else if (preColorString == "Red")
      {
        colorCount--;
      }

      preColorString = "Green";
      colorString = "Green";
    }

    else if (matchedColor == kYellowTarget)
    {
      if (preColorString == "Red")
      {
        colorCount++;
      }
      else if (preColorString == "Blue")
      {
        colorCount--;
      }

      preColorString = "Yellow";
      colorString = "Yellow";
    }

    else if (matchedColor == kFakeYellowTarget1)
    {
      colorString = "fake yellow";
    }

    else
    {
      colorString = "Unknown";
    }

    frc::SmartDashboard::PutNumber("Red", detectedColor.red);
    frc::SmartDashboard::PutNumber("Green", detectedColor.green);
    frc::SmartDashboard::PutNumber("Blue", detectedColor.blue);
    frc::SmartDashboard::PutNumber("colourcount", colorCount);
    frc::SmartDashboard::PutNumber("Confidence", confidence);
    frc::SmartDashboard::PutString("Detected Color", colorString);
    frc::SmartDashboard::PutString("precolourstring", preColorString);
    frc::SmartDashboard::PutString("colourstring", colorString);
  }
}
