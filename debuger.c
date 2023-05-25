#include "stdio.h";
#include "stdlib.h";
#include "string.h";

void printExitCode(char *input)
{
    printf("%i\n", input);
}
void printD(char *input)
{
    printf("%s\n", input);
}
void debug_win(char *input, int* debug_level)
{
    if (debug_level == "0")
    {
        printD(input);
    }
    else if (debug_level == "2")
    {
       printExitCode(input);
    }
    
    
}