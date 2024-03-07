#!/bin/bash

c_file="main.c"

clang -std=c99 -c "$c_file" -o main.o -fsanitize=undefined -fPIE -g -O0
clang main.o -o app.exe -fsanitize=undefined -lm -pie