#include "mbed.h"
#include "motors.h"
Motor::Motor(PinName pwm_pin) : pwm(pwm_pin) {
    pwm.period(0.02f);  
    pwm.write(0.03f);    
    duty_cycle = 0.03f;
}

void Motor::set_position(float angle) {
    if(angle >= 0 && angle <= 180) {
        duty_cycle = 0.03f + 0.1f * angle / 180.0f;  // Map angle to duty cycle
        pwm.write(duty_cycle);
    }
}

void Motor::stop() {
    pwm.write(0.0f); 
}