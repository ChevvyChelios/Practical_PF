
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *sourceFile, *destFile;
    char sourceFilename[100], destFilename[100];
    char ch;

    // Prompt the user to enter the source file name
    printf("Enter the source file name: ");
    scanf("%s", sourceFilename);

    // Open the source file in read mode
    sourceFile = fopen(sourceFilename, "r");
    if (sourceFile == NULL)
    {
        perror("Error opening source file");
        return EXIT_FAILURE; // Exit if the file could not be opened
    }

    // Prompt the user to enter the destination file name
    printf("Enter the destination file name: ");
    scanf("%s", destFilename);

    // Open the destination file in write mode
    destFile = fopen(destFilename, "w");
    if (destFile == NULL)
    {
        perror("Error opening destination file");
        fclose(sourceFile);  // Close the source file before exiting
        return EXIT_FAILURE; // Exit if the file could not be opened
    }

    // Copy contents from source file to destination file
    while ((ch = fgetc(sourceFile)) != EOF)
    {
        fputc(ch, destFile); // Write each character to the destination file
    }

    // Close both files
    fclose(sourceFile);
    fclose(destFile);

    printf("Contents copied from %s to %s successfully.\n", sourceFilename, destFilename);

    return EXIT_SUCCESS; // Indicate successful completion
}