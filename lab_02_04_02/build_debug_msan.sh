#!/bin/bash

c_file="main.c"

clang -std=c99 -c "$c_file" -o main.o -fsanitize=memory -fPIE -g -O0
clang main.o -o app.exe -fsanitize=memory -pie -lm