#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file;         // Pointer to a file
    char filename[100]; // Array to hold the filename
    char ch;            // Variable to hold each character read from the file

    // Prompt the user to enter the filename
    printf("Enter the filename to read: ");
    scanf("%s", filename);

    // Open the file in read mode
    file = fopen(filename, "r");

    // Check if the file was opened successfully
    if (file == NULL)
    {
        perror("Error opening file");
        return EXIT_FAILURE; // Exit if the file could not be opened
    }

    // Read and display the contents of the file character by character
    printf("Contents of the file %s:\n", filename);
    while ((ch = fgetc(file)) != EOF)
    {
        putchar(ch); // Print the character to the screen
    }

    // Close the file
    fclose(file);
    printf("\n");

    return EXIT_SUCCESS; // Indicate successful completion
}