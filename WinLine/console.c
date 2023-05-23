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
        printf("hello world> ");
        fgets(command, sizeof(command), stdin);
        if (strstr(command, "hello") != NULL)
        {
            char* args = strtok(command, " ");
            printf("%s", args);


        }
        

    }
    
}
