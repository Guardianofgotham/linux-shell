#include "OuterCommandHandler.h"

void outerCommandHandler(char *command)
{
    if(command[0]=='l' && command[1]=='s' && command[2]==' ')
    {

        pid_t pid = fork();
        if(pid == 0){
            execl("/bin/ls","ls",command+3,(char *)0);
        }
        wait(NULL);
    }
    else if(command[0]=='l' && command[1]=='s')
    {
        system("ls");
    }
    else if(command[0]=='c' && command[1]=='a' && command[2]=='t')
    {
        pid_t pid = fork();
        if(pid==0)
        {
            execl("/bin/cat","cat",command+4,(char *)0);
        }
        wait(NULL);
    }
    else if(areEqual(command,"clear"))
    {
        pid_t pid = fork();
        if(pid==0)
        {
            execl("/usr/bin/clear","clear",(char *)0);
        }
        wait(NULL);
    }
    else if(areEqual(command,"date") && *(command+5)=='-')
    {
        pid_t pid = fork();
        if(pid==0)
        {
            execl("/bin/date","date",command+5,(char *)0);
        }
        wait(NULL);
    }
    else if(areEqual(command,"date"))
    {
        pid_t pid = fork();
        if(pid==0)
        {
            execl("/bin/date","date",(char *)0);
        }
        wait(NULL);
    }
    else if(areEqual(command,"mkdir"))
    {
        pid_t pid = fork();
        if(pid==0)
        {
            execl("/bin/mkdir","mkdir",command+6,(char *)0);
        }
        wait(NULL);
    }
    else if(command[0]=='r' && command[1]=='m' && command[3]=='-')
    {
        if(command[4]=='r'){
            pid_t pid = fork();

            if(pid==0)
            {
                printf("Attempting to remove file ...\n");
                system("");         ///unknown reason may be making a system call inside child process;
                execl("/bin/rm","rm","-r",command+6,(char *)0);
            }
        wait(NULL);
        }
        else if(command[4]=='i'){
            pid_t pid = fork();

            if(pid==0)
            {
                printf("Attempting to remove file ...\n");
                system("");         ///unknown reason may be making a system call inside child process;
                execl("/bin/rm","rm","-i",command+6,(char *)0);
            }
        wait(NULL);
        }
        else{
            printf("Flag not found or not configured\n");
        }

        }

    else if(command[0]=='r' && command[1]=='m')
    {
        pid_t pid = fork();
        if(pid==0)
        {
            execl("/bin/rm","rm",command+3,(char *)0);
        }
        wait(NULL);
    }

    else{
        printf("Command not Found\n");
    }

}
