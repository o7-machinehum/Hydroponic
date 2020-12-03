#include "FreeRTOS.h"
#include "task.h"

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/flash.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/adc.h>
#include <libopencm3/stm32/usart.h>

demo_task(void *arg __attribute((unused))) {
    rcc_periph_clock_enable(RCC_GPIOC);

    gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ,
    		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO13);

    gpio_clear(GPIOC, GPIO13);

}

int main(void) {
    rcc_clock_setup_in_hse_8mhz_out_72mhz();

    xTaskCreate(demo_task,"demo",300,NULL,1,NULL);
    vTaskStartScheduler();
}
