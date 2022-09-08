/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#pragma once
#include "api.h"

void set_motors_drive(int voltage);
void set_motors_stop();
void set_motors_left(int voltage);
void set_motors_right(int voltage);
void gyro_turning(float left_range, float right_range, bool negative, bool direction);
void tilter_auton();
void skills_auton();
void neutral_auton();
void win_point();
void line_auton();
void new_mexico();
void central_goal_right();