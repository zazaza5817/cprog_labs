#!/bin/bash

for c_file in *.c; do
    gcc -std=c99 -Wall -Wextra -Werror -Wpedantic -Wfloat-equal -Wfloat-conversion -O0 -g3 -c "$c_file"
done

o_files=$(ls *.o)

gcc $o_files -o app.exe -lm
