/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ExtendClimber.h"
#include "subsystems/ClimbMech.h"

ExtendClimber::ExtendClimber(ClimbMech* subsystem) : climb_motor{subsystem} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({subsystem});
}

// Called repeatedly when this Command is scheduled to run
void ExtendClimber::Initialize() {}

void ExtendClimber::Execute() {climb_motor->ExtendClimber();}

bool ExtendClimber::IsFinished() {return false;}

void ExtendClimber::End(bool interrupted) {climb_motor->StopClimber();}