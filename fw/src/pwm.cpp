#include "pwm.h"
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/timer.h>

pwm::pwm(uint32_t port, uint16_t pin, uint32_t tim, uint32_t period, float duc) 
: tim(tim), period(period)
{
    rcc_periph_clock_enable(RCC_TIM1);
    rcc_periph_clock_enable(RCC_GPIOA);
     
    rcc_periph_clock_enable(RCC_AFIO);
    gpio_set_mode(port, GPIO_MODE_OUTPUT_50_MHZ, GPIO_CNF_OUTPUT_ALTFN_PUSHPULL, pin);

    timer_set_mode(tim, TIM_CR1_CKD_CK_INT, TIM_CR1_CMS_CENTER_1,
                   TIM_CR1_DIR_UP);

    timer_set_oc_mode(tim, TIM_OC1, TIM_OCM_PWM2);
    timer_enable_oc_output(tim, TIM_OC1);
    timer_enable_break_main_output(tim);
    set_duc(duc);
    set_period(period);
}

pwm::~pwm() {
    stop();
}

// pec
void pwm::set_duc(float duc) {
    timer_set_oc_value(tim, TIM_OC1, int(duc * period));
}

void pwm::set_period(uint32_t p) {
    period = p;
    timer_set_period(tim, period);
}

void pwm::start() {
    timer_enable_counter(tim);
}

void pwm::stop() {
    timer_disable_counter(tim);
}
