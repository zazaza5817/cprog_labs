#include <stdio.h>

int main(void)
{
    // Переменная для хранения общего количества копеек
    int total_kopecks;

    // Запрос пользователю ввести сумму в копейках
    printf("Enter the total amount of kopecks: ");
    scanf("%d", &total_kopecks);

    // Проверка корректности ввода
    if (total_kopecks < 0)
    {
        // Вывод сообщения об ошибке если сумма меньше нуля
        fprintf(stderr, "the sum of kopecks must be greater than zero");
        return 1; // Возврат с кодом ошибки
    }

    // Проверка возможности покупки хотя бы одной бутылки
    if (total_kopecks < 45)
    {
        // Вывод сообщения о максимальном количестве бутылок
        printf("The maximum number of water bottles that can be bought is:  0");
        return 0; // Возврат без ошибок, так как задача выполнена
    }

    // Расчет максимального количества бутылок, которые можно купить
    int answer = ((total_kopecks - 45) / 25) + 1;

    // Вывод результата
    printf("The maximum number of water bottles that can be bought is: %d\n", answer);

    return 0; // Нормальное завершение программы
}
