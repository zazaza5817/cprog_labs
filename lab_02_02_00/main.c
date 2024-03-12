#include <stdio.h>

#define ARRAY_SIZE 10

/**
 * @brief Заполняет массив значениями, введенными пользователем.
 * @param array Массив для заполнения.
 * @param n Размер массива.
 * @return 0 в случае успеха, 1 в случае ошибки ввода.
 */
int fill_array(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("enter next item: ");
        if (scanf("%d", &array[i]) != 1)
        {
            return 1;
        }
    }
    return 0;
}

/**
 * @brief Вычисляет среднее значение элементов массива.
 * @param array Массив для вычисления среднего значения.
 * @param n Размер массива.
 * @return Среднее значение элементов массива.
 */
double get_average(int array[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += array[i];
    }
    return (double)sum / n;
}

/**
 * @brief Выводит элементы массива.
 * @param array Массив для вывода.
 * @param n Размер массива.
 */
void print_array(int array[], int n)
{
    printf("Output array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

/**
 * @brief Создает массив выходных данных, содержащий только те элементы исходного массива, которые больше среднего.
 * @param array Исходный массив.
 * @param output_array Массив выходных данных.
 * @param n Размер исходного массива.
 * @param output_n Указатель на переменную, хранящую размер выходного массива.
 * @param average Среднее значение элементов исходного массива.
 */
void create_output_array(int array[], int output_array[], int n, int *output_n, double average)
{
    for (int i = 0; i < n; i++)
    {
        if (array[i] > average)
        {
            output_array[*output_n] = array[i];
            *output_n = *output_n + 1;
        }
    }
}

int main(void)
{
    int n;
    int array[ARRAY_SIZE];
    int output_array[ARRAY_SIZE];

    printf("Enter n - dimension of array: ");
    if (scanf("%d", &n) != 1)
    {
        fprintf(stderr, "n must be integer");
        return 1;
    }

    if (n > ARRAY_SIZE || n <= 0)
    {
        fprintf(stderr, "n must be greater than zero and lower then or equal to ten");
        return 1;
    }
    if (fill_array(array, n) != 0)
    {
        fprintf(stderr, "Elements of array must be integers");
        return 1;
    }
    double average = get_average(array, n);
    int output_n = 0;
    create_output_array(array, output_array, n, &output_n, average);
    if (output_n == 0)
    {
        fprintf(stderr, "There is no elements that greater then average in array");
        return 1;
    }
    print_array(output_array, output_n);
    return 0;
}
