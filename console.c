#include "stdio.h";
#include "stdlib.h";
#include "string.h";
#include "console.h";
#include "erros.h";
#include "windows.h";
#include "direct.h";
#include "filehandling.c";
#include "debuger.c";




int main()
{
    
    int debug = -1;
    char currentDir[MAX_PATH];

    if (GetCurrentDirectory(MAX_PATH, currentDir) == 0) {
        printf("Failed to retrieve the current directory.\n");
        return 1;
    }

    printf("Current Directory: %s\n", currentDir);
    int exitValue = 0;
    while (exitValue == 0) 
    {
        char* command[30];
        printf("Enter a command1> ");
        fgets(command, sizeof(command), stdin);
        char * args = command;
        if (strstr(command, " /")!=NULL)
        {
            char * argsC = strtok(command, " /");
            memcpy(args, argsC,strlen(args));
            debug_win("/\n",debug);

        }
        else
        {
            char * argsC = command;
            memcpy(args, argsC,strlen(args));
            debug_win("No /\n",debug);
        }
        if (strstr(args,"help") != NULL)
        {
            printf("Help command\n");
        }
        else if(strstr(args, "exit") != NULL)
        {
            printf("Exit\n");
            exitValue = 1;
        }
        else if(strstr(args, "rfile") != NULL)
        {
            int exitC;
            exitC = ReadFileWin();
            debug_win(exitC,debug);
        }
        else if (strstr(args, "wfile") != NULL)
        {
            int exitC;
            exitC = WriteFileWin();
            debug_win(exitC,debug);
        }
        else if (strstr(args, "mfile") != NULL)
        {
            int exitC;
            exitC = MakeFileWin();
            debug_win(exitC,debug);

        }
        else if (strstr(args, "dfile") != NULL)
        {
            int exitC;
            exitC = DeleteFileWin();
            debug_win(exitC,debug);

        }
        else if (strstr(args, "cd") != NULL)
        {
            int exitC;
            exitC = setDirectoryWin();
            debug_win(exitC,debug);

        }
        else if(strstr(args, "debug") != NULL)
        {
            debug = 0;
        }
        
        else 
        {
            printf("Command not found\n");

        }
        
        
        

    }
    
}
