#include <stdio.h>
#include <math.h>

/**
 * @brief Вычисление значения по заданной формуле пока не будет введен первый отрицательный член
 *
 * Функция принимает на вход числа x, начиная с первого положительного, и вычисляет значение по формуле,  
 * добавляя каждый новый член к результату. Процесс продолжается до тех пор, пока не будет введен первый  
 * отрицательный член. Если ввод не является числом с плавающей точкой, функция выводит ошибку и возвращает -1.
 *
 * @return Значение, вычисленное по заданной формуле, или -1 в случае ошибки ввода
 */
float get_f_value(void)
{
    float result = 0;
    float input;
    int n = 0;
    int scan_result;
    float new_term;

    printf("enter first x: ");
    scan_result = scanf("%f", &input);
    if (scan_result != 1)
    {
        fprintf(stderr, "only float must be inputted");
        return -1;
    }
    if (input < 0)
    {
        fprintf(stderr, "sequence cannot be empty");
        return -1;
    }
    

    while (input >= 0)
    {
        n += 1;
        new_term = input / n;
        result += new_term;

        printf("enter next x: ");
        scan_result = scanf("%f", &input);
        if (scan_result != 1)
        {
            fprintf(stderr, "only float must be inputted");
            return -1;
        }
    }
    return result;
}


int main(void)  
{
    float result;
    result = get_f_value();
    if (result < 0)
    {
        return 1;
    }
    printf("Result: %.6lf", sqrtf(result));
    return 0;
}
