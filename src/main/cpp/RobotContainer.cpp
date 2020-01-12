/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc2/command/button/JoystickButton.h>

#include "Constants.h"
#include "commands/DefaultDrive.h"
#include "commands/ExtendClimber.h"
#include "commands/HalfSpeedDrive.h"
#include "commands/RetractClimber.h"

#include "RobotContainer.h"

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here
  

  // Configure the button bindings
  ConfigureButtonBindings();

  // Set up default drive command
   drive.SetDefaultCommand(DefaultDrive(
       &drive,
       [this] { return driver_controller.GetRawAxis(ConXBOXController::RIGHT_TRIGGER_ID) - driver_controller.GetRawAxis(ConXBOXController::LEFT_TRIGGER_ID); },
       [this] { return driver_controller.GetRawAxis(ConXBOXController::RIGHT_JOYSTICK_X); }));

  
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here

  // Commence Half Speed driving when RB is pressed
  frc2::JoystickButton(&driver_controller, ConXBOXController::RIGHT_BUMPER)
      .WhenHeld(new HalfSpeedDrive(&drive));

  // Extend Climber when 'A' button is held.
  // frc2::JoystickButton(&driverController, ConXBOXController::A)
  //     .WhileHeld(new ExtendClimber(&climb_motor));
  // Retract Climber when 'B' button is held.
  // frc2::JoystickButton(&driverController, ConXBOXController::B)
  //     .WhileHeld(new RetractClimber(&climb_motor));
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &simple_auto;
}
