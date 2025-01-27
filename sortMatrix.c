
#include <stdio.h>

#define ROWS 3
#define COLS 4

// Function to print the matrix
void print_matrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort the elements of the matrix
void sort_matrix(int matrix[ROWS][COLS]) {
    int total_elements = ROWS * COLS;
    int temp[total_elements];

    // Flatten the matrix into a 1D array
    int index = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            temp[index++] = matrix[i][j];
        }
    }

    // Sort the 1D array (using bubble sort for simplicity)
    for (int i = 0; i < total_elements - 1; i++) {
        for (int j = 0; j < total_elements - i - 1; j++) {
            if (temp[j] > temp[j + 1]) {
                // Swap
                swap(&temp[j], &temp[j + 1]);
            }
        }
    }

    // printf("\n2nd Smallest element: %d\n", temp[1]);

    // Reshape the sorted array back into the matrix
    index = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = temp[index++];
        }
    }
}

int main() {
    int matrix[ROWS][COLS] = {
        {12, 5, 3, 8},
        {7, 1, 14, 6},
        {9, 10, 2, 11}
    };

    printf("Original matrix:\n");
    print_matrix(matrix);

    sort_matrix(matrix);

    printf("\nSorted matrix:\n");
    print_matrix(matrix);

    return 0;
}