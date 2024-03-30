#include <stdio.h>

#define MAX_SIZE 10

/**
 * @brief Выводит матрицу на экран.
 * @param matrix Матрица для вывода.
 * @param n Количество строк в матрице.
 * @param m Количество столбцов в матрице.
 */
void display_matrix(int matrix[MAX_SIZE][MAX_SIZE], size_t n, size_t m)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void fill_matrix(int matrix[MAX_SIZE][MAX_SIZE], int n, int m)
{
    int value = 1;
    for (int j = 0; j < m; ++j)
    {
        if (j % 2 == 0)
        {
            for (int i = 0; i < n; ++i, ++value)
            {
                matrix[i][j] = value;
            }
        }
        else
        {
            for (int i = n - 1; i >= 0; --i, ++value)
            {
                matrix[i][j] = value;
            }
        }
    }
}

int main()
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

    fill_matrix(matrix, n, m);

    printf("Generated matrix:\n");
    display_matrix(matrix, n, m);
    return 0;
}
