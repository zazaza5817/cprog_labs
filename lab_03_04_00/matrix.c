#include "matrix.h"

/**cd
 * @brief Заполняет матрицу значениями, введенными пользователем.
 * @param matrix Матрица для заполнения.
 * @param n Количество строк в матрице.
 * @param m Количество столбцов в матрице.
 * @return 0 в случае успешного заполнения, 1 в случае ошибки ввода.
 */
int fill_matrix(int matrix[MAX_SIZE][MAX_SIZE], size_t n)
{
    int value;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
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

/**
 * @brief Находит наименьшее нечетное число под главной диагональю квадратной матрицы.
 * @param matrix Матрица, в которой искать наименьшее нечетное число.
 * @param n Количество строк и столбцов в матрице.
 * @param value Указатель на переменную, в которую будет сохранено найденное число.
 * @return 0, если найдено нечетное число, иначе 1.
 */
int find_value(int matrix[MAX_SIZE][MAX_SIZE], size_t n, int *value)
{
    bool flag = false;
    *value = INT_MAX;
    for (size_t i = 1; i < n; i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            if (matrix[i][j] % 2 != 0 && matrix[i][j] < *value)
            {
                *value = matrix[i][j];
                flag = true;
            }
        }
    }
    return !flag;
}