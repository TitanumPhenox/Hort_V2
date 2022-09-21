/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/
/**
#include "main.h"
#include <string>

void set_motors_stop() {
    l_motor.move_voltage(0);
    l2_motor.move_voltage(0);
    r_motor.move_voltage(0);
    r2_motor.move_voltage(0);
    set_lift(0);
}

void set_motors_drive(int voltage) {
    l_motor.move_voltage(voltage);
    l2_motor.move_voltage(voltage);
    l3_motor.move_voltage(voltage);
    r_motor.move_voltage(-voltage);
    r2_motor.move_voltage(-voltage);
    r3_motor.move_voltage(-voltage);
}

void set_motors_left(int voltage) {
    l_motor.move_voltage(-voltage);
    l2_motor.move_voltage(-voltage);
    l3_motor.move_voltage(-voltage);
    r_motor.move_voltage(-voltage);
    r2_motor.move_voltage(-voltage);
    r3_motor.move_voltage(-voltage);
}

void set_motors_right(int voltage) {
    l_motor.move_voltage(voltage);
    l2_motor.move_voltage(voltage);
    l3_motor.move_voltage(voltage);
    r_motor.move_voltage(voltage);
    r2_motor.move_voltage(voltage);
    r3_motor.move_voltage(voltage);
}

void gyro_turning(float left_range, float right_range, bool negative, bool direction) {
    int posneg;
    if (negative == true) {
        posneg = -1;
    } else {
        posneg = 1;
    };

    if (direction == true) {
        while (gyro.get_heading() < (left_range - 75) || gyro.get_heading() > (right_range - 75)) {
            set_motors_left(12000 * posneg);
        }
        while (gyro.get_heading() < left_range || gyro.get_heading() > right_range) {
            set_motors_left(6000 * posneg);
        }

        /*
        for (int i = 1; gyro.get_heading() < left_range || gyro.get_heading() > right_range; i++) {
            set_motors_left((12000 - (i * 300)) * posneg);
        }

    } else {
        while (gyro.get_heading() < (left_range - 60) || gyro.get_heading() > (right_range - 60)) {
            set_motors_right(12000 * posneg);
        }

        while (gyro.get_heading() < left_range || gyro.get_heading() > right_range) {
            set_motors_right(6000 * posneg);
        }

        /*
        for (int i = 1; gyro.get_heading() < left_range || gyro.get_heading() > right_range; i++) {
            set_motors_right((12000 - (i * 300)) * posneg);
        }

    }
};

void tilter_auton() {
    set_take(-127);
    pros::delay(225);
    set_take(0);

}

void line_auton() {
    set_motors_drive(4000);
    pros::delay(800);
    set_motors_drive(0);
    set_mogo(true);
    pros::delay(1600);
    set_motors_drive(-8000);
    pros::delay(600);
    set_motors_drive(0);
}
void skills_auton() {
    // Grabs Mobile Goal
    set_mogo(true);
    set_tilter(true);
    pros::delay(400);
    set_motors_drive(6000);
    pros::delay(300);
    set_motors_drive(0);
    set_mogo(false);
    pros::delay(700);
//    set_motors_drive(-6000);
    while (gyro.get_heading() < 37 || gyro.get_heading() > 39) {
        l_motor.move_voltage(-6000);
        l2_motor.move_voltage(-6000);
        l3_motor.move_voltage(-6000);
    }
    pros::delay(50);
    set_motors_drive(0);
    pros::delay(300);
    set_motors_drive(-6000);
    pros::delay(500);
    set_motors_drive(0);
    pros::delay(500);

    // Turns towards the neutral mobile goal
    while (gyro.get_heading() < 84 || gyro.get_heading() > 86) {
        set_motors_left(6500);
    }
    set_motors_drive(0);
    pros::delay(20);

    // Drives forward and grabs the nutral goal
    set_motors_drive(-8000);
    pros::delay(1150);
    set_motors_drive(-2000);
    pros::delay(600);
    set_motors_drive(0);
    set_tilter(false);
    pros::delay(900);

    // Moves forward and lifts the mobile goal up
    set_lift(127);
    pros::delay(1600);
    set_motors_drive(-8000);
    pros::delay(1000);
    set_motors_drive(0);
    pros::delay(100);

    // Turns left slightly to line up with the platform
    while (gyro.get_heading() < 133 || gyro.get_heading() > 136) {
        set_motors_left(6000);
    }
    set_motors_drive(0);
    pros::delay(20);

    // Drive forward and places the mobile goal down
    set_motors_drive(-6000);
    pros::delay(1325);
    set_motors_drive(0);
    set_lift(-127);
    pros::delay(750);
    set_lift(0);

    // Lets the mobile goal go
    set_tilter(true);
    pros::delay(1000);
    set_motors_drive(6000);
    pros::delay(100);
    set_motors_drive(0);
    set_lift(127);
    pros::delay(750);
    set_lift(0);
    set_motors_drive(6000);
    pros::delay(825);
    set_motors_drive(0);

    //Lets mogo go and turns to grab it
    set_lift(-127);
    pros::delay(500);
    set_mogo(true);
    pros::delay(500);
    set_motors_drive(-6000);
    pros::delay(400);
    set_motors_drive(0);
    pros::delay(300);
    while (gyro.get_heading() < 295 || gyro.get_heading() > 301) {
        set_motors_left(6000);
    }
    set_motors_drive(-6000);
     pros::delay(350);
     set_motors_drive(0);
     set_tilter(false);
     pros::delay(100);

     //Turns and puts the goal down
     set_lift(127);
     pros::delay(1600);
     set_lift(0);
     while (gyro.get_heading() < 109 || gyro.get_heading() > 116) {
        set_motors_left(6000);
    }
     pros::delay(50);
     set_motors_drive(-6000);
     pros::delay(1150);
     set_motors_drive(0);
    set_lift(-127);
    pros::delay(650);
    set_lift(0);
    pros::delay(400);
     set_tilter(true);
     pros::delay(400);
    set_motors_drive(6000);
     pros::delay(200);
    set_motors_drive(0);
     set_lift(127);
    pros::delay(750);
    set_lift(0);
    set_motors_drive(6000);
    pros::delay(50);
    set_motors_drive(0);

    //Turns and grabs line mobile goal
    while (gyro.get_heading() < 163 || gyro.get_heading() > 169) {
        set_motors_left(6000);
    }
    set_motors_drive(0);
    pros::delay(500);
    set_motors_drive(6000);
    pros::delay(1375); //pros::delay(950);
    set_motors_drive(0);
    set_mogo(false); //set_mogo(true);
    pros::delay(500);
    set_motors_drive(-6000);
    pros::delay(650);
    set_motors_drive(0);

    //Turns to central goal and drive forward
    while (gyro.get_heading() < 215 || gyro.get_heading() > 219) {
        set_motors_left(6000);
    }
    set_motors_drive(0);
    pros::delay(30);

    set_lift(-127);
    pros::delay(1400);

    set_motors_drive(-6000); //-6000
    pros::delay(1400);
    set_motors_drive(-3000);
    pros::delay(700);
    set_motors_drive(0);
    pros::delay(300);

    //Grabs Middle goal, drives to red/blue alliance area, drops off both middle and red goal, then pushes right neutral goal towards opposite alliance area
    set_tilter(false);
    pros::delay(200);
    set_lift(127);
    pros::delay(100);
    set_lift(0);
    set_motors_drive(-6000);
    pros::delay(2200);
    set_motors_drive(0);
    set_tilter(true);
    pros::delay(100);
    while (gyro.get_heading() < 140 || gyro.get_heading() > 145) {
        set_motors_right(6000);
    }
    set_motors_drive(0);
    pros::delay(300);
    set_mogo(true);
    pros::delay(400);
    set_motors_drive(-6000);
    pros::delay(2000);
    set_motors_drive(0);
    /*
    set_motors_drive(6000);
    pros::delay(2900);
    set_motors_drive(0);
    pros::delay(300);
    while (gyro.get_heading() < 183 || gyro.get_heading() > 188) {
        set_motors_right(6000);
    }
    set_motors_drive(0);
    pros::delay(20);
    set_lift(127);
    pros::delay(700);
    set_lift(0);
    set_motors_drive(-6000);
    pros::delay(800);
    set_lift(-127);
    pros::delay(450);
    set_lift(0);
    pros::delay(300);
    set_tilter(true);
    pros::delay(300);
    set_lift(127);
    pros::delay(750);
    set_lift(0);
    set_motors_drive(6000);
    pros::delay(400);
    set_motors_drive(0);
     pros::delay(300);

     //Turns and grabs the platform holding goal
     while (gyro.get_heading() < 230 || gyro.get_heading() > 235) {
        set_motors_left(6000);
    }
    set_motors_drive(0);
     pros::delay(300);
     set_motors_drive(-6000);
     pros::delay(1500);
    set_motors_drive(0);
    pros::delay(300);
     while (gyro.get_heading() < 180 || gyro.get_heading() > 185) {
        set_motors_right(6000);
    }
    set_motors_drive(0);
     pros::delay(300);
     set_motors_drive(-6000);
     pros::delay(1500);
     set_tilter(false);

    set_motors_drive(12000);
    pros::delay(100);
    set_motors_drive(0);
    pros::delay(500);

    //Turns towards left goal and drives forward
    while (gyro.get_heading() < 170 || gyro.get_heading() > 175) {
        set_motors_right(6000);
    }
    set_mogo(true);
    pros::delay(130);
    set_motors_drive(-12000);
    pros::delay(1500);
    set_motors_drive(0);

}

void neutral_auton() {
    // Drives forward
    set_tilter(true);
    set_motors_drive(-12000);
    pros::delay(700);
    set_motors_drive(-3000);
    pros::delay(300);
    set_motors_drive(0);
    // Grabs the goal with the claw
    set_tilter(false);
    pros::delay(200);
    // Drives backwards
    set_motors_drive(12000);
    pros::delay(1000);
    set_motors_drive(0);
}

void win_point() {
    set_mogo(true);
    pros::delay(200);
    set_motors_drive(6000);
    pros::delay(200);
    set_motors_drive(0);
    set_mogo(false);
    pros::delay(50);
    set_take(-127);
    pros::delay(225);
    set_take(0);
    pros::delay(500);
    set_motors_drive(-6000);
    pros::delay(230);
    set_mogo(true);
    pros::delay(230);
    set_motors_drive(0);
    gyro_turning(73, 77, true, false);
///87,91
    set_motors_drive(0);
    pros::delay(200);
    set_motors_drive(-8100);
    pros::delay(585);
    set_motors_drive(0);
    pros::delay(200);
    while (gyro.get_heading() < 5 || gyro.get_heading() > 10) {
        set_motors_right(6000);
    }
///167, 177
    set_motors_drive(0);
    pros::delay(20);
    set_motors_drive(7000);
    pros::delay(2500);
    set_motors_drive(7000);
    pros::delay(1200);
    set_motors_drive(0);
    set_mogo(false);
    pros::delay(875);
    set_take(-127);
    pros::delay(225);
    set_take(0);
    pros::delay(50);
    set_motors_drive(-8000);
    pros::delay(500);
    set_motors_drive(0);
}
**/