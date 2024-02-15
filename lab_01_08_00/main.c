#include <stdio.h> // Подключение библиотеки стандартного ввода-вывода
#include <stdint.h>
#include <inttypes.h> 

// Функция для вывода двоичного представления числа в  4 байта
void print_four_byte_binary(uint32_t num) 
{
    for (int i = 31; i >= 0; i--)  
    {
        printf("%d", (num >> i) & 1);
    }
    printf("\n"); // Переход на новую строку после вывода всех битов
}

// Функция для циклического сдвига числа влево на заданное количество позиций
uint32_t cycle_shift(uint32_t a, int n) 
{
    n %= 32; // Ограничиваем количество сдвигов размером типа unsigned int
    a = (a >> n) | (a << (32 - n)); // Выполняем циклический сдвиг
    return a; // Возвращаем результат сдвига
}

int main(void) 
{
    uint32_t a; // Переменная для хранения числа
    int n; // Переменная для хранения количества сдвигов
    int scan_result; // Переменная для проверки успешности сканирования
    printf("Enter an unsigned integer four bytes long: "); // Запрос на ввод числа
    scan_result = scanf("%" PRIu32, &a); // Считывание числа
    if (scan_result != 1)
    {
        fprintf(stderr, "Error: an unsigned number must be entered"); // Сообщение об ошибке
        return 1; // Возврат из программы с кодом ошибки
    }
    printf("Enter the number of positions to shift: "); // Запрос на ввод количества сдвигов
    scan_result = scanf("%d", &n); // Считывание количества сдвигов
    if (scan_result != 1)
    {
        fprintf(stderr, "Error: an integer must be entered"); // Сообщение об ошибке
        return 1; // Возврат из программы с кодом ошибки
    }
    if (n < 0)
    {
        fprintf(stderr, "Error: shift cannot be negative"); // Сообщение об ошибке
        return 1; // Возврат из программы с кодом ошибки
    }
    uint32_t result = cycle_shift(a, n); // Выполнение циклического сдвига
    printf("Result: "); // Вывод результата
    print_four_byte_binary(result); // Вывод результата в двоичном виде
    return 0; // Нормальный завершение программы
}
