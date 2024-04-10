#include "matrix.h"

/**
 * @brief Функция для ввода данных матрицы и числа.
 * @param n Указатель на переменную, в которую будет записан номер строк матрицы.
 * @param m Указатель на переменную, в которую будет записан номер столбцов матрицы.
 * @param matrix Матрица.
 * @param digit Указатель на переменную, в которую будет записана цифра для поиска.
 * @return int Возвращает 0 при успешном вводе, и 1 в случае ошибки.
 */
int input(size_t *n, size_t *m, int matrix[MAX_SIZE][MAX_SIZE], int *digit)
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

    printf("Enter digit: ");
    if (scanf("%d", digit) != 1 || *digit < 0 || *digit > MAX_DIGIT)
    {
        printf("Only digits must be inputted!");
        return 1;
    }
    return 0;
}

int main(void)
{
    size_t n, m;
    int matrix[MAX_SIZE * 2][MAX_SIZE];
    int digit;

    if (input(&n, &m, matrix, &digit) != 0)
    {
        return 1;
    }
    if (process_matrix(matrix, &n, m, digit) != 0)
    {
        return 1;
    }
    printf("processed matrix:\n");
    display_matrix(matrix, n, m);

    return 0;
}
