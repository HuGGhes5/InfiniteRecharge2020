/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AlignCrossHair.h"

AlignCrossHair::AlignCrossHair(Drivetrain* subsystem1, Limelight* subsystem2) :  drive{subsystem1}, light{subsystem2} {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void AlignCrossHair::Initialize() {
  //light->SetCamMode(ConLimelight::VISION_MODE);
  //drive->ArcadeDrive(0, 0);
  double x_offset = light->GetHorizontalOffset();
  drive->ArcadeDrive(0.1, (x_offset/ConLimelight::MAX_HORIZONTAL_OFFSET)*.5);
}

// Called repeatedly when this Command is scheduled to run
void AlignCrossHair::Execute() {
  double x_offset = light->GetHorizontalOffset(); //angle 

  drive->ArcadeDrive(0.1, (x_offset/ConLimelight::MAX_HORIZONTAL_OFFSET)*.5);
}

// Called once the command ends or is interrupted.
void AlignCrossHair::End(bool interrupted) {}

// Returns true when the command should end.
bool AlignCrossHair::IsFinished() { return abs(light->GetHorizontalOffset()) < ConLimelight::HORIZONTAL_TOLERANCE; }
