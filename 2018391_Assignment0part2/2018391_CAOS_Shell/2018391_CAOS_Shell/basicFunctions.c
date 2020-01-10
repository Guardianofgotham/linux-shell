#include "basicFunctions.h"


void init_shell()
{
    system("clear");
}

void printCommandLine()
{
    char currDirectory[512];
    char currHostName[512];
    gethostname(currHostName,512);
    char* ptr = &(currDirectory[0]);
    getcwd(ptr,512);
    printf("%s@%s:%s$ ",getenv("USER"),currHostName,currDirectory);
}

int areEqual(char* s1,char s2[])
{
    int minLength = (strlen(s1)<=strlen(s2)) ? strlen(s1):strlen(s2) ;
    for(int i=0;i<minLength;i++){
        if( *(s1+i) != *(s2+i) ){
            return 0;
        }
    }
    return 1;
}

int inBuiltHandler(char* command)
{
    system(command);
}

int getCommand(char* command)
{
    if(areEqual(command,"echo") || areEqual(command,"pwd") ){
        inBuiltHandler(command);
        return 1;
    }
    else if(command[0]=='c' && command[1]=='d' && command[2]==' '){
        chdir(command+3);
        return 1;
    }
    else if(areEqual(command,"exit")){
        char* ptr = &(command[0]);
        nullifyinput(ptr);
        exit(0);
        return 1;
    }
    return 0;
}

void nullifyinput(char* input)
{
    for(int i=0;i<100;i++)
    {
        input[i]='\0';
    }
    return;
}
