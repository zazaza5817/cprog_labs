#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_CHARS 256
#define MAX_WORDS MAX_CHARS / 2
#define MAX_CHARS_IN_WORD 16

int split(char *input_s, char words[MAX_WORDS][MAX_CHARS_IN_WORD + 1], size_t *words_n);
int input(char string[MAX_CHARS + 1]);
void process_words(size_t word_n, char words[MAX_WORDS][MAX_CHARS_IN_WORD + 1], int word_counts[MAX_WORDS]);
