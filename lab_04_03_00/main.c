#include "my_string.h"

int main(void)
{
    char input_s[MAX_CHARS + 1];
    char new_str[MAX_CHARS + 1];
    if (input(input_s) != 0)
    {
        return 1;
    }
    size_t words_n;
    char words[MAX_WORDS][MAX_CHARS_IN_WORD + 1];

    split(input_s, words, &words_n);
    if (words_n <= 1)
    {
        return 1;
    }
    if (create_new_str(words, words_n, new_str) != 0)
    {
        return 1;
    }
    printf("Result: %s\n", new_str);
    return 0;
}