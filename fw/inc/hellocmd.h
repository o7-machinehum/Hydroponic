#ifndef HELLOCMD_H 
#define HELLOCMD_H

#include "cmd.h"
#include "uart.h"

class HelloCmd: public Cmd
{
    uart* uartx;
    virtual const char* parse(char* input){
        uartx->send("Hello youself! \r\n");
        // uartx->send(input); 
        // uartx->send("\r\n");
        return(0);
    }
    
    HelloCmd( const HelloCmd& );            // non construction-copyable
    HelloCmd& operator=( const HelloCmd& ); // non copyable
    
    public:
    HelloCmd(const char* cmd_name, uart* u)
    :Cmd(cmd_name), uartx(u){}
};

#endif
