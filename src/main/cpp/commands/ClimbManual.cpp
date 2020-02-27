/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ClimbManual.h"

ClimbManual::ClimbManual(Climber* subsystem, frc::Joystick* controller)
              : climb{subsystem}, codriver_controller{controller} {
  AddRequirements({subsystem});
}

// Called when the command is initially scheduled.
void ClimbManual::Initialize(){ climb->Unlock(); }

// Called repeatedly when this Command is scheduled to run
void ClimbManual::Execute() {
  double speed = codriver_controller->GetRawAxis(ConCoDriverController::RIGHT_STICK_Y);
  climb->SetClimberSpeed(speed);
}

void ClimbManual::End(bool interrupted) { climb->Lock(); }

bool ClimbManual::IsFinished() {return false;}