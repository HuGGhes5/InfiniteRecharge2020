/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Feeder.h"

Feeder::Feeder() {}

// This method will be called once per scheduler run
void Feeder::Periodic() {}

void Feeder::SetFeedSpeed(double speed) {feed_motor.Set(speed);}

void Feeder::SetHopperSpeed(double speed) {hopper_motor.Set(speed);}