#include <stdio.h>

void printLowerTriangle(int matrix[20][20], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= j)
                printf("%d ", matrix[i][j]); // Print elements in the lower triangle
            else
                printf("0 "); // Print 0 for upper triangular elements
        }
        printf("\n"); // New line after each row
    }
}

int main()
{
    int n;
    int matrix[20][20];

    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Lower triangular matrix:\n");
    printLowerTriangle(matrix, n);

    return 0;
}
