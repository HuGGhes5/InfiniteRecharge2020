/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#include <cmath>

#include "subsystems/Limelight.h"

Limelight::Limelight() {}

// This method will be called once per scheduler run
void Limelight::Periodic() {}

double Limelight::GetValidTarget(){
    return table->GetNumber("tv", 0.0);
}

double Limelight::GetHorizontalOffset(){
    return table->GetNumber("tx", 0.0);
}

double Limelight::GetVerticalOffset(){
    return table->GetNumber("ty", 0.0);
}

double Limelight::GetTargetArea(){
    return table->GetNumber("ta", 0.0);
}

double Limelight::GetTargetDistance(){
    return (ConLimelight::TARGET_HEIGHT-ConLimelight::CAMERA_HEIGHT)/(tan(GetVerticalOffset()*ConMath::DEG_2_RAD));
}

void Limelight::SetLEDMode(int mode){
    table->PutNumber("ledMode", mode);
}

void Limelight::SetCamMode(int mode){
    table->PutNumber("camMode", mode);
}

void Limelight::SetSnapshot(int mode){
    table->PutNumber("snapshot", mode);
}