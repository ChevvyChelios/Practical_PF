#include <stdio.h>
#include <limits.h>

#define ROWS 3
#define COLS 4

// Function to find the second largest value and its index in the matrix
void find_second_largest(int matrix[ROWS][COLS], int *second_largest, int *row_index, int *col_index) {
    int largest = INT_MIN;
    *second_largest = INT_MIN; // Initialize second largest to the smallest integer
    *row_index = -1; // Initialize row index
    *col_index = -1; // Initialize column index

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] > largest) {
                // Update second largest before updating largest
                *second_largest = largest;
                largest = matrix[i][j];
                *row_index = i;
                *col_index = j;
            } else if (matrix[i][j] > *second_largest && matrix[i][j] < largest) {
                *second_largest = matrix[i][j];
                *row_index = i;
                *col_index = j;
            }
        }
    }
}

int main() {
    int matrix[ROWS][COLS] = {
        {12, 5, 3, 8},
        {7, 1, 14, 6},
        {9, 10, 2, 11}
    };

    int second_largest, row_index, col_index;

    find_second_largest(matrix, &second_largest, &row_index, &col_index);

    if (second_largest != INT_MIN) {
        printf("The second largest value is %d at index (%d, %d).\n", second_largest, row_index, col_index);
    } else {
        printf("There is no second largest value in the matrix.\n");
    }

    return 0;
}