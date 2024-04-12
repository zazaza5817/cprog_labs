#include "array.h"

/**
 * @brief Выводит элементы массива
 * @param array Массив для вывода
 * @param n Размер массива
 */
void print_array(int array[], size_t n)
{
    printf("Output array: ");
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
