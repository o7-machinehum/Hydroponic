#ifndef CMDPROC_H 
#define CMDPROC_H

#include "cmd.h"
#include "uart.h"

class CLI
{
    const char* prompt;
    void getLine(char* buf, size_t len);
    uart* uartx;

    CLI( const CLI& );            // non construction-copyable
    CLI& operator=( const CLI& ); // non copyable

public:
    void present(Cmd *menu[0]);
    CLI(const char *p, uart* u)
    :prompt(p), uartx(u){}
};

void CLI::present(Cmd *menu[]){
    char buf[80];
    int i(0);
    uartx->send("Turnip CLI V0.1\r\n");
    uartx->send("> ");
    while(true){
        buf[i] = uartx->getch(); // Get input
        uartx->send(buf[i]);     // Send back
        i++;

        // Check for newline
        if(buf[i-1] == '\r') {
            uartx->send('\n');

            // Figure out which command it is!
            for(Cmd** p(menu) ; *p ; p++) {
                if((*p)->match(buf)){
                    (*p)->parse(buf); // Run the command
                    break;
                }
            }

            // Zero the shit out
            while(i--)
                buf[i] = 0;
            i = 0;
            uartx->send("> ");
        }

        // Backspaces
        // if(buf[i-1] == 8) {
        //     uartx->send('\b');
        //     i -= 1;
        //     buf[i] = 0;
        // }
    }
}

#endif
