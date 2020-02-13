/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/LogDataToDashboard.h"

LogDataToDashboard::LogDataToDashboard(Shooter* subsystem1, Limelight* subsystem2, Drivetrain* subsystem3) : shoot{subsystem1}, light{subsystem2}, drive{subsystem3} {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called repeatedly when this Command is scheduled to run
void LogDataToDashboard::Execute() {
    //shooter subsystem
    frc::SmartDashboard::PutNumber("Top Motor Speed", shoot->GetTopMotorSpeed());
    frc::SmartDashboard::PutNumber("Bottom Motor Speed", shoot->GetBottomMotorSpeed());

    //limelight subsystem
    frc::SmartDashboard::PutNumber("Found Target", light->GetValidTarget());
    frc::SmartDashboard::PutNumber("Horizontal offset", light->GetHorizontalOffset());
    frc::SmartDashboard::PutNumber("Vertical offset", light->GetVerticalOffset());
    frc::SmartDashboard::PutNumber("Target Area", light->GetTargetArea());

    //drivetrain subsystem
    //frc::SmartDashboard::PutNumber("Gyro Angle", drive->GetGyroAngle);
}