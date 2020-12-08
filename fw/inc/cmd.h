#ifndef CMD_H 
#define CMD_H

#include "string.h"
#include "cli.h"
// #include "iostream.h"
// #include "iomanip.h"
class Cmd
{
    friend class CLI;

    const char* name;
    virtual const char* parse(char* input) = 0;

    bool match (char* cmd){
        for(size_t i = 0 ; i < strlen(name) ; i++) {
            if(cmd[i] != name[i])
                return false;
        }

        return true;
    }  

    Cmd( const Cmd& );            // non construction-copyable
    Cmd& operator=( const Cmd& ); // non copyable

    public:
    Cmd(const char* n):name(n){}
    virtual ~Cmd(){}
};

#endif
