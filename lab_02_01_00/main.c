#include <stdio.h>

#define ARRAY_SIZE 10

/**
 * @brief Заполняет массив целыми числами, введенными пользователем.
 * @param array Массив для заполнения.
 * @param n Размер массива.
 * @return 0 в случае успеха, 1 в случае ошибки ввода.
 */
int fill_array(int array[], int n)
{
    // Заполняем массив
    for (int i = 0; i < n; i++)
    {
        printf("enter next item: ");
        // Проверяем успешность ввода
        if (scanf("%d", &array[i]) != 1)
        {
            return 1;
        }
    }
    return 0;
}

/**
 * @brief Считает сумму четных элементов массива.
 * @param array Массив для обработки.
 * @param n Размер массива.
 * @return Сумма четных элементов массива.
 */
int sum_even_elements(int array[], int n, int *even_count)
{
    int sum = 0; // Инициализируем сумму
    // Проходим по массиву
    for (int i = 0; i < n; i++)
    {
        // Проверяем, является ли элемент четным
        if (array[i] % 2 == 0)
        {
            sum += array[i]; // Добавляем к сумме
            *even_count += 1;
        }
    }
    return sum;
}

int main(void)
{
    int n;                 // Размер массива
    int array[ARRAY_SIZE]; // Массив для хранения чисел

    printf("Enter n - dimension of array: ");
    // Проверяем успешность ввода размера массива
    if (scanf("%d", &n) != 1)
    {
        fprintf(stderr, "n must be integer");
        return 1;
    }

    // Проверяем корректность введенного размера
    if (n > ARRAY_SIZE || n <= 0)
    {
        fprintf(stderr, "n must be greater than zero and lower then or equal to ten");
        return 1;
    }
    // Заполняем массив
    if (fill_array(array, n) != 0)
    {
        fprintf(stderr, "Elements of array must be integers");
        return 1;
    }
    // Кол-во четных элементов
    int even_count = 0;

    // Считаем сумму четных элементов
    int sum = sum_even_elements(array, n, &even_count);
    if (even_count == 0)
    {
        fprintf(stderr, "There is no even numbers in array");
        return 1;
    }
    printf("The sum even elements of array is %d", sum);
    return 0;
}
