#include <stdio.h>

int main() // Главная функция программы
{
    // Константы для стоимости воды и цены бутылки
    const int WATER_COST =   45;  
    const int BOTTLE_PRICE =   20;

    // Переменная для хранения общего количества копеек
    int totalKopecks;

    // Запрос пользователю ввести сумму в копейках
    printf("Enter the total amount of kopecks: ");
    scanf("%d", &totalKopecks);

    // Проверка корректности ввода
    if (totalKopecks <  0)
    {
        // Вывод сообщения об ошибке если сумма меньше нуля
        printf("the sum of kopecks must be greater than zero");
        return  1; // Возврат с кодом ошибки
    }

    // Проверка возможности покупки хотя бы одной бутылки
    if (totalKopecks <  45)
    {
        // Вывод сообщения о максимальном количестве бутылок
        printf("The maximum number of water bottles that can be bought is:  0");
        return  0; // Возврат без ошибок, так как задача выполнена
    }

    // Расчет максимального количества бутылок, которые можно купить
    int answer = ((totalKopecks -  45) /  25) +  1;

    // Вывод результата
    printf("The maximum number of water bottles that can be bought is: %d\n", answer);

    return   0; // Нормальное завершение программы
}