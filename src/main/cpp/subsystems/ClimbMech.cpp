/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ClimbMech.h"

ClimbMech::ClimbMech() {}

// This method will be called once per scheduler run
void ClimbMech::Periodic() {}

void ClimbMech::ExtendClimber() {
    climb_motor.Set(0.3);
}

void ClimbMech::RetractClimber() {
    climb_motor.Set(-0.3);
}

void ClimbMech::StopClimber() {
    climb_motor.Set(0.0);
}