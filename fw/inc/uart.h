#ifndef UART_H 
#define UART_H

class uart {

public:
    uart();
    ~uart();

    void send(char c);
    void send(const char* str);
    char getch();
};
#endif
