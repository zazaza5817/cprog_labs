#include "matrix.h"

/**
 * @brief Функция для ввода размеров матрицы и ее элементов.
 * @param n Указатель на переменную, в которую будет записан номер строк матрицы.
 * @param m Указатель на переменную, в которую будет записан номер столбцов матрицы.
 * @param matrix Матрица.
 * @return 0 в случае успешного ввода, 1 в случае ошибки.
 */
int input(size_t *n, size_t *m, int matrix[MAX_SIZE][MAX_SIZE])
{
    printf("Enter the number of matrix rows: ");
    if (scanf("%zu", n) != 1 || *n == 0 || *n > MAX_SIZE)
    {
        printf("The number of matrix rows is set incorrectly!");
        return 1;
    }

    printf("Enter the number of matrix columns: ");
    if (scanf("%zu", m) != 1 || *m == 0 || *m > MAX_SIZE)
    {
        printf("The number of matrix columns is set incorrectly!");
        return 1;
    }

    printf("Enter matrix elements: ");

    if (fill_matrix(matrix, *n, *m) != 0)
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

    if (input(&n, &m, matrix) != 0)
    {
        return 1;
    }

    if (process_matrix(matrix, n, m) != 0)
    {
        // нет простых элементов
        return 1;
    }

    printf("processed matrix:\n");
    display_matrix(matrix, n, m);
    return 0;
}
