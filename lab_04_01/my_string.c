#include "my_string.h"

char *my_strpbrk(char *str, char *char_set)
{
    while (*str != 0)
    {
        char *current_char = char_set;
        while (*current_char != '\0')
        {
            if (*current_char == *str)
            {
                return str;
            }
            current_char++;
        }
        str++;
    }
    return NULL;
}

size_t my_strspn(char *str1, char *char_set)
{
    size_t count = 0;
    while (*str1 != '\0')
    {
        const char *p = char_set;
        while (*p != '\0')
        {
            if (*str1 == *p)
            {
                count++;
                break;
            }
            p++;
        }
        if (*p == '\0')
        {
            break;
        }
        str1++;
    }
    return count;
}

size_t my_strcspn(char *string1, char *string2)
{
    char *p1;
    char *p2;

    for (p1 = string1; *p1 != '\0'; p1++)
    {
        for (p2 = string2; *p2 != '\0'; p2++)
        {
            if (*p1 == *p2)
            {
                return p1 - string1;
            }
        }
    }
    return p1 - string1;
}

char *my_strchr(char *str, int c)
{
    char *position = str;
    while (*position != '\0')
    {
        if (*position == c)
        {
            return position;
        }
        position++;
    }
    if (c == '\0')
    {
        return position;
    }
    return NULL;
}

char *my_strrchr(char *str, int c)
{
    char *last_occurrence = NULL;
    while (*str)
    {
        if (*str == c)
        {
            last_occurrence = str;
        }
        str++;
    }

    if (c == '\0' && *str == '\0')
    {
        last_occurrence = str;
    }
    return (char *)last_occurrence;
}
