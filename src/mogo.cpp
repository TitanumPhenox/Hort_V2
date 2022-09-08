#include "main.h"

int mogo_port = 13;
pros::Motor mogo(mogo_port, MOTOR_GEARSET_36, false, MOTOR_ENCODER_DEGREES);

void set_mogo(bool input) { if (input == true) {mogoClamp.set_value(true);} else {mogoClamp.set_value(false);} }

void zero_mogo() { mogo.tare_position(); }

bool mogoboy = false;
void mogo_control_manual()
{
    if (master.get_digital(DIGITAL_L1))
    {
        ///set_mogo(127);
        if (mogoboy == true) {
            mogoboy = false;
            pros::delay(200);
        } else {
            mogoboy = true;
            pros::delay(200);
        }
    }
    if (mogoboy == true) {
        set_mogo(true);
    } else {
        set_mogo(false);
    }
}
