/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/drive/DifferentialDrive.h>
#include <rev/CANSparkMax.h>

#include "Constants.h"
#include "AHRS.h"


class Drivetrain : public frc2::SubsystemBase {
 public:
  Drivetrain();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

  /**
   * Drives the robot using arcade controls.
   *
   * @param speed the commanded forward movement
   * @param rot the commanded rotation
   */
  void ArcadeDrive(double speed, double rot);

  double GetMaxOutput();

  void SetMaxOutput(double max_output);

  double GetAverageEncoderDistance();

  void ResetEncoders();

  double GetGyroAngle();

  void ResetGyro();
  
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  
  double max_output = 1.0;
  
  // Neo motor controllers
  rev::CANSparkMax right{ConDrivetrain::RIGHT_MOTOR, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax right_slave{ConDrivetrain::RIGHT_SLAVE_MOTOR, rev::CANSparkMax::MotorType::kBrushless};

  rev::CANSparkMax left{ConDrivetrain::LEFT_MOTOR, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax left_slave{ConDrivetrain::LEFT_SLAVE_MOTOR, rev::CANSparkMax::MotorType::kBrushless};

  // Drive encoders
  rev::CANEncoder right_encoder = right.GetEncoder();
  rev::CANEncoder right_slave_encoder = right_slave.GetEncoder();

  rev::CANEncoder left_encoder = left.GetEncoder();
  rev::CANEncoder left_slave_encoder = left_slave.GetEncoder();

  // Robot Drive
  frc::DifferentialDrive drive{left, right};

  // Dead zone correction for Xbox controllers
  double DeadZoneCorrection(double axis_value);

  AHRS *gyro;

};
