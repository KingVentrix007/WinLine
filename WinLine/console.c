#include "stdio.h";
#include "stdlib.h";
#include "string.h";
#include "console.h";
#include "erros.h";
printf("Start");



int main()
{
    int exitValue = 0;
    while (exitValue == 0) 
    {
        char* command[30];
        printf("Enter a command> ");
        fgets(command, sizeof(command), stdin);
       
        char * args = strtok(command, "/");
        if (strcmp(args, "help") == 0)
        {
            printf("Help command");
        }
        if(strcmp(args, "exit") == 0)
        {
            printf("Exit");
            exitValue = 1;
        }
        // while (args != NULL)
        // {
        //     printf("%s\n", args);
        //     args = strtok(NULL, " ");
        // }
        
        

    }
    
}
