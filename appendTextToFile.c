
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file;
    char filename[100];
    char text[256];

    // Prompt the user to enter the file name
    printf("Enter the file name to append text: ");
    scanf("%s", filename);

    // Open the file in append mode
    file = fopen(filename, "a"); // 'a' mode opens the file for appending
    if (file == NULL)
    {
        perror("Error opening file");
        return EXIT_FAILURE; // Exit if the file could not be opened
    }

    // Prompt the user to enter the text to append
    printf("Enter the text to append: ");
    getchar();                        // To consume the newline character left in the input buffer
    fgets(text, sizeof(text), stdin); // Read a line of text from standard input

    // Write the text to the file
    fputs(text, file);

    // Close the file
    fclose(file);

    printf("Text appended to %s successfully.\n", filename);

    return EXIT_SUCCESS; // Indicate successful completion
}