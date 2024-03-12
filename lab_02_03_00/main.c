#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 10
#define BASE_TEN 10

/**
 * @brief Заполняет массив числами, введенными пользователем.
 * @param array Массив для заполнения.
 * @param n Размер массива.
 * @return 0 в случае успеха, 1 в случае ошибки ввода.
 */
int fillArray(int array[], int n)
{
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
 * @brief Выводит элементы массива.
 * @param array Массив для вывода.
 * @param n Размер массива.
 */
void printArray(int array[], int n)
{
    printf("Output array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

/**
 * @brief Проверяет, является ли число палиндромом.
 * @param num Проверяемое число.
 * @return true, если число является палиндромом, иначе false.
 */
bool isPalindrome(int num)
{
    int reversed = 0, temp = num;
    while (temp != 0)
    {
        int digit = temp % BASE_TEN;
        reversed = reversed * BASE_TEN + digit;
        temp /= BASE_TEN;
    }
    return num == reversed;
}

/**
 * @brief Удаляет все палиндромы из массива.
 * @param arr Массив, из которого удаляются палиндромы.
 * @param n Указатель на размер массива, который изменяется в процессе удаления.
 */
void removePalindromes(int arr[], int *n)
{
    int readPtr = 0;
    int writePtr = 0;

    while (readPtr < *n)
    {
        if (!isPalindrome(arr[readPtr]))
        {
            arr[writePtr] = arr[readPtr];
            writePtr++;
        }
        readPtr++;
    }
    *n = writePtr;
}

int main(void)
{
    int n;
    int array[ARRAY_SIZE];

    printf("Enter n - dimension of array: ");
    // Проверяем успешность ввода размера массива
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
    // Заполняем массив и проверяем на ошибки
    if (fillArray(array, n) != 0)
    {
        fprintf(stderr, "Elements of array must be integers");
        return 1;
    }
    // Удаляем палиндромы из массива
    removePalindromes(array, &n);
    // Выводим массив
    printArray(array, n);
    return 0;
}
