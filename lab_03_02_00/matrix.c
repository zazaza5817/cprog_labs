#include "matrix.h"

/**
 * @brief Вставляет строку в матрицу.
 * @param matrix Матрица.
 * @param n Количество строк в матрице.
 * @param m Количество столбцов в матрице.
 * @param index Индекс строки для вставки.
 */
void insert_row(int matrix[MAX_SIZE * 2][MAX_SIZE], size_t *n, size_t m, size_t index)
{
    for (size_t i = *n; i >= index; i--)
    {
        for (size_t j = 0; j < m; j++)
        {
            matrix[i][j] = matrix[i - 1][j];
        }
    }
    for (size_t i = 0; i < MAX_SIZE; i++)
    {
        matrix[index][i] = OWERFLOW_CODE;
    }
    *n += 1;
}

/**
 * @brief Обрабатывает матрицу, вставляя строки при определенных условиях.
 * @param matrix Матрица.
 * @param n Количество строк в матрице.
 * @param m Количество столбцов в матрице.
 * @param digit Цифра для проверки.
 * @return 0, если вставки произведены, 1 в противном случае.
 */
int process_matrix(int matrix[MAX_SIZE * 2][MAX_SIZE], size_t *n, size_t m, int digit)
{
    int first_counter;
    int last_counter;
    for (size_t i = 0; i < *n; i++)
    {
        first_counter = 0;
        last_counter = 0;
        for (size_t j = 0; j < m; j++)
        {
            if (first_digit(matrix[i][j]) == digit)
            {
                first_counter++;
            }
            if (last_digit(matrix[i][j]) == digit)
            {
                last_counter++;
            }
        }
        if (first_counter == last_counter && first_counter != 0)
        {
            insert_row(matrix, n, m, i + 1);
            i++;
        }
    }
    return 0;
}

/**
 * @brief Выводит матрицу на экран.
 * @param matrix Матрица.
 * @param n Количество строк в матрице.
 * @param m Количество столбцов в матрице.
 */
void display_matrix(int matrix[MAX_SIZE * 2][MAX_SIZE], size_t n, size_t m)
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
 * @brief Заполняет матрицу значениями.
 * @param matrix Матрица.
 * @param n Количество строк в матрице.
 * @param m Количество столбцов в матрице.
 * @return 0 в случае успеха, 1 в случае ошибки.
 */
int fill_matrix(int matrix[MAX_SIZE * 2][MAX_SIZE], size_t n, size_t m)
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
