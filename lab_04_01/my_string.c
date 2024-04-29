#include "my_string.h"

/**
 * @brief Находит первое вхождение символа из char_set в строке str.
 * @param str Строка, в которой производится поиск.
 * @param char_set Набор символов, среди которых ищется.
 * @return Указатель на первое вхождение символа из char_set в строке str, или NULL, если такого символа нет.
 */
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

/**
 * @brief Считает количество символов в начале строки str1, которые присутствуют в char_set.
 * @param str1 Строка, в которой производится подсчет.
 * @param char_set Набор символов, среди которых ищется.
 * @return Количество символов в начале строки str1, которые присутствуют в char_set.
 */
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

/**
 * @brief Считает количество символов в начале строки string1, которые не присутствуют в string2.
 * @param string1 Строка, в которой производится подсчет.
 * @param string2 Строка, содержащая символы, которые исключаются из подсчета.
 * @return Количество символов в начале строки string1, которые не присутствуют в string2.
 */
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

/**
 * @brief Находит первое вхождение символа c в строке str.
 * @param str Строка, в которой производится поиск.
 * @param c Символ, который ищется.
 * @return Указатель на первое вхождение символа c в строке str, или NULL, если такого символа нет.
 */
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

/**
 * @brief Находит последнее вхождение символа c в строке str.
 * @param str Строка, в которой производится поиск.
 * @param c Символ, последнее вхождение которого ищется.
 * @return Указатель на последнее вхождение символа c в строке str, или NULL, если такого символа нет.
 */
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
