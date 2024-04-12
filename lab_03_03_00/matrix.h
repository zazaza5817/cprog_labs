#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 10

int sum_row(int row[], size_t size);
void swap_rows(int row_1[MAX_SIZE], int row_2[MAX_SIZE], size_t m);
void display_matrix(int matrix[MAX_SIZE][MAX_SIZE], size_t n, size_t m);
int fill_matrix(int matrix[MAX_SIZE ][MAX_SIZE], size_t n, size_t m);
void bubble_sort_matrix(int matrix[MAX_SIZE][MAX_SIZE], size_t n, size_t m);
