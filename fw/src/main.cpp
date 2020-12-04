#include "FreeRTOS.h"
#include "task.h"

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/flash.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/adc.h>
#include <libopencm3/stm32/usart.h>

#include "main.h"
#include "cli.h"
#include "hellocmd.h"

void test_task(void *arg __attribute((unused))) {
     rcc_periph_clock_enable(RCC_GPIOC);
 
     gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ,
     		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO13);
 
     while(true){
         vTaskDelay(500);
         gpio_toggle(GPIOC, GPIO13);
     }
 
}

void cli_task(void *arg __attribute((unused))) {
    CLI cli("CMD> ");

    Cmd* menu[] = {
        new HelloCmd("hello"),
        0
    };
    
    // Run the CLI
    cli.present(menu);
}

int main(void) {
    rcc_clock_setup_pll(&rcc_hse_configs[RCC_CLOCK_HSE8_72MHZ]);

    xTaskCreate(test_task,"demo", 128, NULL, 1, NULL);
    xTaskCreate(cli_task, "cli" , 128, NULL, 1, NULL);
    vTaskStartScheduler();

    while(true);
    
}
