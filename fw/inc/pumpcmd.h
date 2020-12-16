#pragma once

#include "uart.h"
#include "pwm.h"
#include "cmd.h"

class PumpCmd: public Cmd
{
    uart* uartx;
    pwm*  pump1;
    pwm*  pump2;

    void process(void);
    virtual const char* parse(char* input)
    {
        return(process(input));
    }

    PumpCmd( const PumpCmd& );            // non construction-copyable
    PumpCmd& operator=( const PumpCmd& ); // non copyable
    
    public:
    PumpCmd(const char* cmd_name, uart* u, pwm* pump1, pwm* pump2)
    :Cmd(cmd_name), uartx(u), pump1(pump1), pump2(pump2){}
};
