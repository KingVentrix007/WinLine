#include "stdio.h";
#include "stdlib.h";
#include "string.h";
#define MAX_LENGTH 100

char split(char *str,char *delimiters)
{
    char array_out[MAX_LENGTH];
    char *token = strtok(str,delimiters);
    int count = 0;
     while (token != NULL)
    {
            printf("Split: %s\n", token);
            array_out[count] = token;
            count++;
                
            
            token = strtok(NULL, delimiters);
    }
} 