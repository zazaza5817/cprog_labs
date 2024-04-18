#include <stdio.h>
#include <string.h>

#define MAX_CHARS 256
#define MAX_WORDS MAX_CHARS / 2 


char* my_strtok(char* str, char* delimiters) {
    static char* next_token = NULL;
    if (str == NULL) {
        str = next_token;
    }

    if (str == NULL) {
        return NULL;
    }

    str += strspn(str, delimiters);

    if (*str == '\0') {
        next_token = NULL;
        return NULL;
    }

    char* end = str + strcspn(str, delimiters);

    if (*end == '\0') {
        next_token = NULL;
    } else {
        *end = '\0';
        next_token = end + 1;
    }

    return str;
}

int main() {
    char input[MAX_CHARS + 1];
    char *words[MAX_WORDS];
    int wordCounts[MAX_WORDS] = {0};

    printf("Input string: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = 0;

    size_t wordIndex = 0;
    char *token = my_strtok(input, " ");
    while (token != NULL) {
        words[wordIndex] = token;
        wordIndex++;
        token = my_strtok(NULL, " ");
    }
    size_t wordCount = wordIndex;

    for (size_t i = 0; i < wordCount; i ++)
    {

        size_t result = 0;
        for (size_t j = 0; j < wordCount; j ++)
        {
            if (strcmp(words[i], words[j]) == 0)
            {
                result ++;
            }
        }
        wordCounts[i] = result;
    }
    printf("\nResult: ");
    for (int i = 0; i < wordIndex; i++) {
        printf("%s %d\n", words[i], wordCounts[i]);
    }

    return 0;
}
