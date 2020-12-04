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
    return (strcmp(cmd, name) == 0);
  }

  public:
  Cmd(const char* n):name(n){}
  virtual ~Cmd(){}
};

#endif
