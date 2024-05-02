#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_CHARS 256

void strip(char *str, char *new_str);
int is_valid_ip(char *str);
int input(char string[MAX_CHARS + 1]);
