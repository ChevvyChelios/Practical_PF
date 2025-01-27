
#include <stdio.h>

unsigned int reverseBits(unsigned int n)
{
    unsigned int result = 0;
    int bits = sizeof(n) * 8;
    for (int i = 0; i < bits; i++)
    {
        result = (result << 1) | (n & 1);
        n = n >> 1;
    }
    return result;
}

int main()
{
    unsigned int number;

    // Input a number
    printf("Enter a positive integer: ");
    scanf("%u", &number);

    // Reverse the bits of the number
    unsigned int reversedNumber = reverseBits(number);

    // Output the result
    printf("Original number: %u\n", number);
    printf("Reversed bits: %u\n", reversedNumber);
    printf("\n");
    return 0;
}