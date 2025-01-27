#include <stdio.h>

#define ROWS 3
#define COLS 4

// Function to calculate the mean of the matrix elements
double calculate_mean(int matrix[ROWS][COLS]) {
    int sum = 0;
    int total_elements = ROWS * COLS;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            sum += matrix[i][j]; // Sum all elements
        }
    }

    return (double)sum / total_elements; // Calculate mean
}

int main() {
    int matrix[ROWS][COLS] = {
        {12, 5, 3, 8},
        {7, 1, 14, 6},
        {9, 10, 2, 11}
    };

    double mean = calculate_mean(matrix);
    printf("The mean of the matrix elements is: %.2f\n", mean);

    return 0;
}