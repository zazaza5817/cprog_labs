#include <stdio.h>

int main() 
{
    // Объявление переменных
    int h; // Рост в сантиметрах
    int t; // Обхват грудной клетки в сантиметрах
    double m; // Масса тела в килограммах
    double m_normal; // Нормальный вес
    double BMI; // Индекс массы тела

    // Чтение данных
    printf("Enter height in centimeters: ");
    scanf("%d", &h);
    if (h <= 0)
    {
        printf("height must be greater then zero");
        return 1;
    }
    printf("Enter chest circumference in centimeters: ");
    scanf("%d", &t);
    if (t <= 0)
    {
        printf("chest circumference must be greater then zero");
        return 1;
    }
    printf("Enter body weight in kilograms: ");
    scanf("%lf", &m);
    if (m <= 0)
    {
        printf("body weight must be greater then zero");
        return 1;
    }

    // Расчет нормального веса
    m_normal = ((double)h /  240) * t;

    // Расчет BMI
    BMI = m / ((double)h * h);

    // Вывод результатов
    printf("Normal weight: %.6lf кг\n", m_normal);
    printf("BMI: %.6lf\n", BMI);

    return  0;
}
