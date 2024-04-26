#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHARS 256
#define MAX_WORDS MAX_CHARS / 2
#define MAX_CHARS_IN_WORD 16

int input(char string[MAX_CHARS + 1]);
int split(char *input_s, char words[MAX_WORDS][MAX_CHARS_IN_WORD + 1], size_t *words_n);
void process_word(char *string, char *new_word);
int create_new_str(char words[MAX_WORDS][MAX_CHARS_IN_WORD + 1], size_t words_n, char *new_str);