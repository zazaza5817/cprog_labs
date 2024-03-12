#!/bin/bash

c_file="main.c"

gcc -std=c99 -c "$c_file" -o main.o -fsanitize=address -g -O0
gcc main.o -o app.exe -fsanitize=address -lm
