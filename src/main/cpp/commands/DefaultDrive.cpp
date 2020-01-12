/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DefaultDrive.h"

DefaultDrive::DefaultDrive(Drivetrain* subsystem, std::function<double()> forwardSpeed, std::function<double()> rotationSpeed)
              : drive{subsystem}, speed{forwardSpeed}, rotation{rotationSpeed} {
  AddRequirements({subsystem});
}

// Called repeatedly when this Command is scheduled to run
void DefaultDrive::Execute() {
  drive->ArcadeDrive(speed(), rotation());
}
