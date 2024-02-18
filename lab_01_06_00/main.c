#include <stdio.h>
#include <math.h>

#define ACCURACY 0.0001
#define SCANF_PARAMS_COUNT 6

/**
 * @brief Вычисляет квадрат расстояния между двумя точками
 *
 * Эта функция вычисляет квадрат расстояни между двумя точками,
 * заданными координатами (x1, y1) и (x2, y2).
 *
 * @param x1 The x-coordinate of the first point.
 * @param y1 The y-coordinate of the first point.
 * @param x2 The x-coordinate of the second point.
 * @param y2 The y-coordinate of the second point.
 * @return The square of the Euclidean distance between the two points.
 */
double sqr_distance(double x1, double y1, double x2, double y2)  
{
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

/**
 * @brief Классифицирует треугольник по координатам его вершинам.
 *
 * Функция определяет тип треугольника на основе координат его вершин.
 * Возвращает -1, если точки лежат на одной прямой или совпадают;
 *  1, если треугольник является прямоугольным;
 *  2, если треугольник является тупоугольным;
 *  0, если треугольник является остроугольным.
 *
 * @param x1 x-координата первой вершины.
 * @param y1 y-координата первой вершины.
 * @param x2 x-координата второй вершины.
 * @param y2 y-координата второй вершины.
 * @param x3 x-координата третьей вершины.
 * @param y3 y-координата третьей вершины.
 * @return int -1 для невалидного треугольника,  1 для прямоугольного,  2 для тупоугольного,  0 для остроугольного.
 */
int classify_triangle(double x1, double y1, double x2, double y2, double x3, double y3)  
{
    double area = fabs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
    if (area <= ACCURACY) 
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
    if (fabs(a - (b + c)) < ACCURACY)  
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
    if (scan_result != SCANF_PARAMS_COUNT)  
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
