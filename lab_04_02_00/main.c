#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CHARS 256
#define MAX_WORDS MAX_CHARS / 2

char *my_strtok(char *str, char *delimiters)
{
    static char *next_token = NULL;
    if (str == NULL)
    {
        str = next_token;
    }

    if (str == NULL)
    {
        return NULL;
    }

    str += strspn(str, delimiters);

    if (*str == '\0')
    {
        next_token = NULL;
        return NULL;
    }

    char *end = str + strcspn(str, delimiters);

    if (*end == '\0')
    {
        next_token = NULL;
    }
    else
    {
        *end = '\0';
        next_token = end + 1;
    }

    return str;
}

int main()
{
    char input[MAX_CHARS + 1];
    char *words[MAX_WORDS];
    int word_counts[MAX_WORDS] = {0};

    printf("Input string: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = 0;

    size_t word_index = 0;
    char *token = my_strtok(input, " ");
    while (token != NULL)
    {
        words[word_index] = token;
        word_index++;
        token = my_strtok(NULL, " ");
    }
    size_t word_count = word_index;

    size_t repeats_count = 0;
    size_t repeats[MAX_WORDS];

    for (size_t i = 0; i < word_count; i++)
    {
        bool flag = false;
        size_t result = 0;
        for (size_t j = 0; j < repeats_count; j++)
        {
            if (i == repeats[j])
            {
                flag = true;
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
                if (i != j)
                {
                    repeats[repeats_count++] = j;
                }
            }
        }
        word_counts[i] = result;
    }
    printf("\nResult: ");
    for (int i = 0; i < word_index; i++)
    {
        if (word_counts[i] != 0)
        {
            printf("%s %d\n", words[i], word_counts[i]);
        }
    }

    return 0;
}
