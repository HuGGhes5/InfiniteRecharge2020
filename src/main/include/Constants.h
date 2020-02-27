/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#pragma once

#include <units/units.h>
#include <wpi/math>
//#include <stdlib>
#include <opencv2/opencv.hpp>
/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

namespace ConMath {
    constexpr double PI = 3.141592;
    constexpr double METERS_2_INCH = .0254; // m/in
    constexpr double MINUTES_2_SECONDS = 1/60.; // sec/min
    constexpr double RAD_2_DEG = PI/180.0;
    constexpr double DEG_2_RAD = 1/RAD_2_DEG;
}

//THESE ARE ALL DUMBY VALUES FOR A SIMPLE AUTO
namespace ConAuto {
    constexpr double AutoDriveDistanceInches = 60;
    constexpr double AutoBackupDistanceInches = 20;
    constexpr double AutoDriveSpeed = 0.5; 
}

namespace ConClimber {
    // Motors
    constexpr int CLIMB_MOTOR = 1;
     constexpr double ENCODER_2_INCHES = 3.75; // inches #35 Chain = .375 pitch x 10 tooth = 3.75 inches
    constexpr double EXT_LIMIT = -31.0; // inches FIXME: Guesstimate in inches
    constexpr double RET_LIMIT = 0.0; // Starting Configuration: fully retracted, Encoder=0
    // Solenoid lock
    constexpr int SOLENOID_LOCK_ID = 6;
    constexpr int SOLENOID_UNLOCK_ID = 7;
}

namespace ConDrivetrain {
    //Motors
    constexpr int RIGHT_MOTOR = 2;
    constexpr int RIGHT_SLAVE_MOTOR = 4;

    constexpr int LEFT_MOTOR = 3;
    constexpr int LEFT_SLAVE_MOTOR = 5;
    
    //Spark Max Settings
    constexpr int RAMP_RATE = 0.100; //seconds
    constexpr bool INVERSION = false; //
    //Conversions
    constexpr double IN_2_ENCODER = (10.71*42)/(6*ConMath::PI); //encoder to motor 42 counts/rev, motor to shaft 10.71:1, 6in wheel
    constexpr double ENCODER_2_IN = 1/IN_2_ENCODER; 

    constexpr double TURN_P = 1;
    constexpr double TURN_I = 0;
    constexpr double TURN_D = 0;

    constexpr auto TURN_TOLERANCE = 5_deg;
    constexpr auto TURN_RATE_TOLERANCE = 10_deg_per_s;

    constexpr auto MAX_TURN_RATE = 100_deg_per_s;
    constexpr auto MAX_TURN_ACCELERATION = 300_deg_per_s / 1_s;
}

namespace ConLimelight {
    constexpr int VISION_MODE = 0;
    constexpr int CAMERA_MODE = 1;

    constexpr int LED_PIPLINE_DEFAULT = 0;
    constexpr int LED_OFF = 1;
    constexpr int LED_BLINK = 2;
    constexpr int LED_ON = 3;

    constexpr int SNAPSHOT_STOP = 0;
    constexpr int SNAPSHOT_START = 1;

    constexpr double HORIZONTAL_TOLERANCE = 1.0;  //degrees
    constexpr double TARGET_HEIGHT = 38.5; //in to center of target
    constexpr double CAMERA_HEIGHT = 19.5; //in to center of camera
    constexpr double MAX_HORIZONTAL_OFFSET = 29.8; //degrees

    // constexpr cv::Matx33d cameraMatrix = cv::Matx33d(
    //                     772.53876202, 0., 479.132337442,
    //                     0., 769.052151477, 359.143001808,
    //                     0., 0., 1.0);
    // constexpr std::vector istortionCoefficient =  std::vector<double> {
    //                     2.9684613693070039e-01, -1.4380252254747885e+00,-2.2098421479494509e-03,
    //                     -3.3894563533907176e-03, 2.5344430354806740e+00};

    constexpr double focalLength = 2.9272781257541; //mm
}

namespace ConNEO {
    constexpr int MAXIMUM_RPM = 5676;
}

namespace ConShooter {
    constexpr int DEAULT_SPEED = 4000; //RPM
    namespace Top {
        constexpr int MOTOR = 6;
        constexpr int WHEEL_SIZE = 4; //in inches
        constexpr double VELOCITY_FACTOR = 1; //(ConMath::PI*WHEEL_SIZE) * ConMath::METERS_2_INCH * ConMath::MINUTES_2_SECONDS; //(velocity) y [m/s] = PI*WHEEL_SIZE * m/in * 1/60 * x [RPM]
        //PID gains
        constexpr double P = 2e-4;
        constexpr double I = 0.0;
        constexpr double D = 2e-3;
        constexpr double FF = 1.7e-4;
    }
    namespace Bottom {
        constexpr int MOTOR = 9;
        constexpr int WHEEL_SIZE = 6; //in inches
        constexpr double VELOCITY_FACTOR = 1; //(ConMath::PI*WHEEL_SIZE) * ConMath::METERS_2_INCH * ConMath::MINUTES_2_SECONDS; //(velocity) y [m/s] = PI*WHEEL_SIZE * m/in * 1/60 * x [RPM]
        //PID gains
        constexpr double P = 2e-4;
        constexpr double I = 0.0;
        constexpr double D = 2e-3;
        constexpr double FF = 1.7e-4;
    }
}

namespace ConFeeder {
    //motor IDs
    constexpr int KICKER_MOTOR = 7;
    constexpr int HOPPER_MOTOR = 1;
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
    constexpr double DEAD_ZONE = 0.5; //approximate value
    //Driver controller Port
    constexpr int DRIVER_CONTROLLER_PORT = 1;
}

    namespace ConCoDriverController {
        namespace Button{
            constexpr int RED = 1;
            constexpr int BLUE = 2;
            constexpr int YELLOW = 3;
            constexpr int GREEN = 4;
            constexpr int WHITE = 5;
        }

        namespace Switch{
            constexpr int RED = 6;
            constexpr int BLUE = 7;
            constexpr int YELLOW = 8;
            constexpr int GREEN = 9;
        }
        namespace Dial{
            constexpr int LEFT = 0;
            constexpr int RIGHT = 4;
        }

        constexpr int SLIDER = 6;
        
        constexpr int RIGHT_STICK_Y = 4;
        constexpr int RIGHT_STICK_X = 3;

        constexpr int CODRIVER_CONTROLLER_PORT = 4;
        
    }