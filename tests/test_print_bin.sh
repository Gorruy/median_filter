#!/usr/bin/bash

#Тест модуля вывода данных в бинарном формате
gcc ../tests/test_print_bin.c ../src/median_filter.c -o test_print;

printer='10101000 1010101010 111 1 1111111 1111111 110101010 11111111111111111111111111111111 10000000000000000000000000000000';
counter=9;
echo $printer > test_print_bin.txt && echo $printer | ./test_print $counter;

if [[ $(diff -w test_print_bin.txt output_print_bin.txt) ]]; 
then
    exit 1
else
    exit 0
fi;
