#include <stdio.h>

int main(void) 
{
    // Объявление переменных
    float h, t; // Рост и обхват грудной клетки в сантиметрах
    float m; // Масса тела в килограммах
    float m_normal; // Нормальный вес
    float bmi; // Индекс массы тела

    // Чтение данных
    printf("Enter height in centimeters: ");
    scanf("%f", &h);
    if (h <= 0)
    {
        printf("height must be greater then zero");
        return 1;
    }
    printf("Enter chest circumference in centimeters: ");
    scanf("%f", &t);
    if (t <= 0)
    {
        printf("chest circumference must be greater then zero");
        return 1;
    }
    printf("Enter body weight in kilograms: ");
    scanf("%f", &m);
    if (m <= 0)
    {
        printf("body weight must be greater then zero");
        return 1;
    }

    // Расчет нормального весаba
    m_normal = (h * t) / 240;

    // Расчет BMI
    bmi = m / (h / 100 * h / 100);

    // Вывод результатов
    printf("Normal weight: %.6f кг\n", m_normal);
    printf("BMI: %.6f\n", bmi);

    return 0;
}
