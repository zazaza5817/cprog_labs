#!/bin/bash

for c_file in *.c; do
    clang -std=c99 -c "$c_file" -fsanitize=memory -fPIE -g -O0
done

o_files=$(ls *.o)

clang $o_files -o app.exe -fsanitize=memory -pie -lm
