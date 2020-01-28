/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"

#include "Constants.h"

class Limelight : public frc2::SubsystemBase {
 public:
  Limelight();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

  double GetValidTarget();

  double GetHorizontalOffset();

  double GetVerticalOffset();

  double GetTargetArea();

  double GetTargetDistance();

  void SetLEDMode(int mode);

  void SetCamMode(int mode);

  void SetSnapshot(int mode);

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  std::shared_ptr<NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");

};
