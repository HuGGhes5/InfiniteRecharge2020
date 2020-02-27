/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Climber.h"

Climber::Climber() {}

void Climber::StopClimber() {
    climb_motor.Set(0.0);
}

void Climber::SetClimberSpeed(double speed){
  if (((climber_position < ConClimber::RET_LIMIT) && speed < 0.0) || ((climber_position > ConClimber::EXT_LIMIT) && speed > 0.0))
    {
      this->StopClimber();
    }
  else if (climb_enable) 
    {
      climb_motor.Set(speed);
    }
}

void Climber::Unlock(){
  climb_enable = true;
  climber_lock.Set(frc::DoubleSolenoid::kReverse);
}

void Climber::Lock(){
  climb_enable = false;
  this->StopClimber();
  climb_motor.Set(0.0);
  climber_lock.Set(frc::DoubleSolenoid::kForward);

}

void Climber::ResetEncoder(){
  climb_duty_encoder.Reset();
}

// This method will be called once per scheduler run
void Climber::Periodic() {
  climber_position = climb_duty_encoder.GetDistance();
}