#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_SIZE 10

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

int main()
{
    size_t n, m;
    int matrix[MAX_SIZE][MAX_SIZE];

    printf("Enter the number of matrix rows: ");
    if (scanf("%zu", &n) != 1 || n == 0 || n > MAX_SIZE)
    {
        printf("The number of matrix rows is set incorrectly!");
        return 1;
    }

    printf("Enter the number of matrix columns: ");
    if (scanf("%zu", &m) != 1 || m == 0 || m > MAX_SIZE || m != n)
    {
        printf("The number of matrix columns is set incorrectly!");
        return 1;
    }

    printf("Enter matrix elements: ");

    if (fill_matrix(matrix, n) != 0)
    {
        printf("Incorrect matrix element specified!");
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
