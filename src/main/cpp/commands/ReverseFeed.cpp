/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#include <frc/smartdashboard/SmartDashboard.h>

#include "commands/ReverseFeed.h"

ReverseFeed::ReverseFeed(Shooter* subsystem) : shoot{subsystem} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({subsystem});
}

// Called repeatedly when this Command is scheduled to run
void ReverseFeed::Execute() {shoot->SetHopperSpeed(- frc::SmartDashboard::GetNumber("Hopper Speed", 0.0));}

// Called once the command ends or is interrupted.
void ReverseFeed::End(bool interrupted) {shoot->SetHopperSpeed(0.0);}

