/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Shooter.h"

Shooter::Shooter() {
    
    // Invert shooter motors correctly
    top_motor.SetInverted(false);
    bottom_motor.SetInverted(true);
    //Set velocity of shaft relative to velocity of wheel
    top_encoder.SetVelocityConversionFactor(ConShooter::Top::VELOCITY_FACTOR);
    bottom_encoder.SetVelocityConversionFactor(ConShooter::Bottom::VELOCITY_FACTOR);

    //Set controller gains from constants
    top_velocity_PID.SetP(ConShooter::Top::P);
    top_velocity_PID.SetI(ConShooter::Top::I);
    top_velocity_PID.SetD(ConShooter::Top::D);
    top_velocity_PID.SetFF(ConShooter::Top::FF);
    top_velocity_PID.SetOutputRange(0,1);
    
    bottom_velocity_PID.SetP(ConShooter::Bottom::P);
    bottom_velocity_PID.SetI(ConShooter::Bottom::I);
    bottom_velocity_PID.SetD(ConShooter::Bottom::D);
    bottom_velocity_PID.SetFF(ConShooter::Bottom::FF);
    bottom_velocity_PID.SetOutputRange(0,1);

    //Kicker motor PID code
    kicker_motor.SetInverted(true);
    kicker_motor.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);
    train_motor.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
    hopper_motor.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);
    //first choose sensor
    kicker_motor.ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::CTRE_MagEncoder_Absolute, 0, 30);
    
    // set the peak and nominal outputs
    kicker_motor.ConfigNominalOutputForward(0, 30);
    kicker_motor.ConfigNominalOutputReverse(0, 30);
    kicker_motor.ConfigPeakOutputForward(1, 30);
    kicker_motor.ConfigPeakOutputReverse(-1, 30);
    //closed loop gains in slot 0
    kicker_motor.Config_kP(0, 1.0, 30);
    kicker_motor.Config_kD(0, 250.0, 30);
}

// This method will be called once per scheduler run
void Shooter::Periodic() {}

//give velocity in meters per second
void Shooter::SetBottomMotorSpeed(double velocity) {
    bottom_velocity_PID.SetReference(velocity, rev::ControlType::kVelocity);
}

void Shooter::SetTopMotorSpeed(double velocity) {
    top_velocity_PID.SetReference(velocity, rev::ControlType::kVelocity);
}

double Shooter::GetBottomMotorSpeed() {
    return bottom_encoder.GetVelocity();
}

double Shooter::GetTopMotorSpeed() {
    return top_encoder.GetVelocity();
}

//Feeder system
void Shooter::SetKickerSpeed(double velocity) {/* feed_motor.Set(speed); */ kicker_motor.Set(ControlMode::Velocity, velocity);}

void Shooter::SetHopperSpeed(double speed) {hopper_motor.Set(speed);}

void Shooter::SetTrainSpeed(double speed) {train_motor.Set(speed);}