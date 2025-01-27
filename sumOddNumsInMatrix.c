#include <stdio.h>

#define ROWS 3
#define COLS 4

// Function to calculate the sum of odd numbers in the matrix
int sum_odd_numbers(int matrix[ROWS][COLS]) {
    int sum = 0; // Initialize sum to 0

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] % 2 != 0) { // Check if the number is odd
                sum += matrix[i][j]; // Add to sum if it's odd
            }
        }
    }

    return sum; // Return the total sum of odd numbers
}

int main() {
    int matrix[ROWS][COLS] = {
        {12, 5, 3, 8},
        {7, 1, 14, 6},
        {9, 10, 2, 11}
    };

    int odd_sum = sum_odd_numbers(matrix);
    printf("The sum of odd numbers in the matrix is: %d\n", odd_sum);

    return 0;
}