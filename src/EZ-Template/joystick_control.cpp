/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "main.h"

void arcadeDrive() {
    int power = pros::c::controller_get_analog(pros::E_CONTROLLER_MASTER,pros::E_CONTROLLER_ANALOG_RIGHT_X);
    int turn = pros::c::controller_get_analog(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_ANALOG_RIGHT_Y);
    int left = power + turn;
    int right = power - turn;

    l_motor.move(-left);
    l2_motor.move(-left);
    r_motor.move(-right);
    r2_motor.move(-right);

    pros::delay(20);

}