#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAX_SIZE 10
#define MAX_DIGIT 9

int first_digit(int n)
{
    int digits = (int)log10(n);
    return (int)(n / pow(10, digits));
}

int last_digit(int n)
{
    return n % 10;
}

void insert_row(int matrix[MAX_SIZE * 2][MAX_SIZE], size_t *n, size_t *m, size_t index)
{
    for (size_t i = *n; i >= index; i--)
    {
        for (size_t j = 0; j < *m; j++)
        {
            matrix[i][j] = matrix[i - 1][j];
        }
    }
    for (size_t i = 0; i < MAX_SIZE; i++)
    {
        matrix[index][i] = 100;
    }
    *n += 1;
}

int process_matrix(int matrix[MAX_SIZE * 2][MAX_SIZE], size_t *n, size_t *m, int digit)
{
    int insertions = 0;
    int first_counter;
    int last_counter;
    for (size_t i = 0; i < *n; i++)
    {
        first_counter = 0;
        last_counter = 0;
        for (size_t j = 0; j < *m; j++)
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
            printf("INSERTING %d\n", i);
            insert_row(matrix, n, m, i + 1);
            i++;
            insertions++;
        }
    }
    if (insertions == 0)
    {
        return 1;
    }
    return 0;
}

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

int main(void)
{
    size_t n, m;
    int matrix[MAX_SIZE * 2][MAX_SIZE];

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

    int digit;
    printf("Enter digit: ");
    if (scanf("%d", &digit) != 1 || digit < 0 || digit > MAX_DIGIT)
    {
        printf("Only digits must be inputted!");
        return 1;
    }
    if (process_matrix(matrix, &n, &m, digit) != 0)
    {
        return 1;
    }
    printf("processed matrix:\n");
    display_matrix(matrix, n, m);

    return 0;
}