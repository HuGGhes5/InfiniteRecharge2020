/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/smartdashboard/SmartDashboard.h>

#include "commands/Shoot.h"

Shoot::Shoot(Shooter* subsystem1, Feeder* subsystem2) : shoot{subsystem1}, feed{subsystem2} {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void Shoot::Execute() {
  shoot->SetBottomMotorSpeed(frc::SmartDashboard::GetNumber("Bottom Motor RPM", 0.0));
  shoot->SetTopMotorSpeed(frc::SmartDashboard::GetNumber("Top Motor RPM", 0.0));
  feed->SetFeedSpeed(frc::SmartDashboard::GetNumber("Feeder Speed", 0.0));
}

// Returns true when the command should end.
// bool Shoot::IsFinished() { return true; }
void Shoot::End(bool interupted) {
  shoot->SetBottomMotorSpeed(0.0);
  shoot->SetTopMotorSpeed(0.0);
  feed->SetFeedSpeed(0.0);
}