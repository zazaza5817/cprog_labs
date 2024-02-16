#include <stdio.h>
#include <math.h>

// Функция для вычисления приближенного значения синуса с помощью ряда Тейлора
float s(float x, float eps)
{
    float current_term = x, result = 0.0; // Инициализация текущего члена и результата
    int n = 0; // Счетчик для итераций
    float last_coefficient = 1.0;
    while (fabs(current_term) >= eps) 
    {
        result += current_term; // Добавляем текущий член к результату
        n ++; // Увеличиваем счетчик
        last_coefficient = last_coefficient * (2 * n - 1) / (2 * n);
        current_term = powf(x, 2 * n + 1) / (2 * n + 1) * last_coefficient;
    }
    return result; // Возвращаем результат
}

int main(void)  
{
    float x, eps, absolute_error, relative_error; // Переменные для хранения входных данных и ошибок
    int scanned; // Переменная для проверки успешности чтения данных

    printf("Enter x value: ");
    scanned = scanf("%f", &x);
    if (scanned != 1)  
    {
        fprintf(stderr, "x must be a real number");
        return 1;
    }
    if (fabs(x) > 1)
    {
        fprintf(stderr, "the absolute value of x must be less than or equal to one");
        return 1;
    }

    printf("Enter epsilon value: ");
    scanned = scanf("%f", &eps);
    if (scanned != 1)  
    {
        fprintf(stderr, "epsilon must be a real number");
        return 1;
    }
    if (eps <= 0 || eps > 1)
    {
        fprintf(stderr, "epsilon must be greater than zero and less than or equal to one");
        return 1;
    }

    float s_value = s(x, eps); // Вычисляем приближенное значение синуса
    float f_value = (float)asin(x); // Вычисляем точное значение синуса
    absolute_error = (float)fabs(f_value - s_value); // Вычисляем абсолютную ошибку
    relative_error = 0.0; // Инициализируем относительную ошибку
    if (fabs(f_value) > eps)
        relative_error = absolute_error / (float)fabs(f_value); // Вычисляем относительную ошибку
    printf("s(x) = %.6f\n", s_value); // Выводим приближенное значение синуса
    printf("f(x) = %.6f\n", f_value); // Выводим точное значение синуса
    printf("Absolute error: %.6f\n", absolute_error); // Выводим абсолютную ошибку
    printf("Relative error : %.6f\n", relative_error); // Выводим относительную ошибку

    return 0; // Завершаем программу
}
