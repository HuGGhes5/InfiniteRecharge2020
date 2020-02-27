/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/DutyCycleEncoder.h>
#include <frc/DoubleSolenoid.h>
#include <frc/Joystick.h>
#include <rev/CANSparkMax.h>

#include "Constants.h"

class Climber : public frc2::SubsystemBase {
 public:
  Climber();

  void StopClimber();

  void SetClimberSpeed(double speed);

  void ResetEncoder();

  void Unlock();

  void Lock();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  rev::CANSparkMax climb_motor{ConClimber::CLIMB_MOTOR, rev::CANSparkMax::MotorType::kBrushless};
  frc::DutyCycleEncoder climb_duty_encoder{0};
  double climber_position = 0.0;

  frc::DoubleSolenoid climber_lock{ConClimber::SOLENOID_LOCK_ID, ConClimber::SOLENOID_UNLOCK_ID};
  bool climb_enable = false;
};