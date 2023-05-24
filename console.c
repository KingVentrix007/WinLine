#include "stdio.h";
#include "stdlib.h";
#include "string.h";
#include "console.h";
#include "erros.h";
#include "windows.h";
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
        }
        else 
        {
            printf("Command not found\n");

        }
        
        
        

    }
    
}
