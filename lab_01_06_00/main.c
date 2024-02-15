#include <stdio.h>
#include <math.h>

// Функция для расчета квадрата расстояния между двумя точками
double sqr_distance(double x1, double y1, double x2, double y2)  
{
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

// Функция для классификации треугольника
int classify_triangle(double x1, double y1, double x2, double y2, double x3, double y3)  
{
    double area = fabs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
    if (area <= 0.0001) 
    {
        return -1; // Точки лежат на одной или прямой или две/три точки совпадают
    }
    double a, b, c; // Квадрат длин сторон

    // Рассчитать квадраты длин сторон
    a = sqr_distance(x1, y1, x2, y2);
    b = sqr_distance(x1, y1, x3, y3);
    c = sqr_distance(x2, y2, x3, y3);

    // Отсортировать квадраты длин
    if (a < b)  
    {
        double temp = a;
        a = b;
        b = temp;
    }
    if (a < c)  
    {
        double temp = a;
        a = c;
        c = temp;
    }
    // Классифицировать треугольник по теореме Пифагора
    if (fabs(a - (b + c)) < 0.0001)  
    {
        return 1;
    }  
    else if (a > b + c)  
    {
        return 2;
    }  
    else  
    {
        return 0;
    }
}

int main(void)  
{
    double x1, y1, x2, y2, x3, y3;
    int triagle_class;
    int scan_result;
    // Ввод координат вершин
    printf("Введите координаты первой вершины (x y): ");
    scan_result = scanf("%lf %lf", &x1, &y1);
    printf("Введите координаты второй вершины (x y): ");
    scan_result += scanf("%lf %lf", &x2, &y2);
    printf("Введите координаты третьей вершины (x y): ");
    scan_result += scanf("%lf %lf", &x3, &y3);
    if (scan_result != 6)  
    {
        fprintf(stderr, "ошибка ввода\n");
        return 1;
    }
    // Классификация треугольника
    triagle_class = classify_triangle(x1, y1, x2, y2, x3, y3);
    if (triagle_class == -1)
    {
        fprintf(stderr, "the entered point coordinates do not form a triangle");
        return 1;
    }
    printf("%d", triagle_class);
    return 0;
}
