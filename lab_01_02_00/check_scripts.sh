#!/bin/bash

current_scripts="./*.sh"
testing_scripts="func_tests/scripts/*.sh"

for script in $current_scripts; do
    shellcheck "$script"
done

for script in $testing_scripts; do
    shellcheck "$script"
done
