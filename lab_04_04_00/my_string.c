#include "my_string.h"

/**
 * @brief Удаляет пробелы в начале и конце строки.
 * @param str Исходная строка.
 * @param new_str Строка, в которую будет скопирована исходная строка без пробелов в начале и конце.
 */
void strip(char *str, char *new_str)
{
    if (str == NULL || *str == '\0')
    {
        new_str[0] = '\0';
        return;
    }

    while (isspace(*str))
        str++;

    char *output_ptr = new_str;
    while (*str != '\0')
    {
        *output_ptr = *str;
        output_ptr++;
        str++;
    }

    output_ptr--;
    while (new_str < output_ptr && isspace(*output_ptr))
        output_ptr--;

    output_ptr[1] = '\0';
}

/**
 * @brief Проверяет, является ли строка допустимым IP-адресом.
 * @param str Строка для проверки.
 * @return 1, если строка является допустимым IP-адресом, иначе 0.
 */
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

/**
 * @brief Считывает строку из стандартного ввода.
 * @param string Массив символов, в который будет скопирована введенная строка.
 * @return 0, если строка успешно считывается, иначе 1.
 */
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

    strncpy(string, temp_string, MAX_CHARS + 1);
    return 0;
}
