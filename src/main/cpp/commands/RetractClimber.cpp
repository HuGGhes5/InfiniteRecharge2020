/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/RetractClimber.h"
#include "subsystems/Climber.h"

RetractClimber::RetractClimber(Climber* subsystem) : climb{subsystem} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({subsystem});
}

// Called repeatedly when this Command is scheduled to run
void RetractClimber::Initialize() {climb->RetractClimber();}

void RetractClimber::End(bool interrupted) {climb->StopClimber();}