#ifndef MOTOR_H
#define MOTOR_H
#include "mbed.h"
#include "global_defines.h"

class Motor {
    public:
        Motor(PinName pwm_pin);

        // Sets motor position based on angle (0-180 degrees)
        void set_position(float angle);

        void stop();

    private:
        float duty_cycle;
        PwmOut pwm;  // PWM output object
};

#endif