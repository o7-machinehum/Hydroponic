#ifndef HELLOCMD_H 
#define HELLOCMD_H

// #include "iostream.h"
#include "cmd.h"

class HelloCmd: public Cmd
{
  virtual const char* parse(char* intput){
    // print something
    // os << endl << "Hello World!";
    return(0);
  }
  
  public:
  HelloCmd(const char* name)
  :Cmd(name){}
};

#endif
