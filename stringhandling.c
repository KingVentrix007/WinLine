#include "stdio.h";
#include "stdlib.h";
#include "string.h";
#define MAX_LENGTH 100
void splitString(const char* str, const char* delimiter, char result[][MAX_LENGTH], int* count) {
    char temp[MAX_LENGTH];
    char* token = strtok(str, delimiter);
    
    while (token != NULL) {
        strcpy(temp, token);
        strcpy(result[*count], temp);
        (*count)++;
        token = strtok(NULL, delimiter);
    }
}

int splitter() {
    char inputString[MAX_LENGTH];
    char delimiter[MAX_LENGTH];
    char result[MAX_LENGTH][MAX_LENGTH];
    int count = 0;
    
    printf("Enter the string: ");
    fgets(inputString, sizeof(inputString), stdin);
    
    printf("Enter the delimiter: ");
    fgets(delimiter, sizeof(delimiter), stdin);
    
    // Remove newline characters from input
    inputString[strcspn(inputString, "\n")] = '\0';
    delimiter[strcspn(delimiter, "\n")] = '\0';
    
    splitString(inputString, delimiter, result, &count);
    
    printf("Resulting components:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", result[i]);
    }
    
    return 0;
}