#!/bin/bash

# Определение шаблона для поиска файлов с положительными тестами
pos_files="../data/pos_[0-9][0-9]_in.txt"

# Цикл по файлам с положительными тестами
for file_stream_in in $pos_files; do
    # Проверка на совпадение с шаблоном, чтобы избежать ошибок при неправильном расширении
    if [ "$file_stream_in" == "$pos_files" ]; then
        break
    fi
    # Извлечение номера теста из имени файла
    test_number=$(echo "$file_stream_in" | grep -o -E '[0-9]+')

    # Формирование пути к ожидаемому выходному файлу
    file_stream_out_expect="../data/pos_$test_number""_out.txt"

    # Проверка на существование ожидаемого выходного файла
    if [ -f "$file_stream_out_expect" ]; then
        # Формирование команды для выполнения скрипта тестирования
        command="./pos_case.sh $file_stream_in $file_stream_out_expect"
    else
        echo "positive $test_number: ERROR"
        continue
    fi
    # Выполнение команды тестирования
    $command
    exit_code="$?"

    # Проверка кода выхода команды
    if [ "$exit_code" -eq "0" ]; then
        echo "positive $test_number: OK"
    else
        echo "positive $test_number: ERROR"
    fi
done

# Определение шаблона для поиска файлов с отрицательными тестами
neg_files="../data/neg_[0-9][0-9]_in.txt"

# Цикл по файлам с отрицательными тестами
for file_stream_in in $neg_files; do
    # Проверка на совпадение с шаблоном, чтобы избежать ошибок при неправильном расширении
    if [ "$file_stream_in" == "$neg_files" ]; then
        break
    fi
    # Извлечение номера теста из имени файла
    test_number=$(echo "$file_stream_in" | grep -o -E '[0-9]+')

    # Формирование команды для выполнения скрипта тестирования
    command="./neg_case.sh $file_stream_in"
    # Выполнение команды тестирования
    $command
    exit_code="$?"

    # Проверка кода выхода команды
    if [ "$exit_code" -eq "0" ]; then
        echo "negative $test_number: OK"
    else
        echo "negative $test_number: ERROR"
    fi
done
