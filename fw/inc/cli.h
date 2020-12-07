#ifndef CMDPROC_H 
#define CMDPROC_H

// #include "stddef.h"
// #include "iostream.h"
#include "cmd.h"
#include "uart.h"
// #include "strstream.h"
// #include "ctype.h"

class CLI
{
    const char* prompt;
    void getLine(char* buf, size_t len);
    uart* uartx;

public:
    void present(Cmd *menu[0]);
    CLI(const char *p, uart* u)
    :prompt(p), uartx(u){}
};

void CLI::present(Cmd *menu[]){
    while(true){
        // print: prompt
        uartx->send('f');
        char buf[80];
        getLine(buf, sizeof(buf));

        if(buf[0] != 0){
            const char* msg = "unknown command";
            for(Cmd** p(menu) ; *p ; p++){

                if((*p)->match(buf)){
                    msg = (*p)->parse(buf);
                    break;
                }
            }
            // if(msg) Print msg if we get here.
            //     os << msg;
        }
    }
}

void CLI::getLine(char* buf, size_t len)
{
//     istream is(sbuf);
//     ostream os(sbuf);
// 
//     char* bp = &buf[0];
//     char* ep = &buf[len - 1];
// 
//     while (true)
//     {
//         int c = is.get();
//         switch (c)
//         {
//             case '\r':
//             case '\n':
//                 *bp = 0;
//                 return;
// 
//             case 'H' - 0x40:
//                 if (bp > buf)
//                 {
//                     os << "\b \b" << flush;
//                     --bp;
//                 }
//                 break;
// 
//             default:
//                 if (isprint(c) && bp < ep)
//                 {
//                     os << char(c) << flush;
//                     *bp++ = c;
//                 }
//                 break;
//         }
//     }
}

#endif
