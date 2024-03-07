#!/bin/bash

c_file="main.c"

gcc -std=c99 -Wall -Wextra -Werror -Wpedantic -Wfloat-equal -Wfloat-conversion -c -O3 "$c_file"
gcc main.o -o app.exe -lm