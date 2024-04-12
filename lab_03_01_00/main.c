#include "matrix.h"
#include "array.h"

/**
 * @brief Функция для ввода размеров матрицы и самой матрицы.
 * @param n Указатель на переменную, в которую будет записан номер строк матрицы.
 * @param m Указатель на переменную, в которую будет записан номер столбцов матрицы.
 * @param matrix Матрица.
 * @return 0 в случае успешного выполнения, 1 в случае ошибки.
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
    int rc = fill_matrix(matrix, *n, *m);
    if (rc != 0)
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

    int result[MAX_SIZE];
    for (size_t i = 0; i < m; i++)
    {
        result[i] = is_descending(matrix, n, i);
    }

    print_array(result, m);
    return 0;
}
