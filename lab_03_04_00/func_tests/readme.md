# Тесты для лабораторной работы 3
## Входные данные
n, m - размерности матрицы, после чего n*m целых чисел - элементов входной матрицы
## Выходные данные
целое число value - наименьшее нечетное, лежащее под главной диагональю
## Позитивные тесты:
- 01 - минимальный размер матрицы - 2x2
- 02 - подходищих элементов несколько (ожидается минимальный из них)
- 03 - только положительные подходящие элементы
- 04 - только отрицательные подходящие элементы 
## Негативные тесты:
- 01 - Ошибка ввода размерности n
- 02 - Ошибка ввода размерности m
- 03 - Ошибка ввода очередного элемента 
- 04 - Нет ни одного подходящего элемента
- 05 - n не равно m
- 06 - n равно m равно еденице
