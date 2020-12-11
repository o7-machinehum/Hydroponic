#include "pwm.h"
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/timer.h>

// Period in uS
pwm::pwm(uint32_t port, uint16_t pin, uint32_t tim, uint32_t freq, float duc, uint32_t sysclk) 
: tim(tim), freq(freq), clk(sysclk)
{
    rcc_periph_clock_enable(RCC_AFIO);
    gpio_set_mode(port, GPIO_MODE_OUTPUT_50_MHZ, GPIO_CNF_OUTPUT_ALTFN_PUSHPULL, pin);

    timer_set_mode(tim, TIM_CR1_CKD_CK_INT, TIM_CR1_CMS_CENTER_1,
                   TIM_CR1_DIR_UP);

    timer_set_oc_mode(tim, TIM_OC1, TIM_OCM_PWM2);
    timer_enable_oc_output(tim, TIM_OC1);
    timer_enable_break_main_output(tim);

    set_duc(duc);
    set_freq(freq);
}

pwm::~pwm() {
    stop();
}

// pec duc
void pwm::set_duc(float duc) {
    timer_set_oc_value(tim, TIM_OC1, uint32_t((1-duc)*freq_to_ticks(freq)));
}

void pwm::set_freq(uint32_t f) {
    freq = f;
    timer_set_period(tim, freq_to_ticks(f));
}

void pwm::start() {
    timer_enable_counter(tim);
}

void pwm::stop() {
    timer_disable_counter(tim);
}

uint32_t pwm::freq_to_ticks(uint32_t f) {
    return uint32_t(clk / (freq*2));
}
