#include "matrix.h"

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

/**
 * @brief Заполняет матрицу ходом быка.
 * @param matrix Матрица для заполнения.
 * @param n Количество строк в матрице.
 * @param m Количество столбцов в матрице.
 */
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