#!/bin/bash

for c_file in *.c; do
    gcc -std=c99 -c "$c_file" -fsanitize=address -g -O0
done

o_files=$(ls *.o)

gcc $o_files -o app.exe -fsanitize=address -lm
