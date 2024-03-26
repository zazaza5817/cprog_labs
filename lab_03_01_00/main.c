#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

void print_array(int array[], size_t n)
{
    printf("Output array: ");
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

bool is_descending(int matrix[MAX_SIZE][MAX_SIZE], size_t n, size_t col)
{
    for (size_t i = 0; i < n - 1; i++)
    {
        if (matrix[i][col] <= matrix[i + 1][col])
        {
            return false;
        }
    }
    return true;
}

int fill_matrix(int matrix[MAX_SIZE][MAX_SIZE], size_t n, size_t m)
{
    int value;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if (scanf("%d", &value) != 1)
            {
                return 1;
            }
            matrix[i][j] = value;
        }
    }
    return 0;
}

int main(void)
{
    size_t n, m;
    int matrix[MAX_SIZE][MAX_SIZE];

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
    int rc = fill_matrix(matrix, n, m);
    if (rc != 0)
    {
        printf("Incorrect matrix element specified!");
        return 1;
    }

    int result[MAX_SIZE];
    for (size_t i = 0; i < m; i++)
    {
        result[i] = is_descending(matrix, n, i) ? 1 : 0;
    }

    print_array(result, m);
    return 0;
}