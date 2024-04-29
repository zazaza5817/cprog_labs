#include "my_string.h"

int split(char *input_s, char words[MAX_WORDS][MAX_CHARS_IN_WORD + 1], size_t *words_n)
{
    *words_n = 0;
    char *beg_ptr = input_s;
    char *end_ptr = beg_ptr;

    while (*end_ptr != '\0')
    {
        while ((isspace(*beg_ptr) || ispunct(*beg_ptr)) && *beg_ptr != '\0')
            beg_ptr++;
        end_ptr = beg_ptr;
        while (!(isspace(*end_ptr) || ispunct(*end_ptr)) && *end_ptr != '\0')
            end_ptr++;

        if (beg_ptr == end_ptr)
        {
            return 1;
        }
        size_t word_len = end_ptr - beg_ptr;
        if (word_len > MAX_CHARS_IN_WORD)
            return 1;

        size_t i = 0;
        while (beg_ptr != end_ptr)
        {
            words[*words_n][i] = *beg_ptr;
            beg_ptr++;
            i++;
        }
        words[*words_n][i] = '\0';
        *words_n += 1;
    }
    return 0;
}

int input(char string[MAX_CHARS + 1])
{
    char temp_string[MAX_CHARS + 2];

    if (fgets(temp_string, MAX_CHARS + 2, stdin) == NULL)
    {
        return 1;
    }

    if (strcspn(temp_string, "\n") == MAX_CHARS + 1)
    {
        return 1;
    }

    temp_string[strcspn(temp_string, "\n")] = '\0';

    if (strlen(temp_string) == 0)
    {
        return 1;
    }

    strncpy(string, temp_string, MAX_CHARS + 1);
    return 0;
}

void process_words(size_t word_n, char words[MAX_WORDS][MAX_CHARS_IN_WORD + 1], int word_counts[MAX_WORDS])
{
    for (size_t i = 0; i < word_n; i++)
    {
        bool flag = false;
        size_t result = 0;
        for (size_t j = 0; j < i; j++)
        {
            if (strcmp(words[i], words[j]) == 0)
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            continue;
        }
        for (size_t j = 0; j < word_n; j++)
        {
            if (strcmp(words[i], words[j]) == 0)
            {
                result++;
            }
        }
        word_counts[i] = result;
    }
}