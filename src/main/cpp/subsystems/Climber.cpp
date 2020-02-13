/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Climber.h"

Climber::Climber() {}

// This method will be called once per scheduler run
void Climber::Periodic() {}

void Climber::ExtendClimber() {
    if (climber_position > ConClimber::EXT_LIMIT) { // Extending is NEGATIVE/DECREASING on the encoder
    SetClimberSpeed(0.5);
  }
  else {
    StopClimber();
  }
}

void Climber::RetractClimber() {
    if (climber_position < ConClimber::RET_LIMIT) { // Retracting is POSITIVE/INCREASING on the encoder
    SetClimberSpeed(0.5);
  }
  else {
    StopClimber();
  }
}

void Climber::StopClimber() {
    climb_motor.Set(0.0);
}

void Climber::SetClimberSpeed(double speed){
    climb_motor.Set(speed);
}

void Climber::ResetEncoder(){
  climb_duty_encoder.Reset();
}

// // This method will be called once per scheduler run
// void Climber::Periodic() {
//   climber_position = climb_duty_encoder.GetDistance();
// }