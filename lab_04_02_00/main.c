#include "my_string.h"

int main()
{
    char input_s[MAX_CHARS + 1];
    char words[MAX_WORDS][MAX_CHARS_IN_WORD + 1];
    int word_counts[MAX_WORDS] = { 0 };

    // printf("Input string: ");
    if (input(input_s) != 0)
    {
        return 1;
    }

    size_t word_n;
    split(input_s, words, &word_n);

    if (word_n == 0)
    {
        return 1;
    }

    process_words(word_n, words, word_counts);
    printf("Result: ");
    for (int i = 0; i < word_n; i++)
    {
        if (word_counts[i] != 0)
        {
            printf("%s %d\n", words[i], word_counts[i]);
        }
    }
    return 0;
}
