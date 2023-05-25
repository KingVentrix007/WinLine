#include "filehandling.h";
#include "stdio.h";
#include "string.h";
#include "stdlib.h";
#include "windows.h";
#include "direct.h";
int ReadFileWin(char filename_in[100])
{
    FILE *file;
    char filename[100];
    char ch;
    
    //printf("Enter the file name: ");
    //fgets(filename, sizeof(filename), stdin);
    ///scanf("%s", filename);
    int i;
    while (filename[i] != '\n' && filename[i] != '\0') {
        i++;
    }
    filename[i] = '\0';

    // Open the file in read mode
    file = fopen(filename_in, "r");

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
int WriteFileWin(char filename[100])
{
    
    char data[100];
    FILE *file;
    //char filename[100];
    char ch;

    //printf("Enter the file name: ");
    //fgets(filename, sizeof(filename), stdin);
    // int i;
    // while (filename[i] != '\n' && filename[i] != '\0') {
    //     i++;
    // }
    // filename[i] = '\0';
    printf("Enter the data to write to the file: ");
    fgets(data, sizeof(data), stdin);
    int q;
    while (data[q] != '\n' && data[q] != '\0') {
        q++;
    }
    data[q] = '\0';
    //scanf("%s", data);

    // Open the file in write mode ("w" flag)
    file = fopen(filename, "w");
    
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }
    
    // Write data to the file
    fprintf(file, "%s", data);
    
    // Close the file
    fclose(file);
    
    printf("Data has been written to the file.\n");
    
    return 0;

}
int MakeFileWin(char filename[100])
{
    FILE *file;
    // char filename[100];
    // printf("Enter the file name: ");
    // fgets(filename, sizeof(filename), stdin);
    // int i;
    // while (filename[i] != '\n' && filename[i] != '\0') {
    //     i++;
    // }
    // filename[i] = '\0';

    ///scanf("%s", filename);
    printf("filename: %s\n", filename);
    // Open the file in write mode
    file = fopen(filename, "w");

    if (file == NULL) {
        printf("Unable to create the file.\n");
        return 1;
    }

    // Write some content to the file
    fprintf(file, "");

    // Close the file
    fclose(file);

    printf("File created successfully.\n");

    return 0;
}
int DeleteFileWin(char file_path[100])
{
    // char file_path[100];

    // printf("Enter the path of the file to be deleted: ");
    // fgets(file_path, sizeof(file_path), stdin);

    // // Remove the newline character from the file_path
    // int i = 0;
    // while (file_path[i] != '\n' && file_path[i] != '\0') {
    //     i++;
    // }
    // file_path[i] = '\0';

    // Delete the file
    if (remove(file_path) == 0) {
        printf("File deleted successfully.\n");
    } else {
        printf("Unable to delete the file.\n");
    }

    return 0;
}
int setDirectoryWin(char newDirectory[100])
{
    // char newDirectory[100];  // Adjust the size as per your needs

    // printf("Enter the new directory path: ");
    // fgets(newDirectory, sizeof(newDirectory), stdin);

    // // Remove newline character from the end of the directory path
    // newDirectory[strcspn(newDirectory, "\n")] = '\0';

    if (_chdir(newDirectory) == 0) {
        printf("Current working directory changed to: %s\n", newDirectory);
    } else {
        printf("Failed to change the current working directory.\n");
    }

    return 0;
}
