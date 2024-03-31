#include <stdio.h>
#include "numbers.h"

#define MAX_SIZE 10

void insert_row(int matrix[MAX_SIZE * 2][MAX_SIZE], size_t *n, size_t *m, size_t index);
int process_matrix(int matrix[MAX_SIZE * 2][MAX_SIZE], size_t *n, size_t *m, int digit);
void display_matrix(int matrix[MAX_SIZE * 2][MAX_SIZE], size_t n, size_t m);
int fill_matrix(int matrix[MAX_SIZE * 2][MAX_SIZE], size_t n, size_t m);
int first_digit(int n);
int last_digit(int n);