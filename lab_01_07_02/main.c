#include <stdio.h>
#include <math.h>

// Функция для вычисления приближенного значения синуса с помощью ряда Тейлора
double s(double x, double eps)
{
    double current_term = x, result =  0.0; // Инициализация текущего члена и результата
    int n =  0; // Счетчик для итераций
    while (fabs(current_term) >= eps) // Цикл, продолжаемый пока текущий член не станет меньше заданной точности
    {
        result += current_term; // Добавляем текущий член к результату
        n ++; // Увеличиваем счетчик
        int numerator =  1; // Нумератор для формулы ряда
        for (int i =  1; i <= (2*n-1); i +=  2)
        {
            numerator *= i; // Вычисляем факториал для нумератора
        }
        int denominator =  1; // Знаменатель для формулы ряда
        for (int i =  2; i <=  2*n; i +=  2)
        {
            denominator *= i; // Вычисляем факториал для знаменателя
        }
        double main_part; // Главная часть ряда
        main_part = (powf(x, (2*n+1))) / (double)(2*n+1); // Вычисляем главную часть ряда
        current_term = ((double)numerator / denominator) * main_part; // Обновляем текущий член ряда
    }
    return result; // Возвращаем результат
}

int main()  
{
    double x, eps, absolute_error, relative_error; // Переменные для хранения входных данных и ошибок
    int scanned; // Переменная для проверки успешности чтения данных

    printf("Введите значение x: ");
    scanned = scanf("%lf", &x);
    if (scanned !=  1)  
    {
        printf("x должно быть вещественным числом");
        return  1;
    }
    if (fabs(x) >  1)
    {
        printf("абсолютное значение x должно быть меньше или равно единице");
        return  1;
    }

    printf("Введите значение эпсилон: ");
    scanned = scanf("%lf", &eps);
    if (scanned !=  1)  
    {
        printf("эпсилон должно быть вещественным числом");
        return  1;
    }
    if (eps <=  0 || eps >  1)
    {
        printf("эпсилон должно быть больше нуля и меньше или равно единице");
        return  1;
    }

    double s_value = s(x, eps); // Вычисляем приближенное значение синуса
    double f_value = asin(x); // Вычисляем точное значение синуса
    absolute_error = fabs(f_value - s_value); // Вычисляем абсолютную ошибку
    relative_error =  0.0; // Инициализируем относительную ошибку
    if (fabs(f_value) > eps)
        relative_error = absolute_error / fabs(f_value); // Вычисляем относительную ошибку

    printf("s(x) = %.6lf\n", s_value); // Выводим приближенное значение синуса
    printf("f(x) = %.6lf\n", f_value); // Выводим точное значение синуса
    printf("Абсолютная ошибка : %.6lf\n", absolute_error); // Выводим абсолютную ошибку
    printf("Относительная ошибка : %.6lf\n", relative_error); // Выводим относительную ошибку

    return   0; // Завершаем программу
}