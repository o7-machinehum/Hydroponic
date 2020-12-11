#ifndef PWM_H 
#define PWM_H

#include <stdint.h>

class pwm {
    uint32_t tim;
    uint32_t freq;
    uint32_t clk;

    uint32_t freq_to_ticks(uint32_t f);

public:
    pwm(uint32_t port, uint16_t pin, uint32_t tim, uint32_t freq, float duc, uint32_t sysclk); 
    ~pwm();

    void set_duc(float duc);
    void set_freq(uint32_t f); 
    void start();
    void stop();
};
#endif
