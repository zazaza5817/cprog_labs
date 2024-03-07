#!/bin/bash

for_delete="*.exe *.o ./func_tests/scripts/*.txt *.gcno *.gcda *.gcov"

for mask in $for_delete; do
	rm -f "$mask" 
done