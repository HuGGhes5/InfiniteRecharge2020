/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Constants.h"
#include "subsystems/Drivetrain.h"

Drivetrain::Drivetrain() {}

// This method will be called once per scheduler run
void Drivetrain::Periodic() {}

double Drivetrain::DeadZoneCorrection(double axis_value) {
    return (axis_value <= ConXBOXController::DEAD_ZONE && axis_value >= -ConXBOXController::DEAD_ZONE) ? 0.0:axis_value;
}

void Drivetrain::ArcadeDrive(double speed, double rot) {
    drive.ArcadeDrive(speed, DeadZoneCorrection(rot));
}

double Drivetrain::GetMaxOutput() {
    return max_output; 
}

void Drivetrain::SetMaxOutput(double max_output) {
    this->max_output = max_output;
    drive.SetMaxOutput(max_output);
}

//This is autonomous code that needs to get updated to real things afterwards
void Drivetrain::ResetEncoders() {
  left_encoder.SetPosition(0);
  right_encoder.SetPosition(0);
}

double Drivetrain::GetAverageEncoderDistance() {
  return (left_encoder.GetPosition() + right_encoder.GetPosition()) / 2.0;
}