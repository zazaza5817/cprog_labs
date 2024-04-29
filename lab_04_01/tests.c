#include "tests.h"

int test_my_strpbrk(void)
{
    int result_diff = 0;

    char *str_1[] = { "bebbrr", "cat", "second", "" };
    char *str_2[] = { "black", "dog", "", "" };
    size_t tests_count = 4;
    for (size_t i = 0; i < tests_count; i++)
    {
        if (strpbrk(str_1[i], str_2[i]) != my_strpbrk(str_1[i], str_2[i]))
        {
            result_diff++;
        }
    }
    return result_diff;
}

int test_my_strspn(void)
{
    int result_diff = 0;

    char *str_1[] = { "bebbrr", "cat", "second", "" };
    char *str_2[] = { "black", "dog", "", "" };
    size_t tests_count = 4;
    for (size_t i = 0; i < tests_count; i++)
    {
        if (strspn(str_1[i], str_2[i]) != my_strspn(str_1[i], str_2[i]))
        {
            result_diff++;
        }
    }
    return result_diff;
}

int test_my_strcspn(void)
{
    int result_diff = 0;

    char *str_1[] = { "test", "cat", "second", "" };
    char *str_2[] = { "s", "dog", "", "" };
    size_t tests_count = 4;
    for (size_t i = 0; i < tests_count; i++)
    {
        if (strcspn(str_1[i], str_2[i]) != my_strcspn(str_1[i], str_2[i]))
        {
            result_diff++;
        }
    }
    return result_diff;
}

int test_my_strchr(void)
{
    int result_diff = 0;

    char *str_1[] = { "bebbrr", "", "a", "ab", "abc", "abc" };
    char str_2[] = { 'r', 'a', 'a', 'b', 'g', '\0' };
    size_t tests_count = 4;
    for (size_t i = 0; i < tests_count; i++)
    {
        if (strchr(str_1[i], str_2[i]) != my_strchr(str_1[i], str_2[i]))
        {
            result_diff++;
        }
    }
    return result_diff;
}

int test_my_strrchr(void)
{
    int result_diff = 0;

    char *str_1[] = { "bebbrr", "cat", "second", "" };
    char str_2[] = { 'r', 'a', '!', '\0' };
    size_t tests_count = 4;
    for (size_t i = 0; i < tests_count; i++)
    {
        if (strrchr(str_1[i], str_2[i]) != my_strrchr(str_1[i], str_2[i]))
        {
            result_diff++;
        }
    }
    return result_diff;
}
