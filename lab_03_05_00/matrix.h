#include "array.h"
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAX_SIZE 10

int is_prime(int num);
int process_matrix(int matrix[MAX_SIZE][MAX_SIZE], size_t n, size_t m);
void display_matrix(int matrix[MAX_SIZE][MAX_SIZE], size_t n, size_t m);
int fill_matrix(int matrix[MAX_SIZE][MAX_SIZE], size_t n, size_t m);