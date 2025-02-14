#include "my_string.h"

/**
 * @brief Считывает строку из стандартного ввода, удаляя символ новой строки в конце.
 * 
 * @param string Массив символов, в который будет скопирована введенная строка.
 * @return int Возвращает 0, если строка успешно считывается, иначе 1.
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

    if (strlen(temp_string) == 0)
    {
        return 1;
    }

    strncpy(string, temp_string, MAX_CHARS + 1);
    return 0;
}

/**
 * @brief Разделяет входную строку на слова, сохраняя их в массив.
 * 
 * @param input_s Входная строка для разделения на слова.
 * @param words Массив для хранения разделенных слов.
 * @param words_n Указатель на переменную, в которую будет записано количество слов.
 * @return int Возвращает 0 при успешном разделении, иначе 1.
 */
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

/**
 * @brief Обрабатывает слово, удаляя все символы, отличные от первого.
 * 
 * @param string Исходное слово.
 * @param new_word Массив символов, в который будет скопирована обработанная строка.
 */
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

/**
 * @brief Создает новую строку из массива слов, обрабатывая каждое слово.
 * 
 * @param words Массив слов для обработки.
 * @param words_n Количество слов в массиве.
 * @param new_str Массив символов, в который будет записана новая строка.
 * @return int Возвращает 0 при успешном создании новой строки, иначе 1.
 */
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