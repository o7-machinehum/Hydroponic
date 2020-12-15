#ifndef CMDPROC_H 
#define CMDPROC_H

#include "cmd.h"
#include "uart.h"

class CLI
{
    const char* prompt;
    void getLine(char* buf, size_t len);
    uart* uartx;
    Cmd **menu;
    uint8_t num_commands;

    CLI( const CLI& );            // non construction-copyable
    CLI& operator=( const CLI& ); // non copyable

public:
    void present();
    CLI(const char *p, uart* u, Cmd** menu_st)
    :prompt(p), uartx(u), num_commands(0)
    {
        while(menu_st[num_commands]) {
            num_commands++;
        }

        menu = new Cmd*[num_commands];

        for(int i(0) ; i < num_commands ; i++) {
            menu[i] = menu_st[i]; 
        }
    }
};

void CLI::present(){
    char buf[80];
    uartx->send("Turnip CLI V0.2\r\n> ");
    int i(0);
    while(true){
        buf[i] = uartx->getch(); // Get input
        uartx->send(buf[i]);     // Send back
        i++;

        // Check for newline
        if(buf[i-1] == '\r') {
            uartx->send('\n');

            // Figure out which command it is!
            for(uint8_t k(0) ; k < num_commands ; k++) {
                if(menu[k]->match(buf)){
                    menu[k]->parse(buf); // Run the command
                    break;
                }
            }

            // Zero the shit out
            do {
                buf[i] = 0;
            }while(i--);
            i = 0;

            uartx->send("> ");
        }

        // Backspaces
        else if((buf[i-1] == 0x08) || (buf[i-1] == 0x7f)) {
            if(i == 1) {     // We're at the begining of the line
                buf[0] = 0;
                i = 0;
            }
            else {
                uartx->send('\b');
                buf[i-1] = 0;  // Delete the backspace
                buf[i-2] = 0;  // Delete the char before the backspace
                i -= 2;
            }
        }
    }
}

#endif
