
#include <stdio.h>

// Function to calculate factorial using iterative method
unsigned long long factorial_iterative(int n)
{
    unsigned long long result = 1; // Use unsigned long long for larger results
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

// Function to calculate factorial using recursive method
unsigned long long factorial_recursive(int n)
{
    if (n == 0 || n == 1)
    {
        return 1; // Base case
    }
    else
    {
        return n * factorial_recursive(n - 1); // Recursive case
    }
}

int main()
{
    int number;

    // Prompt user for input
    printf("Enter a non-negative integer: ");
    scanf("%d", &number);

    // Check for non-negative input
    if (number < 0)
    {
        printf("Factorial is not defined for negative numbers.\n");
        return 1; // Exit with error code
    }

    // Calculate factorial using iterative method
    unsigned long long iterative_result = factorial_iterative(number);
    printf("Factorial of %d (iterative method) is: %llu\n", number, iterative_result);

    // Calculate factorial using recursive method
    unsigned long long recursive_result = factorial_recursive(number);
    printf("Factorial of %d (recursive method) is: %llu\n", number, recursive_result);

    return 0; // Successful execution
}