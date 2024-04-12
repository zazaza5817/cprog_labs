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
 * @param m Количество столбцов в матрице.
 * @param row_1 Первую строчку для обмена.
 * @param row_2 Вторую строчку для обмена.
 */
void swap_rows(int row_1[MAX_SIZE], int row_2[MAX_SIZE], size_t m)
{
    for (size_t i = 0; i < m; i++)
    {
        int temp = row_1[i];
        row_1[i] = row_2[i];
        row_2[i] = temp;
    }
}

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
 * @brief Заполняет матрицу значениями, введенными пользователем.
 * @param matrix Матрица для заполнения.
 * @param n Количество строк в матрице.
 * @param m Количество столбцов в матрице.
 * @return 0 в случае успешного заполнения, 1 в случае ошибки ввода.
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

/**
 * @brief Сортирует матрицу по сумме элементов в строках с помощью пузырьковой сортировки.
 * @param matrix Матрица для сортировки.
 * @param n Количество строк в матрице.
 * @param m Количество столбцов в матрице.
 */
void bubble_sort_matrix(int matrix[MAX_SIZE][MAX_SIZE], size_t n, size_t m)
{
    for (size_t i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (size_t j = 0; j < n - i - 1; j++)
        {
            if (sum_row(matrix[j], m) > sum_row(matrix[j + 1], m))
            {
                swapped = true;
                swap_rows(matrix[j], matrix[j + 1], m);
            }
        }
        if (!swapped)
        {
            return;
        }
    }
}
