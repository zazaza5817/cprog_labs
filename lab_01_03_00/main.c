#include <stdio.h>


#define M_NORMAL_MULTIPLIER 240
#define CENTIMETERS_IN_METER  100

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
        fprintf(stderr, "height must be greater then zero");
        return 1;
    }
    printf("Enter chest circumference in centimeters: ");
    scanf("%f", &t);
    if (t <= 0)
    {
        fprintf(stderr, "chest circumference must be greater then zero");
        return 1;
    }
    printf("Enter body weight in kilograms: ");
    scanf("%f", &m);
    if (m <= 0)
    {
        fprintf(stderr, "body weight must be greater then zero");
        return 1;
    }

    // Расчет нормального веса
    m_normal = (h * t) / M_NORMAL_MULTIPLIER;

    // Расчет BMI
    bmi = m / (h / CENTIMETERS_IN_METER * h / CENTIMETERS_IN_METER);

    // Вывод результатов
    printf("Normal weight: %.6f кг\n", m_normal);
    printf("BMI: %.6f\n", bmi);

    return 0;
}
