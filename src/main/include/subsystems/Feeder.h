/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>

#include "Constants.h"

class Feeder : public frc2::SubsystemBase {
 public:
  Feeder();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

  void SetFeedSpeed(double speed);

  void SetHopperSpeed(double speed);


 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
    WPI_TalonSRX feed_motor{ConFeeder::FEED_MOTOR};
    WPI_TalonSRX hopper_motor{ConFeeder::HOPPER_MOTOR};

};
