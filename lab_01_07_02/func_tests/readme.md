# Тесты для лабораторной работы 1
## Входные данные
Рациональные x - точка в которой производить вычисления, eps - погрешность вплоть до которой производить вычисления
## Выходные данные
Рациональные s(x) - прближенное значение, f(x) - точное значение, абсолютна и относительная погрешности
## Позитивные тесты:
- 01 - вводиться x = 0.3 eps = 0.000001 (случайные значения)
- 02 - вводится x = 0.5 eps = 1 (пограничное значение eps)
## Негативные тесты:
- 01 - вместо x вводится символ
- 02 - вводится eps = 10, x - валидное
- 03 - вводится eps = -1, x - валидное
- 04 - вводится x = 2, eps - валидное
- 05 - вводится eps, которое не является числом