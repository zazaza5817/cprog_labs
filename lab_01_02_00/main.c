#include <stdio.h>
#include <math.h>

int main(void) 
{
    float a, b;
    float h;
    float c;
    float per;

    // Чтение оснований и высоты с клавиатуры
    printf("Enter base length a: ");
    scanf("%f", &a);
    printf("Enter base length b: ");
    scanf("%f", &b);
    printf("Enter height h: ");
    scanf("%f", &h);
    if (a <= 0 || b <= 0 || h <= 0)
    {
        fprintf(stderr, "the dimensions of the bases and heights must be greater than zero");
        return 1;
    }

    // Вычисление периметра равнобедренной трапеции
    c = (float)fabs(a - b) / 2;
    c = (float)sqrtf(c * c + h * h);
    per = a + b + 2 * c;

    // Вывод периметра на экран
    printf("Perimeter of an isosceles trapezoid: %.6lf\n", per);

    return 0;
}
