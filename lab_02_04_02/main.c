#include <stdio.h>

#define MAX_ARRAY_SIZE 10
#define OWERFLOW_EXIT_CODE 0

/**
 * @brief Заполняет массив числами, введенными пользователем.
 * @param array Массив для заполнения.
 * @param n Указатель на переменную, в которой будет храниться количество элементов в массиве.
 * @return 0 в случае успешного заполнения, иначе 1.
 */
int fill_array(int array[], int *n)
{
    // Заполняем массив числами, введенными пользователем
    for (int i = 0; i < MAX_ARRAY_SIZE; i++)
    {
        printf("enter next item: ");
        // Проверяем успешность ввода
        if (scanf("%d", &array[i]) != 1)
        {
            return 0;
        }
        *n += 1;
    }
    return 0;
}

/**
 * @brief Выводит элементы массива.
 * @param array Массив для вывода.
 * @param n Количество элементов в массиве.
 */
void print_array(int array[], int n)
{
    printf("Output array: ");
    // Выводим элементы массива
    for (int i = 0; i < n; i++)
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
void selection_sort(int arr[], int n)
{
    int i, j;
    int min_index;
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
    int n = 0;
    int array[MAX_ARRAY_SIZE];

    // Заполняем массив
    fill_array(array, &n);

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
    if (n == MAX_ARRAY_SIZE)
    {
        return OWERFLOW_EXIT_CODE;
    }
    return 0;
}
