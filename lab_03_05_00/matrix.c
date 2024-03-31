#include "matrix.h"

/**
 * @brief Проверяет, является ли число простым.
 * @param num Число, которое нужно проверить на простоту.
 * @return 1, если число простое, иначе возвращает 0.
 */
int is_prime(int num)
{
    if (num <= 1)
    {
        return 0;
    }
    if (num == 2)
    {
        return 1;
    }
    if (num % 2 == 0)
    {
        return 0;
    }
    int sqrt_num = (int)sqrt(num);
    for (int i = 3; i <= sqrt_num; i += 2)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

/**
 * @brief Обрабатывает матрицу, по условию.
 *
 * Эта функция проходит по каждому элементу матрицы, проверяет его на простоту
 * и, если элемент простой, добавляет его в массив. После обработки всех элементов,
 * массив переворачивается, и простые числа заменяются на соответствующие элементы
 * из перевернутого массива.
 *
 * @param matrix Матрица, элементы которой проверяются на простоту.
 * @param n Количество строк в матрице.
 * @param m Количество столбцов в матрице.
 * @return 0, если в матрице найдено хотя бы одно простое число, иначе возвращает 1.
 */
int process_matrix(int matrix[MAX_SIZE][MAX_SIZE], size_t n, size_t m)
{
    bool is_entered = false;
    size_t a_i = 0;
    int array[MAX_SIZE * MAX_SIZE];
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if (is_prime(matrix[i][j]))
            {
                array[a_i] = matrix[i][j];
                a_i++;
                is_entered = true;
            }
        }
    }
    reverse_array(array, a_i - 1);
    a_i = 0;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if (is_prime(matrix[i][j]) == 1)
            {
                matrix[i][j] = array[a_i];
                a_i++;
            }
        }
    }
    return !is_entered;
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