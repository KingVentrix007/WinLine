#include "stdio.h";
#include "stdlib.h";
#include "string.h";
#include "console.h";
#include "erros.h";





int main()
{
    int exitValue = 0;
    while (exitValue == 0) 
    {
        char* command[30];
        printf("Enter a command3> ");
        fgets(command, sizeof(command), stdin);
        char * args = command;
        if (strstr(command, " /")!=NULL)
        {
            char * argsC = strtok(command, " /");
            memcpy(args, argsC,strlen(args));
            printf("/\n");

        }
        else
        {
            char * argsC = command;
            memcpy(args, argsC,strlen(args));
            printf("No /\n");
        }
        
        printf("ARGS: %s\n", args);
        if (strcmp("help",args) == 0)
        {
            printf("Help command\n");
        }
        if(strcmp(args, "exit") == 0)
        {
            printf("Exit\n");
            exitValue = 1;
        }
        else 
        {
            printf("Command not found\n");

        }
        // while (args != NULL)
        // {
        //     printf("%s\n", args);
        //     args = strtok(NULL, " ");
        // }
        
        

    }
    
}
