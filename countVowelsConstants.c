#include <stdio.h>
#include <ctype.h>

int main()
{
    char str[100];                  // Array to hold the input string
    int vowels = 0, consonants = 0; // Counters for vowels and consonants
    int i = 0;

    // Prompt the user to enter a string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); // Read a line of input

    // Iterate through each character in the string
    while (str[i] != '\0')
    {
        char ch = tolower(str[i]); // Convert to lowercase for uniformity

        // Check if the character is an alphabet
        if (isalpha(ch))
        {
            // Check if the character is a vowel
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                vowels++;
            }
            else
            {
                // If it's not a vowel, then it must be a consonant
                consonants++;
            }
        }
        i++; // Move to the next character
    }

    // Display the results
    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);

    return 0;
}