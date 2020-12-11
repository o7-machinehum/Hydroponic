#ifndef PWM_H 
#define PWM_H

#include <stdint.h>

class pwm {
    uint32_t tim;
    uint32_t period;

public:
    pwm(uint32_t port, uint16_t pin, uint32_t tim, uint32_t period, float duc); 
    ~pwm();

    void set_duc(float duc);
    void set_period(uint32_t p); 
    void start();
    void stop();
};
#endif
