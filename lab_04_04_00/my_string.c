#include "my_string.h"

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

    fgets(temp_string, MAX_CHARS + 2, stdin);
    
    if (strcspn(temp_string, "\n") == MAX_CHARS+1)
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
