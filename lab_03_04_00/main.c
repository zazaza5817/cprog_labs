#include "matrix.h"

/**
 * @brief Функция для ввода матрицы с проверкой корректности ввода.
 * @param matrix Матрица.
 * @param n Указатель на переменную, в которую будет записано количество строк матрицы.
 * @param m Указатель на переменную, в которую будет записано количество столбцов матрицы.
 * @return 0 в случае успешного ввода, 1 в случае ошибки ввода.
 */
int input(int matrix[MAX_SIZE][MAX_SIZE], size_t *n, size_t *m)
{
    printf("Enter the number of matrix rows: ");
    if (scanf("%zu", n) != 1 || *n == 0 || *n > MAX_SIZE)
    {
        printf("The number of matrix rows is set incorrectly!");
        return 1;
    }

    printf("Enter the number of matrix columns: ");
    if (scanf("%zu", m) != 1 || *m == 0 || *m > MAX_SIZE || *m != *n)
    {
        printf("The number of matrix columns is set incorrectly!");
        return 1;
    }

    printf("Enter matrix elements: ");

    if (fill_matrix(matrix, *n) != 0)
    {
        printf("Incorrect matrix element specified!");
        return 1;
    }
    return 0;
}

int main(void)
{
    size_t n, m;
    int matrix[MAX_SIZE][MAX_SIZE];

    if (input(matrix, &n, &m) != 0)
    {
        return 1;
    }

    int value;
    if (find_value(matrix, n, &value) != 0)
    {
        return 1;
    }

    printf("value: %d\n", value);
    return 0;
}
