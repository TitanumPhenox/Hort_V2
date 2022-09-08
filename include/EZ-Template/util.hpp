/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#pragma once
#include "api.h"

void print_ez_template();

extern pros::Motor l_motor;
extern pros::Motor r_motor;
extern pros::Motor l2_motor;
extern pros::Motor r2_motor;
extern pros::Imu gyro;
extern pros::ADIDigitalOut tilterClamp;
extern pros::ADIDigitalOut mogoClamp;
void chassis_motor_init();

void set_drive_brake(pros::motor_brake_mode_e_t input);

bool imu_calibrate();
