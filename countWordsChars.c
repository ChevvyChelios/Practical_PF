
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    FILE *file;
    char filename[100];
    char ch;
    int word_count = 0;
    int char_count = 0;
    int in_word = 0; // Flag to track if we are inside a word

    // Prompt the user to enter the filename
    printf("Enter the filename to read: ");
    scanf("%s", filename);

    // Open the file in read mode
    file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return EXIT_FAILURE; // Exit if the file could not be opened
    }

    // Read the file character by character
    while ((ch = fgetc(file)) != EOF)
    {
        char_count++; // Increment character count for every character read

        // Check if the character is a whitespace
        if (isspace(ch))
        {
            if (in_word)
            {
                in_word = 0; // We have reached the end of a word
            }
        }
        else
        {
            if (!in_word)
            {
                in_word = 1;  // We are inside a word now
                word_count++; // Increment word count
            }
        }
    }

    // Close the file
    fclose(file);

    // Display the results
    printf("Total number of characters: %d\n", char_count);
    printf("Total number of words: %d\n", word_count);

    return EXIT_SUCCESS; // Indicate successful completion
}