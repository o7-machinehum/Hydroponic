#ifndef PUMPCMD_H 
#define PUMPCMD_H

#include "pwm.h"

class PumpCmd: public Cmd
{
    uart* uartx;
    pwm*  pump1;
    pwm*  pump2;

    virtual const char* parse(char* input){
        uartx->send("Commands to control the system pumps\r\n");
        // uartx->send(input); 
        // uartx->send("\r\n");
        return(0);
    }
    
    PumpCmd( const PumpCmd& );            // non construction-copyable
    PumpCmd& operator=( const PumpCmd& ); // non copyable
    
    public:
    PumpCmd(const char* cmd_name, uart* u, pwm* pump1, pwm* pump2)
    :Cmd(cmd_name), uartx(u), pump1(pump1), pump2(pump2){}
};

#endif
