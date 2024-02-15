#include <stdio.h>
#include <limits.h>


int get_fib(int n)
{
    int fib0 = 0; // Первое число Фибоначчи
    int fib1 = 1; // Второе число Фибоначчи
    int fib2;  // Переменная для хранения следующего числа Фибоначчи
    // Проверка случая, когда введено число  0 или  1
    if (n <= 1)
    {
        if (n == 1)
        {
            return fib1; // Вывод второго числа Фибоначчи
        }  
        else  
        {
            return fib0; // Вывод первого числа Фибоначчи
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        // Проверка возможности переполнения при вычислении следующего числа
        if (fib1 > INT_MAX - fib0)
        {
            return -1;
        }
        fib2 = fib0 + fib1; // Вычисление следующего числа Фибоначчи
        fib0 = fib1; // Перемещение второго числа в первое
        fib1 = fib2; // Перемещение следующего числа во второе
    }
    return fib2;
}


int main(void)  
{
    // Инициализация переменных для хранения чисел Фибоначчи
    int n, status; // Переменные для хранения введенного пользователем числа и статуса чтения

    // Вывод приглашения к вводу числа
    printf("enter n: ");


    // Чтение числа от пользователя и проверка корректности ввода
    status = scanf("%d", &n);
    if (status != 1 || (status == 1 && n < 0))  
    {
        // Если ввод некорректен, выводим сообщение об ошибке и завершаем программу
        fprintf(stderr, "Wrong input!\n");
        return 1;
    }
    int fib = get_fib(n);
    if (fib == -1)
    {
        fprintf(stderr, "It is impossible to calculate a given Fibonacci number because int overflow occurs");
        return 1;
    }
    // Вывод искомого числа Фибоначчи
    printf("Fibonacci number whose number was entered: %d\n", fib);
    return 0;
}
