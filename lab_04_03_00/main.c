#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHARS 256
#define MAX_WORDS MAX_CHARS / 2
#define MAX_CHARS_IN_WORD 16

int input(char string[MAX_CHARS + 1])
{
    char temp_string[MAX_CHARS + 2];

    if (fgets(temp_string, MAX_CHARS + 2, stdin) == NULL)
        return 1;
    temp_string[strcspn(temp_string, "\n")] = '\0';

    if (strlen(temp_string) && strlen(temp_string) > MAX_CHARS)
        return 1;
    strncpy(string, temp_string, MAX_CHARS + 1);
    return 0;
}

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

void process_word(char *string, char *new_word)
{
    char first_char = *string;
    new_word[0] = *string;
    string++;
    size_t i = 1;
    while (*string != '\0')
    {
        if (*string != first_char)
        {
            new_word[i] = *string;
            i++;
        }
        string++;
    }
    new_word[i] = '\0';
}

int create_new_str(char words[MAX_WORDS][MAX_CHARS_IN_WORD + 1], size_t words_n, char *new_str)
{
    char new_word[MAX_CHARS_IN_WORD + 1];
    size_t j = 0;
    for (size_t i = 0; i < words_n; i++)
    {
        if (strcmp(words[words_n - 1], words[words_n - 1 - i]) == 0)
        {
            continue;
        }
        process_word(words[words_n - 1 - i], new_word);
        size_t i = 0;
        while (new_word[i] != '\0')
        {
            new_str[j] = new_word[i];
            j++;
            i++;
        }
        new_str[j] = ' ';
        j++;
    }
    if (j != 0)
    {
        new_str[j - 1] = '\0';
        return 0;
    }
    else
    {
        return 1;
    }
}

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