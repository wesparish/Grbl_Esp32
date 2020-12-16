#pragma once
// clang-format off

/*
        pen_laser.h
        Part of Grbl_ESP32

        Pen assignments for the Buildlog.net pen laser controller V1 & V2

        For pen mode be sure to uncomment #define USE_PEN_SERVO in config.h
        For solenoid  mode be sure to uncomment #define USE_PEN_SERVO in config.h
        For laser mode, you do not need to change anything
        Note: You can use all 3 modes at the same time if you want

        2019    - Bart Dring
        2020    - Mitch Bradley

        Grbl_ESP32 is free software: you can redistribute it and/or modify
        it under the terms of the GNU General Public License as published by
        the Free Software Foundation, either version 3 of the License, or
        (at your option) any later version.

        Grbl is distributed in the hope that it will be useful,
        but WITHOUT ANY WARRANTY; without even the implied warranty of
        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
        GNU General Public License for more details.

        You should have received a copy of the GNU General Public License
        along with Grbl_ESP32.  If not, see <http://www.gnu.org/licenses/>.
*/

#define MACHINE_NAME "XY_SERVO_DRAWER"
                                                // ESP32-devkit pin
#define X_STEP_PIN              GPIO_NUM_12     // D12
#define X_DIRECTION_PIN         GPIO_NUM_26     // D26

#define Y_STEP_PIN              GPIO_NUM_14     // D14
#define Y_DIRECTION_PIN         GPIO_NUM_25     // D25

#define STEPPERS_DISABLE_PIN    GPIO_NUM_13     // D13

#define X_LIMIT_PIN             GPIO_NUM_15     // D15
#define Y_LIMIT_PIN             GPIO_NUM_4      // D04

#define Z_SERVO_PIN             GPIO_NUM_27     // D27

// #define CONTROL_SAFETY_DOOR_PIN GPIO_NUM_35  // labeled Door,  needs external pullup
// #define CONTROL_RESET_PIN       GPIO_NUM_34  // labeled Reset, needs external pullup
// #define CONTROL_FEED_HOLD_PIN   GPIO_NUM_36  // labeled Hold,  needs external pullup
// #define CONTROL_CYCLE_START_PIN GPIO_NUM_39  // labeled Start, needs external pullup

#define SPINDLE_TYPE SpindleType::NONE

// defaults
#define DEFAULT_STEP_PULSE_MICROSECONDS 3
#define DEFAULT_STEPPER_IDLE_LOCK_TIME 250 // don't stay on

#define DEFAULT_STEPPING_INVERT_MASK 0 // uint8_t
#define DEFAULT_DIRECTION_INVERT_MASK 0 // uint8_t
#define DEFAULT_INVERT_ST_ENABLE 0 // boolean
#define DEFAULT_INVERT_LIMIT_PINS 1 // boolean
#define DEFAULT_INVERT_PROBE_PIN 0 // boolean

#define DEFAULT_STATUS_REPORT_MASK 1

#define DEFAULT_JUNCTION_DEVIATION 0.01 // mm
#define DEFAULT_ARC_TOLERANCE 0.002 // mm
#define DEFAULT_REPORT_INCHES 0 // false

#define DEFAULT_SOFT_LIMIT_ENABLE 0 // false
#define DEFAULT_HARD_LIMIT_ENABLE 0  // false

#define DEFAULT_HOMING_ENABLE 0
#define DEFAULT_HOMING_DIR_MASK 0 // move positive dir Z, negative X,Y
#define DEFAULT_HOMING_FEED_RATE 200.0 // mm/min
#define DEFAULT_HOMING_SEEK_RATE 1000.0 // mm/min
#define DEFAULT_HOMING_DEBOUNCE_DELAY 250 // msec (0-65k)
#define DEFAULT_HOMING_PULLOFF 10.0 // mm

#define DEFAULT_SPINDLE_RPM_MAX 1000.0 // rpm
#define DEFAULT_SPINDLE_RPM_MIN 0.0 // rpm

#define DEFAULT_X_STEPS_PER_MM 80.0
#define DEFAULT_Y_STEPS_PER_MM 80.0
#define DEFAULT_Z_STEPS_PER_MM 100.0 // This is percent in servo mode...used for calibration

#define DEFAULT_X_MAX_RATE 5000.0 // mm/min
#define DEFAULT_Y_MAX_RATE 5000.0 // mm/min
#define DEFAULT_Z_MAX_RATE 5000.0 // mm/min

#define DEFAULT_X_ACCELERATION 50.0 // mm/sec^2. 50 mm/sec^2 = 180000 mm/min^2
#define DEFAULT_Y_ACCELERATION 50.0 // mm/sec^2
#define DEFAULT_Z_ACCELERATION 50.0 // mm/sec^2

#define DEFAULT_X_MAX_TRAVEL 300.0 // mm NOTE: Must be a positive value.
#define DEFAULT_Y_MAX_TRAVEL 300.0 // mm NOTE: Must be a positive value.
#define DEFAULT_Z_MAX_TRAVEL 5.0 // This is percent in servo mode...used for calibration

#define DEFAULT_X_HOMING_MPOS 10.0 //DEFAULT_Z_MAX_TRAVEL

#define Z_SERVO_PIN                   GPIO_NUM_27 // comment this out if PWM spindle/laser control.
#define DEFAULT_Z_MAX_TRAVEL          5.0   // Range of travel is 5mm
#define DEFAULT_Z_HOMING_MPOS         0.0   // MPos will be set to 5mm after homing
#define Z_SERVO_CAL_MIN               1.0   // calibration factor for the minimum PWM duty
#define Z_SERVO_CAL_MAX               1.0   // calibration factor for the maximum PWM duty

/*
Settings for successful first print
>>> $$
$0 = 3    (Step pulse time, microseconds)
$1 = 250    (Step idle delay, milliseconds)
$2 = 0    (Step pulse invert, mask)
$3 = 0    (Step direction invert, mask)
$4 = 0    (Invert step enable pin, boolean)
$5 = 1    (Invert limit pins, boolean)
$6 = 0    (Invert probe pin, boolean)
$10 = 1    (Status report options, mask)
$11 = 0.010    (Junction deviation, millimeters)
$12 = 0.002    (Arc tolerance, millimeters)
$13 = 0    (Report in inches, boolean)
$20 = 0    (Soft limits enable, boolean)
$21 = 0    (Hard limits enable, boolean)
$22 = 1    (Homing cycle enable, boolean)
$23 = 3    (Homing direction invert, mask)
$24 = 200.000    (Homing locate feed rate, mm/min)
$25 = 1000.000    (Homing search seek rate, mm/min)
$26 = 250.000    (Homing switch debounce delay, milliseconds)
$27 = 10.000    (Homing switch pull-off distance, millimeters)
$30 = 1000.000    (Maximum spindle speed, RPM)
$31 = 0.000    (Minimum spindle speed, RPM)
$32 = 0    (Laser-mode enable, boolean)
$N1=
$N0=
$100 = 80.000    (X-axis travel resolution, step/mm)
$101 = 80.000    (Y-axis travel resolution, step/mm)
$102 = 100.000    (Z-axis travel resolution, step/mm)
$103 = 100.000   
$104 = 100.000   
$105 = 100.000   
$110 = 5000.000    (X-axis maximum rate, mm/min)
$111 = 5000.000    (Y-axis maximum rate, mm/min)
$112 = 5000.000    (Z-axis maximum rate, mm/min)
$113 = 1000.000   
$114 = 1000.000   
$115 = 1000.000   
$120 = 50.000    (X-axis acceleration, mm/sec^2)
$121 = 50.000    (Y-axis acceleration, mm/sec^2)
$122 = 50.000    (Z-axis acceleration, mm/sec^2)
$123 = 200.000   
$124 = 200.000   
$125 = 200.000   
$130 = 300.000    (X-axis maximum travel, millimeters)
$131 = 300.000    (Y-axis maximum travel, millimeters)
$132 = 5.000    (Z-axis maximum travel, millimeters)
$133 = 300.000   
$134 = 300.000   
$135 = 300.000   
ok
*/