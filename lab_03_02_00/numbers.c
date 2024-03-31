#include <stdlib.h>
#define MAX_DIGIT 9


/**
 * @brief Возвращает первую цифру числа.
 * @param n Число.
 * @return Первая цифра числа.
 */
int first_digit(int n)
{
    n = abs(n);
    while (n >= 10)
    {
        n /= 10;
    }
    return n;
}

/**
 * @brief Возвращает последнюю цифру числа.
 * @param n Число.
 * @return Последняя цифра числа.
 */
int last_digit(int n)
{
    n = abs(n);
    return n % 10;
}
