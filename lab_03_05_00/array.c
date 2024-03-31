#include "array.h"

/**
 * @brief Разворачивает массив целых чисел.
 * @param arr Массив целых чисел, который нужно развернуть.
 * @param end Индекс последнего элемента массива.
 */
void reverse_array(int arr[], int end)
{
    int temp;
    int start = 0;
    while (start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
