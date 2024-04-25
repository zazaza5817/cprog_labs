#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CHARS 256
#define MAX_WORDS MAX_CHARS / 2
#define MAX_CHARS_IN_WORD 16

int split(char *input_s, char words[MAX_WORDS][MAX_CHARS_IN_WORD + 1], size_t *words_n){
    *words_n = 0;
    char *beg_ptr = input_s;
    char *end_ptr = beg_ptr;

    while (*end_ptr != '\0')
    {
        while(*beg_ptr == ' ' && *beg_ptr != '\0')
            beg_ptr ++;
        end_ptr = beg_ptr;
        while(*end_ptr != ' ' && *end_ptr != '\0')
            end_ptr ++;
        
        if(beg_ptr == end_ptr)
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
            beg_ptr ++;
            i ++;
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
        return 1;

    temp_string[strcspn(temp_string, "\n")] = '\0';

    if (strlen(temp_string) && strlen(temp_string) > MAX_CHARS)
        return 1;

    strncpy(string, temp_string, MAX_CHARS + 1);

    return 0;
}

int main()
{
    char input_s[MAX_CHARS + 1];
    char words[MAX_WORDS][MAX_CHARS_IN_WORD+1];
    int word_counts[MAX_WORDS] = { 0 };

    printf("Input string: ");
    if (input(input_s) != 0)
    {
        return 1;
    }
    
    size_t word_count;
    split(input_s, words, &word_count);

    if (word_count == 0)
    {
        return 1;
    }


    for (size_t i = 0; i < word_count; i++)
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
        for (size_t j = 0; j < word_count; j++)
        {
            if (strcmp(words[i], words[j]) == 0)
            {
                result++;
            }
        }
        word_counts[i] = result;
    }

    printf("Result: ");
    for (int i = 0; i < word_count; i++)
    {
        if (word_counts[i] != 0)
        {
            printf("%s %d\n", words[i], word_counts[i]);
        }
    }
    return 0;
}
