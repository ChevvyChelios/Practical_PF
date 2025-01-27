#include <stdio.h>
#include <string.h>

void removeDuplicates(char *str) {
    int hash[256] = {0}; // Array to keep track of character occurrences
    int index = 0; // Index for the new string
    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        // If the character has not been encountered before
        if (hash[(unsigned char)str[i]] == 0) {
            hash[(unsigned char)str[i]] = 1; // Mark character as encountered
            str[index++] = str[i]; // Add it to the new string
        }
    }
    str[index] = '\0'; // Null-terminate the new string
}

int main() {
    char str[100]; // Input string buffer

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); // Read input string
    str[strcspn(str, "\n")] = 0; // Remove newline character if present

    removeDuplicates(str);
    printf("String after removing duplicates: %s\n", str);

    return 0;
}