/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc/smartdashboard/SmartDashboard.h>

#include "subsystems/Shooter.h"
#include "subsystems/Limelight.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class LogDataToDashboard
    : public frc2::CommandHelper<frc2::CommandBase, LogDataToDashboard> {
  public:
    explicit LogDataToDashboard(Shooter* subsystem, Limelight* subsystem2);

    void Execute() override;

  private:
    Shooter* shoot;
    Limelight* light;
};
