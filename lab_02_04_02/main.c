#include <stdio.h>

#define MAX_ARRAY_SIZE 10
#define OWERFLOW_EXIT_CODE 100

/**
 * @brief Заполняет массив числами, введенными пользователем.
 * @param array Массив для заполнения.
 * @param n Указатель на переменную, в которой будет храниться количество элементов в массиве.
 * @return 0 в случае успешного заполнения, иначе 1.
 */
int fill_array(int array[], size_t *n)
{
    // Заполняем массив числами, введенными пользователем
    int scanned_value;
    for (size_t i = 0; i < MAX_ARRAY_SIZE + 1; i++)
    {
        printf("enter next item: ");
        // Проверяем успешность ввода
        if (scanf("%d", &scanned_value) != 1)
        {
            return 0;
        }
        // Проверка на "переполнение" массива
        if (i == MAX_ARRAY_SIZE) 
        {
            return OWERFLOW_EXIT_CODE;
        }
        array[i] = scanned_value;
        *n += 1;
    }
    return 0;
}

/**
 * @brief Выводит элементы массива.
 * @param array Массив для вывода.
 * @param n Количество элементов в массиве.
 */
void print_array(int array[], size_t n)
{
    printf("Output array: ");
    // Выводим элементы массива
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

/**
 * @brief Сортирует массив методом selection sort.
 * @param arr Массив для сортировки.
 * @param n Количество элементов в массиве.
 */
void selection_sort(int arr[], size_t n)
{
    size_t i, j;
    size_t min_index;
    int temp;
    for (i = 0; i < n - 1; i++)
    {
        min_index = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}

int main(void)
{
    size_t n = 0;
    int array[MAX_ARRAY_SIZE];

    // Заполняем массив
    int exit_code = fill_array(array, &n);

    // Проверяем, что количество элементов больше нуля
    if (n == 0)
    {
        fprintf(stderr, "number of elements must be greater than zero");
        return 1;
    }
    // Сортируем массив
    selection_sort(array, n);

    // Выводим отсортированный массив
    print_array(array, n);

    // Проверяем, на особый код завершения
    return exit_code;
}
