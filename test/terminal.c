#include <stdio.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10
#define MAX_ARGUMENT_LENGTH 20

void parseCommand(char* command, char** arguments, int* numArguments) {
    *numArguments = 0;
    char* token = strtok(command, " ");
    
    while (token != NULL) {
        arguments[*numArguments] = token;
        (*numArguments)++;
        token = strtok(NULL, " ");
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char* arguments[MAX_ARGUMENTS];
    int numArguments;

    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);
        
        // Remove newline character from input
        input[strcspn(input, "\n")] = '\0';

        parseCommand(input, arguments, &numArguments);
        
        // Handle exit command
        if (strcmp(arguments[0], "exit") == 0)
            break;
        
        // Handle other commands
        // You can add more commands and their respective functionalities here

        printf("Command: %s\n", arguments[0]);
        printf("Arguments (%d): ", numArguments - 1);
        
        for (int i = 1; i < numArguments; i++)
            printf("%s ", arguments[i]);
        
        printf("\n\n");
    }

    return 0;
}
