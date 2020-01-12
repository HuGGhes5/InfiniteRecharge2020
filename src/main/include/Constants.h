/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

//THESE ARE ALL DUMBY VALUES FOR A SIMPLE AUTO
namespace ConAuto {
    constexpr double AutoDriveDistanceInches = 60;
    constexpr double AutoBackupDistanceInches = 20;
    constexpr double AutoDriveSpeed = 0.5; 
}

namespace ConCANBus {
    constexpr int RIGHT_MOTOR = 4;
    constexpr int LEFT_MOTOR = 5;
    constexpr int CLIMB_MOTOR = 6;
}

namespace ConXBOXController {
    //Axis inputs
    constexpr int LEFT_JOYSTICK_X = 0;    
    constexpr int LEFT_JOYSTICK_Y = 1;
    constexpr int LEFT_TRIGGER_ID = 2;
    constexpr int RIGHT_TRIGGER_ID = 3;
    constexpr int RIGHT_JOYSTICK_X = 4;    
    constexpr int RIGHT_JOYSTICK_Y = 5;
    //Buttons
    constexpr int A = 1;
    constexpr int B = 2;
    constexpr int X = 3;
    constexpr int Y = 4;
    constexpr int LEFT_BUMPER = 5;
    constexpr int RIGHT_BUMPER = 6;
    constexpr int SELECT = 7;
    constexpr int START = 8;
    constexpr int LEFT_JOYSTICK = 9;
    constexpr int RIGHT_JOYSTICK = 10;

    //CREATE A WIDGEt FOR THESE TO CHANGE
    //Dead zone
    constexpr double DEAD_ZONE = 0.015; //approximate value
    //Driver controller Port
    constexpr int DRIVER_CONTROLLER_PORT = 0;
}
