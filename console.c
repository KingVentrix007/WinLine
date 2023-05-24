#include "stdio.h";
#include "stdlib.h";
#include "string.h";
#include "console.h";
#include "erros.h";
//#include "winbase.h";
#include "windows.h";
//#include <direct.h>;
int ReadFileWin()
{
    FILE *file;
    char filename[100];
    char ch;

    printf("Enter the file name: ");
    scanf("%s", filename);

    // Open the file in read mode
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }

    printf("File contents:\n");

    // Read and print each character until the end of file
    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }
    printf("\n");

    // Close the file
    fclose(file);

    return 0;
}
// char ReadFile(char *filename)
// {
//     FILE *fp;
//     char buff[100];
//     fp = fopen(filename, "r");
//     fgets(buff, 255, fp);
//     printf("%s\n", filename);
//     printf("HERE");
//     return buff;
// }


void printD(char *input, int* debug)
{
    if (debug == 0)
    {
        printf("%s", input);
    }
    
}


int main()
{
    
    int debug = 1;
    char currentDir[MAX_PATH];

    if (GetCurrentDirectory(MAX_PATH, currentDir) == 0) {
        printf("Failed to retrieve the current directory.\n");
        return 1;
    }

    printf("Current Directory: %s\n", currentDir);
    // if (argc == 2)
    // {
    //     if (strcmp(argv[1], "debug") == 0)
    //     {
    //         int debug = 0;
    //     }
    // }
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
            printD("/\n",debug);

        }
        else
        {
            char * argsC = command;
            memcpy(args, argsC,strlen(args));
            printD("No /\n",debug);
        }
        
        ///printf("AARGS: %s\n", args);
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
            ReadFileWin();
            // printD("Length of args%i\n",strlen(args));
            // char *argsFile[5];
            // for (int i = 0; i < 5; i++)
            // {
            //     // if (strcmp(args,NULL) == 0)
            //     // {
            //     //     i = 5;
            //     // }
                
            //     if(args != NULL)
            //     {
            //         //printf("ARGS: %s\n", args);
            //         argsFile[i] = args;
            //         //printf("argsFile%s\n", argsFile[i]);

            //     }
                
            //     args = strtok(NULL, " /");
            // }
            // ReadFile(argsFile[1]);
            //printf("File %s\n", buff);
            
            
        }
        else 
        {
            printf("Command not found\n");

        }
        
        
        

    }
    
}
