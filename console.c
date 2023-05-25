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




int main()
{
    
    int* debug = -1;
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
        // if (strstr(command, " /")!=NULL)
        // {
        //     char * argsC = strtok(command, " /");
        //     memcpy(args, argsC,strlen(args));
        //     debug_win("/\n",debug);

        // }
        // else
        // {
        //     char * argsC = command;
        //     memcpy(args, argsC,strlen(args));
        //     debug_win("No /\n",debug);
        // }
        if (strstr(args,"help") != NULL)
        {
            debug_win("Usage: help",debug);
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
            //int result;
            char *parser;
			char string[64];
			parser = strstr(args, "debug /");
			parser += strlen("debug /");
			parse_string(string, parser, ' ');
            
			///sha224(string);
            //split(args," /");
            printf("%s\n", string);
            if (strcmp(string,"0") == 0)
            {
                //printf("0");
                debug = 0;
            }
            else if (strcmp(string,"1") == 0)
            {
                //printf("1");
                debug = 1;
            }
            else
            {
                //printf("not valid");
                printf("Debug level %s is not a valid level",string);
            }
            //printf(type());
            //debug = string;
           

        }
        
        else 
        {
            printf("Command not found\n");

        }
        
        
        

    }
    
}
