#include <stdio.h>
#include <math.h>

int main() 
{
    double a, b, h, c, P;

    // Чтение оснований и высоты с клавиатуры
    printf("Enter base length a: ");
    scanf("%lf", &a);
    printf("Enter base length b: ");
    scanf("%lf", &b);
    printf("Enter height h: ");
    scanf("%lf", &h);
    if (a <= 0 || b <= 0 || h <= 0)
    {
        printf("the dimensions of the bases and heights must be greater than zero");
        return 1;
    }

    // Вычисление периметра равнобедренной трапеции
    c = fabs(a - b) / 2;
    c = sqrtf(c * c + h * h);
    P =  a + b + 2 * c;

    // Вывод периметра на экран
    printf("Perimeter of an isosceles trapezoid: %.6lf\n", P);

    return  0;
}