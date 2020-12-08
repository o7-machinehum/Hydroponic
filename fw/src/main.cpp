#include "FreeRTOS.h"
#include "task.h"

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/flash.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/adc.h>

#include "main.h"
#include "cli.h"
#include "hellocmd.h"
#include "uart.h"

static void clock_setup(void)
{
    rcc_clock_setup_pll(&rcc_hse_configs[RCC_CLOCK_HSE8_72MHZ]);

    /* Enable GPIOA clock (for LED GPIOs). */
    rcc_periph_clock_enable(RCC_GPIOA);
    rcc_periph_clock_enable(RCC_GPIOB);
    rcc_periph_clock_enable(RCC_GPIOC);

    /* Enable clocks for GPIO port B (for GPIO_USART1_TX) and USART1. */
    rcc_periph_clock_enable(RCC_AFIO);
    rcc_periph_clock_enable(RCC_USART1);
}

void test_task(void * parameters) {
    gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ,
    GPIO_CNF_OUTPUT_PUSHPULL, GPIO13);

    while(true){
        vTaskDelay(10);
        gpio_toggle(GPIOC, GPIO13);
    }
}

void cli_task(void * parameters) {
    auto uart1 = (uart *) parameters; 
    CLI cli("CMD> ", uart1);

    Cmd* menu[] = {
        new HelloCmd("hello", uart1),
        0
    };
    
    // Run the CLI
    cli.present(menu);
}

int main(void) {
    clock_setup();
    uart* uart1 = new uart();

    xTaskCreate(test_task,"demo", 128, NULL, 1, NULL);
    xTaskCreate(cli_task, "cli" , 128, uart1, 1, NULL);
    vTaskStartScheduler();

    while(true);
    
}
