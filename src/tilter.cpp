#include "main.h"

int tilter_port = 17;
pros::Motor tilter(tilter_port, MOTOR_GEARSET_36, true, MOTOR_ENCODER_DEGREES);

void set_tilter(bool input) { if (input == true) {tilterClamp.set_value(true);} else {tilterClamp.set_value(false);} }

void zero_tilter() { tilter.tare_position(); }

bool tilterboy = false;
void tilter_control_manuel()
{
    if (master.get_digital(DIGITAL_UP))
    {
        ///set_tilter(127);
        tilterClamp.set_value(true);
    }
    else if (master.get_digital(DIGITAL_DOWN))
    {
        ///set_tilter(-127);
        tilterClamp.set_value(false);
    }
    else
    {
        ///set_tilter(0);
    }
}
