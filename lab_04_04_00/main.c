#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHARS 256

void strip(char *str, char *new_str)
{
    int i = 0, k = 0;

    while (str[i] != '\0')
    {
        if (str[i] != ' ' && str[i] != '\t')
        {
            new_str[k] = str[i];
            k++;
        }
        i++;
    }
    new_str[k] = '\0';
}

int is_valid_ip(char *str)
{
    int segs = 0;
    int chcnt = 0;
    int accum = 0;

    if (str == NULL)
        return 0;

    while (*str != '\0')
    {
        if (*str == '.')
        {
            if (chcnt == 0 || chcnt > 3)
                return 0;
            if (++segs == 4)
                return 0;
            chcnt = accum = 0;
            str++;
            continue;
        }
        if ((*str < '0') || (*str > '9'))
            return 0;
        if ((accum = accum * 10 + *str - '0') > 255)
            return 0;
        chcnt++;
        str++;
    }

    if (segs != 3)
        return 0;
    if (chcnt == 0 || chcnt > 3)
        return 0;

    return 1;
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

    // printf("Input string: ");
    if (input(input_s) != 0)
    {
        return 1;
    }

    char input_ip[MAX_CHARS + 1];
    strip(input_s, input_ip);

    if (is_valid_ip(input_ip))
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }

    return 0;
}
