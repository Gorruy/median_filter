#!/usr/bin/bash

rm -f output.txt test_print test.txt && gcc test_print_bin.c ../src/median_filter.c -o test_print;

printer='10101000 1010101010 111 1 1111111 1111111 110101010 11111111111111111111111111111111 10000000000000000000000000000000';
counter=9;
echo $printer > test.txt && echo $printer | ./test_print $counter;

diff -w test.txt output.txt;

rm -f test_partition && gcc test_partition.c ../src/median_filter.c -o test_partition;

./test_partition;

rm -f test_partition test_print *.txt

