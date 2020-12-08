#include "uart.h"
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/usart.h>


uart::uart() {
    gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_50_MHZ,
              GPIO_CNF_OUTPUT_ALTFN_PUSHPULL, GPIO_USART1_TX);
    
    gpio_set_mode(GPIOA, GPIO_MODE_INPUT,
              GPIO_CNF_INPUT_FLOAT, GPIO_USART1_RX);

    /* Setup UART parameters. */
    usart_set_baudrate(USART1, 115200);
    usart_set_databits(USART1, 8);
    usart_set_stopbits(USART1, USART_STOPBITS_1);
    usart_set_mode(USART1, USART_MODE_TX_RX);
    usart_set_parity(USART1, USART_PARITY_NONE);
    usart_set_flow_control(USART1, USART_FLOWCONTROL_NONE);

    /* Finally enable the USART. */
    usart_enable(USART1);
}

uart::~uart() {
    // lol
}

void uart::send(char c) {
    usart_send_blocking(USART1, c);
}

void uart::send(const char* str) {
    while(*str) {
        usart_send_blocking(USART1, *str++);
    }
}

char uart::getch() {
    return usart_recv_blocking(USART1);
}
