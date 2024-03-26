#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

int sum_row(int row[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += row[i];
    }
    return sum;
}

void swap_rows(int matrix[MAX_SIZE][MAX_SIZE], size_t m, size_t index_1, size_t index_2)
{
    for (size_t i = 0; i < m; i++)
    {
        int temp = matrix[index_1][i];
        matrix[index_1][i] = matrix[index_2][i];
        matrix[index_2][i] = temp;
    }
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

void bubble_sort_matrix(int matrix[10][10], int n, int m) {
    for (int i = 0; i < n - 1; i ++){
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j ++){
            if (sum_row(matrix[j], m) > sum_row(matrix[j + 1], m)){
                swapped = true;
                swap_rows(matrix, m, j, j + 1);
            }
        }
        if (! swapped) 
        {
            return;
        }
    }
}


int main() {
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

    bubble_sort_matrix(matrix, n, m);
    printf("processed matrix:\n");
    display_matrix(matrix, n, m);
    return 0;
}
