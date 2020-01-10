#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include "basicFunctions.h"
#include "OuterCommandHandler.h"



int main()
{
    init_shell();
    char *history = (char*) calloc(2048,sizeof(char));
    int currHistoryIndex=0;
    while(1)
    {
        char input[512];
        printCommandLine();
        scanf("\n%[^\n]s", &(input[0])); ///Taking whole line as input

        //printf("%c",input[9]);
        if(areEqual(input,"history") && input[9]=='c') ///For clearing history
        {
            currHistoryIndex=0;
            free(history);
            history = (char*) calloc(2048,sizeof(char));;
            nullifyinput(&(input[0]));
            continue;
        }
        else if(areEqual(input,"history") && input[9]=='l') ///For printing only first five commands
        {
            int count=0;
            for(int i=0;i<currHistoryIndex;i++)
            {
                if(history[i]=='`')
                {
                    count++;
                    printf("\n");
                }
                else{
                    printf("%c",history[i]);
                }
                if(count==5)
                {
                    break;
                }
            }
            nullifyinput(& (input[0]) );
            continue;
        }
        else if(areEqual(input,"history")) ///for printing history
        {
            for(int i=0;i<currHistoryIndex;i++){
                if(*(history+i)=='`')
                {
                    printf("\n");
                }
                else
                {
                    printf("%c",*(history+i));
                }
            }
            nullifyinput(& (input[0]) );
            continue;
        }

        ///For storing history of commands
        for(int i=0;i<strlen(input);i++){
            *(history+currHistoryIndex)=*(input+i);
            currHistoryIndex++;
        }
        currHistoryIndex++;
        *(history+currHistoryIndex)='`';        ///To identify the difference between current and next command
        currHistoryIndex++;

        ///Will return 1 if the command was in built & handle it on it's own else 0
        int inBuiltStatus = getCommand(&(input[0]) );

        ///will execute external commands
        if(inBuiltStatus==0){
            outerCommandHandler(&(input[0]) ) ;
            nullifyinput(& (input[0]) );
        }
        nullifyinput(& (input[0]) );
    }
    return 0;
}

