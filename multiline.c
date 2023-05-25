#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 10
#define MAX_LENGTH 100

char multi() {
    char input[MAX_LINES * MAX_LENGTH]; // Buffer to store the input
    char line[MAX_LENGTH]; // Buffer to store each line
    int num_lines = 0; // Counter for the number of lines

    printf("Enter multiple lines of text (Ctrl+D or Ctrl+Z to finish):\n");

    // Read lines until the maximum number of lines is reached or EOF is encountered
    while (num_lines < MAX_LINES && fgets(line, sizeof(line), stdin) != NULL) {
        strcat(input, line); // Concatenate the line to the input buffer
        num_lines++;
    }

    printf("\nEntered text:\n%s\n", input);
    return input;
    //return 0;
}