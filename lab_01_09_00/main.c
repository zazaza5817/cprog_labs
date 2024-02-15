#include <stdio.h>
#include <float.h>
#include <math.h>

int main(void)  
{
    // Объявляем переменные для хранения результата и входных данных
    float result = 0; // Инициализируем результат нулем
    float input;
    int n = 0; // Счетчик для деления
    int scan_result;
    float new_term;

    // Запрашиваем первое значение x от пользователя
    printf("enter first x: ");
    scan_result = scanf("%f", &input);

    // Проверка успешности считывания числа с плавающей точкой
    if (scan_result != 1)
    {
        printf("only float must be inputted");
        return 1; // Возвращаем ошибку, если ввод некорректен
    }

    // Цикл для считывания чисел, пока они не отрицательны
    while (input >= 0)
    {
        // Повторная проверка ввода на корректность
        if (scan_result != 1)
        {
            printf("only float must be inputted");
            return 1; // Выходим из программы, если ввод некорректен
        }

        // Увеличиваем счетчик и обновляем результат
        n += 1;
        new_term = input / n;
        if (new_term > DBL_MAX - result)
        {
            printf("OWERFLOW DOUBLE TYPE");
            return 1;
        }
        result += new_term;

        // Запрашиваем следующее значение x
        printf("enter next x: ");
        scan_result = scanf("%f", &input);
    }

    // Выводим квадратный корень из суммы
    printf("Result: %.6lf", sqrtf(result));
    return 0; // Нормальное завершение программы
}
