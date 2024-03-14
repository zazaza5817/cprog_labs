#include <stdio.h>

#define ARRAY_SIZE 10

/**
 * @brief Заполняет массив значениями, введенными пользователем.
 * @param parray Указатель на массив, который нужно заполнить.
 * @param n Размер массива.
 * @return 0 в случае успешного заполнения, 1 в случае ошибки ввода.
 */
int fill_array(int *parray, int n)
{
    // Запрашиваем у пользователя ввод значений для массива
    for (int i = 0; i < n; i++)
    {
        printf("enter next item: ");
        // Проверяем успешность ввода
        if (scanf("%d", (parray + i)) != 1)
        {
            return 1;
        }
    }
    return 0;
}

/**
 * @brief Находит максимальное значение, которое можно получить, складывая элементы массива.
 * @param parray Указатель на массив.
 * @param n Размер массива.
 * @return Максимальное значение, которое можно получить, складывая элементы массива.
 */
int find_value(int *parray, int n)
{
    // Инициализируем максимальное значение как сумму первого и последнего элементов массива
    int max_value = *(parray) + *(parray + (n - 1));
    int value;
    // Проходим по всем возможным комбинациям элементов массива
    for (int i = 1; i <= (n - 1) / 2; i++)
    {
        value = *(parray + i) + *(parray + (n - i - 1));
        // Если текущая сумма больше максимальной, обновляем максимальное значение
        if (value > max_value)
        {
            max_value = value;
        }
    }
    return max_value;
}

int main(void)
{
    size_t array_size = ARRAY_SIZE;
    int n;
    int array[array_size];

    // Запрашиваем у пользователя размер массива
    printf("Enter n - dimension of array: ");
    // Проверяем успешность ввода
    if (scanf("%d", &n) != 1)
    {
        fprintf(stderr, "n must be integer");
        return 1;
    }

    // Проверяем корректность введенного размера массива
    if (n > ARRAY_SIZE || n <= 0)
    {
        fprintf(stderr, "n must be greater than zero and lower then or equal to ten");
        return 1;
    }
    // Заполняем массив значениями, введенными пользователем
    if (fill_array(array, n) != 0)
    {
        fprintf(stderr, "Elements of array must be integers");
        return 1;
    }

    // Находим максимальное значение, которое можно получить, складывая элементы массива
    int value = find_value(array, n);

    // Выводим найденное максимальное значение
    printf("search value: %d", value);
    return 0;
}
