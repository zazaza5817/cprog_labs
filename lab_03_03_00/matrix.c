#include "matrix.h"

/**
 * @brief Вычисляет сумму элементов в строке матрицы.
 * @param row Массив, содержащий элементы строки матрицы.
 * @param size Размер строки матрицы.
 * @return Сумма элементов в строке матрицы.
 */
int sum_row(int row[], size_t size)
{
    int sum = 0;
    for (size_t i = 0; i < size; i++)
    {
        sum += row[i];
    }
    return sum;
}

/**
 * @brief Меняет местами две строки матрицы.
 * @param matrix Матрица, в которой происходит обмен строк.
 * @param m Количество столбцов в матрице.
 * @param index_1 Индекс первой строки для обмена.
 * @param index_2 Индекс второй строки для обмена.
 */
void swap_rows(int matrix[MAX_SIZE][MAX_SIZE], size_t m, size_t index_1, size_t index_2)
{
    for (size_t i = 0; i < m; i++)
    {
        int temp = matrix[index_1][i];
        matrix[index_1][i] = matrix[index_2][i];
        matrix[index_2][i] = temp;
    }
}

/**
 * @brief Выводит матрицу на экран.
 * @param matrix Матрица для вывода.
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
 * @brief Заполняет матрицу значениями, введенными пользователем.
 * @param matrix Матрица для заполнения.
 * @param n Количество строк в матрице.
 * @param m Количество столбцов в матрице.
 * @return 0 в случае успешного заполнения, 1 в случае ошибки ввода.
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

/**
 * @brief Сортирует матрицу по сумме элементов в строках с помощью пузырьковой сортировки.
 * @param matrix Матрица для сортировки.
 * @param n Количество строк в матрице.
 * @param m Количество столбцов в матрице.
 */
void bubble_sort_matrix(int matrix[10][10], size_t n, size_t m)
{
    for (size_t i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (size_t j = 0; j < n - i - 1; j++)
        {
            if (sum_row(matrix[j], m) > sum_row(matrix[j + 1], m))
            {
                swapped = true;
                swap_rows(matrix, m, j, j + 1);
            }
        }
        if (!swapped)
        {
            return;
        }
    }
}