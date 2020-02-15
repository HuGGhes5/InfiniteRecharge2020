/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/HalfSpeedDrive.h"

HalfSpeedDrive::HalfSpeedDrive(Drivetrain* subsystem) : drive(subsystem){
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void HalfSpeedDrive::Initialize() {
  double max_output = drive->GetMaxOutput()*(3.0/4.0);
  drive->SetMaxOutput(max_output);
  }

// Called once the command ends or is interrupted.
void HalfSpeedDrive::End(bool interrupted) {
  double max_output = drive->GetMaxOutput()*(4.0/3.0);
  drive->SetMaxOutput(max_output);
  }

