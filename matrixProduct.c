#include <stdio.h>

void inputMatrix(int matrix[10][10], int rows, int cols)
{
    printf("Enter elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[10][10], int rows, int cols)
{
    printf("Matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrices(int mat1[10][10], int mat2[10][10], int result[10][10], int r1, int c1, int c2)
{
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            result[i][j] = 0; // Initialize the result matrix element
            for (int k = 0; k < c1; k++)
            {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main()
{
    int mat1[10][10], mat2[10][10], result[10][10];
    int r1, c1, r2, c2;

    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &r2, &c2);

    // Check if multiplication is possible
    if (c1 != r2)
    {
        printf("Matrix multiplication not possible. The number of columns of the first matrix must equal the number of rows of the second matrix.\n");
        return 0;
    }

    // Input matrices
    printf("Input for first matrix:\n");
    inputMatrix(mat1, r1, c1);
    printf("Input for second matrix:\n");
    inputMatrix(mat2, r2, c2);

    // Perform multiplication
    multiplyMatrices(mat1, mat2, result, r1, c1, c2);

    // Display results
    printf("First Matrix:\n");
    displayMatrix(mat1, r1, c1);
    printf("Second Matrix:\n");
    displayMatrix(mat2, r2, c2);
    printf("Resultant Matrix (Product):\n");
    displayMatrix(result, r1, c2);

    return 0;
}
