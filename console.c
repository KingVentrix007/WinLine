#include "stdio.h";
#include "stdlib.h";
#include "string.h";
#include "console.h";
#include "erros.h";
#include "windows.h";
#include "direct.h";
#include "filehandling.c";
#include "debuger.c";
#include "stringhandling.c";
#include "multiline.c";



#include <stdio.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10
#define MAX_ARGUMENT_LENGTH 20

int init_system(char *check)
{
    if (strcmp(check, "check") == 0)
    {
        if (directoryExists("system"))
        {
            return 0;
        }
        else
        {
            return FileNotFound;
        }

    }
    else if (strcmp(check, "system"))
    {
        int out = MakeDirectory("system");
        if(out == 0)
        {
            printf("%s created\n", check);
        }
        else if (out == -1)
        {
            printf("%s Failed to create\n", check);
        }
        
    }
    else if (strcmp(check,"sys_var.txt") == 0)
    {
       int out = FileExists("system/sys.var.txt");
       return out;
    }
    
    

}

int main() {
    int out;
    out = init_system("check");
    if (out == 404)
    {
        out = init_system("system");
    }
    else if (out == 0)
    {
        out = init_system("sys_var.txt");
        if (out == 404)
        {
            MakeFileWin("system/sys.var.txt");
        }
        else if (out == 1)
        {
            char vars = ReadFileWin("system/var.txt");
            printf("%s\n", vars);
        }
        
    }
    char input[MAX_COMMAND_LENGTH];
    char* arguments[MAX_ARGUMENTS];
    int numArguments;

    while (1) {
        printf("\033[0;32mEnter command> ");
        printf("\033[0;37m");
        fgets(input, sizeof(input), stdin);
        
        // Remove newline character from input
        input[strcspn(input, "\n")] = '\0';

        parseCommand(input, arguments, &numArguments);
        
        // Handle exit command
        if (strcmp(arguments[0], "exit") == 0)
        {
            if (numArguments -1 == 0)
            {
                break;
            }
            else if (numArguments -1 >= 1)
            {
                printf("exit takes no arguments\n");
            }
            
            
        }
        else if (strcmp(arguments[0], "help") == 0)
        {
            printf("Available commands: ");
            printf("\n\tComing soon\n");
        }
        else if (strcmp(arguments[0], "rfile") == 0 && (numArguments -1 ==1))
        { 
            ReadFileWin(arguments[1]);
        }
        else if (strcmp(arguments[0], "wfile") == 0 && (numArguments -1 ==2))
        { 
            if(strcmp(arguments[2], "a") != 0)
            { 
                WriteFileWin(arguments[1],arguments[2]);
            }
            else if (strcmp(arguments[2], "a")==0)
            {
                char write = multi();
                printf("%s\n",write);
                //WriteFileWin(arguments[1],write);
            }
        }
        else if (strcmp(arguments[0], "mfile") == 0 && (numArguments -1 ==1))
        { 
            MakeFileWin(arguments[1]);
        }
         else if (strcmp(arguments[0], "dfile") == 0 && (numArguments -1 ==1))
        { 
            DeleteFileWin(arguments[1]);
        }
        else if (strcmp(arguments[0], "mfile") == 0 && (numArguments -1 ==1))
        { 
            setDirectoryWin(arguments[1]);
        }
        else if (strcmp(arguments[0], "ls") == 0 && (numArguments -1 ==0))
        { 
            ListContents();
        }
        
            
        
        // Handle other commands
        // You can add more commands and their respective functionalities here

        //@printf("Command: %s\n", arguments[0]);
        //@printf("Arguments (%d): ", numArguments - 1);
        
        // for (int i = 1; i < numArguments; i++)
        //     printf("%s ", arguments[i]);
        
        // printf("\n\n");
    }

    return 0;
}
