#include "matrix.h"

int main(void)
{
    size_t n, m;
    int matrix[MAX_SIZE * 2][MAX_SIZE];

    printf("Enter the number of matrix rows: ");
    if (scanf("%zu", &n) != 1 || n == 0 || n > MAX_SIZE)
    {
        printf("The number of matrix rows is set incorrectly!");
        return 1;
    }

    printf("Enter the number of matrix columns: ");
    if (scanf("%zu", &m) != 1 || m == 0 || m > MAX_SIZE)
    {
        printf("The number of matrix columns is set incorrectly!");
        return 1;
    }

    printf("Enter matrix elements: ");

    if (fill_matrix(matrix, n, m) != 0)
    {
        printf("Incorrect matrix element specified!");
        return 1;
    }

    int digit;
    printf("Enter digit: ");
    if (scanf("%d", &digit) != 1 || digit < 0 || digit > MAX_DIGIT)
    {
        printf("Only digits must be inputted!");
        return 1;
    }
    if (process_matrix(matrix, &n, &m, digit) != 0)
    {
        return 1;
    }
    printf("processed matrix:\n");
    display_matrix(matrix, n, m);

    return 0;
}
