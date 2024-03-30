#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAX_SIZE 10

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
    int sqrt_num = sqrt(num);
    for (int i = 3; i <= sqrt_num; i += 2)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

void reverse_array(int arr[], int end)
{
    int temp;
    int start = 0;
    while (start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

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
    if (scanf("%zu", &m) != 1 || m == 0 || m > MAX_SIZE)
    {
        printf("The number of matrix columns is set incorrectly!");
        return 1;
    }

    printf("Enter matrix elements: ");

    if (fill_matrix(matrix, n, m) != 0)
    {
        printf("Incorrect matrix element specified!");
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
