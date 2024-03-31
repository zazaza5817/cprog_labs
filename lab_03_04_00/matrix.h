#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_SIZE 10

int fill_matrix(int matrix[MAX_SIZE][MAX_SIZE], size_t n);
int find_value(int matrix[MAX_SIZE][MAX_SIZE], size_t n, int *value);