#include<stdio.h>
#include<string.h>

void compressString(const char *input, char* output){
    int count=1, j=0;
    for (int i=0; i < strlen(input); i++){
        if (input[i] == input[i+1]){
            count++;
        }
        else {
            output[j++] = input[i];
            if (count > 1){
                j += sprintf(&output[j], "%d", count);
            }
            count = 1;
        }
    }
    output[j] = '\0';
}
int main()
{
    char input[100];  // Input string
    char output[200]; // Output string for compressed result

    // Input the string from the user
    printf("Enter a string to compress: ");
    scanf("%s", input);

    // Compress the string
    compressString(input, output);

    // Output the compressed string
    printf("Compressed string: %s\n", output);
    return 0;
}