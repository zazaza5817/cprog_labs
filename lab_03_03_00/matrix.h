#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 10

int sum_row(int row[], size_t size);
void swap_rows(int matrix[MAX_SIZE][MAX_SIZE], size_t m, size_t index_1, size_t index_2);
void display_matrix(int matrix[MAX_SIZE * 2][MAX_SIZE], size_t n, size_t m);
int fill_matrix(int matrix[MAX_SIZE * 2][MAX_SIZE], size_t n, size_t m);
void bubble_sort_matrix(int matrix[10][10], size_t n, size_t m);