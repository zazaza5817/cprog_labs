#include <stdio.h>

#define ARRAY_SIZE 10

/**
 * @brief Заполняет массив целыми числами, введенными пользователем.
 * @param array Массив для заполнения.
 * @param n Размер массива.
 * @return 0 в случае успеха, 1 в случае ошибки ввода.
 */
int fillArray(int array[], int n)
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
int sumEvenElements(int array[], int n)
{
    int sum = 0; // Инициализируем сумму
    // Проходим по массиву
    for (int i = 0; i < n; i++)
    {
        // Проверяем, является ли элемент четным
        if (array[i] % 2 == 0)
        {
            sum += array[i]; // Добавляем к сумме
        }
    }
    return sum;
}

int main(void)
{
    int n;         // Размер массива
    int array[ARRAY_SIZE]; // Массив для хранения чисел

    printf("Enter n - dimension of array: ");
    // Проверяем успешность ввода размера массива
    if (scanf("%d", &n) != 1)
    {
        return 1;
    }

    // Проверяем корректность введенного размера
    if (n > ARRAY_SIZE || n <= 0)
    {
        return 1;
    }
    // Заполняем массив
    if (fillArray(array, n) != 0)
    {
        return 1;
    }

    // Считаем сумму четных элементов
    int sum = sumEvenElements(array, n);
    printf("The sum even elements of array is %d", sum);
    return 0;
}
