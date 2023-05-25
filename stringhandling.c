#include "stdio.h";
#include "stdlib.h";
#include "string.h";
#define MAX_LENGTH 100

char split(char strs[],char delimiterss)
{
    // char array_out[MAX_LENGTH];
    // char *tokens = strtok(str,delimiters);
    // int count = 0;
    //  while (tokens != NULL)
    // {
    //         printf("Split: %s\n", tokens);
    //         //array_out[count] = token;
    //         count++;
                
            
    //         tokens = strtok(NULL, delimiters);
    // }
    
    char str[100];
    strcpy(str,strs);
    // Returns first token
    char *token = strtok(str, " /");
   
    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, " /");
    }
 
    //return 0;
}
void parse_string(char *parser, char *string, char c)
{
    int i = 0;

    while (string[i] != c)
    {
        parser[i] = string[i];
        i++;
    }
    parser[i] = '\0';
}