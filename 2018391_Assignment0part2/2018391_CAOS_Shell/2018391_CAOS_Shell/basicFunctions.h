#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>


#ifndef BASICFUNCTIONS_H
#define BASICFUNCTIONS_H
    void nullifyinput(char* input);
    void init_shell();
    void printCommandLine();
    int areEqual(char* s1,char s2[]);
    int inBuiltHandler(char* command);
    int getCommand(char* command);

#endif // BASICFUNCTIONS_H

