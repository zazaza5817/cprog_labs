#include <stdio.h>
#include <float.h>
#include <math.h>

float get_f_value() {
    int n = 0;
    float input;
    int scan_result;
    float new_term;
    float result = 0;
    printf("enter first x: ");
    scan_result = scanf("%f", &input);
    // Проверка успешности считывания числа с плавающей точкой
    if (scan_result != 1)
    {
        printf("only float must be inputted");
        return -1; // Возвращаем ошибку, если ввод некорректен
    }

    // Цикл для считывания чисел, пока они не отрицательны
    while (input >= 0)
    {
        // Повторная проверка ввода на корректность
        if (scan_result != 1)
        {
            printf("only float must be inputted");
            return -1; // Выходим из программы, если ввод некорректен
        }
        // Увеличиваем счетчик и обновляем результат
        n += 1;
        new_term = input / n;
        if (new_term > FLT_MAX - result)
        {
            printf("OWERFLOW FLOAT TYPE");
            return -1;
        }
        result += new_term;

        // Запрашиваем следующее значение x
        printf("enter next x: ");
        scan_result = scanf("%f", &input);
    }
    return sqrtf(result);
};


int main(void)  
{
    float result;
    result = get_f_value();
    if (result < 0)
    {
        return 1;
    }
    printf("Result: %.6f", result);
    return 0; // Нормальное завершение программы
}
