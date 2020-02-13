/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Jumble.h"

Jumble::Jumble(Feeder* subsystem) : feed{subsystem} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({subsystem});
}

// Called repeatedly when this Command is scheduled to run
void Jumble::Execute() {feed->SetHopperSpeed(2.0/3.0);}

// Called once the command ends or is interrupted.
void Jumble::End(bool interrupted) {feed->SetHopperSpeed(0.0);}

