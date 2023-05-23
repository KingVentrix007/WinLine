#include "stdio.h";
#include "stdlib.h";
#include "string.h";
#include "console.h";
#include "erros.h";


int* exitCode = 0;
int main()
{
    while (exitCode == 0)
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
