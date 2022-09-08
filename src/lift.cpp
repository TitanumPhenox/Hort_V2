#include "main.h"


// Driver Control Variables
int lift_port = 12;

pros::Motor lift(lift_port, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_DEGREES);


void set_lift(int input) { lift = input; }

void zero_lift() { lift.tare_position(); }

float prime;
bool primeboy = false;
void lift_control_manuel() {
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
        set_lift(127);
    } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        set_lift(-127);
    } else {
        set_lift(0);
    }

    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2))
    {
        if (!primeboy) {
            prime = lift.get_position();
            primeboy = true;
            pros::delay(150);
        } else {
            primeboy = false;
            pros::delay(150);
        }
    }
    if (lift.get_position() > prime + 10 && primeboy) {
        set_take(-110);
    } else {
        set_take(0);
    }
}