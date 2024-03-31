#include "matrix.h"


/**
 * @brief Проверяет, является ли столбец матрицы по убыванию
 * @param matrix Матрица для проверки
 * @param n Количество строк в матрице
 * @param col Индекс столбца для проверки
 * @return true, если столбец по убыванию, иначе false
 */
bool is_descending(int matrix[MAX_SIZE][MAX_SIZE], size_t n, size_t col)
{
    if (n == 1)
    {
        return false;
    }
    for (size_t i = 0; i < n - 1; i++)
    {
        if (matrix[i][col] <= matrix[i + 1][col])
        {
            return false;
        }
    }
    return true;
}

/**
 * @brief Заполняет матрицу значениями, введенными пользователем
 * @param matrix Матрица для заполнения
 * @param n Количество строк в матрице
 * @param m Количество столбцов в матрице
 * @return 0 в случае успеха, 1 в случае ошибки ввода
 */
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
