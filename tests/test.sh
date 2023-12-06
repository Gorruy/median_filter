#!/usr/bin/bash

#Тест модуля вывода данных в бинарном формате
rm -f output.txt test_print test.txt && gcc test_print_bin.c ../src/median_filter.c -o test_print;

printer='10101000 1010101010 111 1 1111111 1111111 110101010 11111111111111111111111111111111 10000000000000000000000000000000';
counter=9;
echo $printer > test.txt && echo $printer | ./test_print $counter;

diff -w test.txt output.txt;

rm -f test_partition && gcc test_partition.c ../src/median_filter.c -o test_partition;

# Тест модуля сортировки
./test_partition;

rm -f test_partition test_print *.txt

rm -f test_main output.txt && gcc test_main.c ../src/median_filter.c -o test_main;

# Тест всей программы
cycles=10000;
window_size=10;
let res=$cycles/$window_size+1;
./test_main $cycles | ../bin/median_filter $window_size > test.txt;

grep -o '[^[:space:]]*' test.txt | sort -u | wc -l| (read words &&
if [[ $(($words)) -eq $res ]] 
then
    echo "first main test passed!"
else
    echo "first main test doesnt passed!"
fi);

echo "1 10101001 11111111111111111111111111111111 1" | ../bin/median_filter 2 | (read res &&
if [[ $res == "1010101 1010101 0 0" ]] 
then 
    echo "second main test passed!" 
else 
    echo "second main test doesnt passed!" 
fi);

echo "100 11111 100101 1010110 1010100 1010101 11111 11111110110111101111110111000011" | 
    ../bin/median_filter 3 | (read res && 
if [[ $res == "11111 11111 11111 1010101 1010101 1010101 11111111011011110111111011110001 11111111011011110111111011110001" ]] 
then 
    echo "third main test passed!" 
else 
    echo "third main test doesnt passed!" 
fi);

echo "1 1 1 1001 10010 10101010 11010 10101010 111 0 0 0 0 1 1 1" | ../bin/median_filter 1 | (read res &&
if [[ $res == "1 1 1 1001 10010 10101010 11010 10101010 111 0 0 0 0 1 1 1" ]] 
then 
    echo "fourth main test passed!" 
else 
    echo "fourth main test doesnt passed!" 
fi);

echo "1 1 1 10101010101010" | ../bin/median_filter | (read res &&
if [[ $res == "Wrong usage!" ]] 
then 
    echo "fifth main test passed!" 
else 
    echo "fifth main test doesnt passed!" 
fi);

echo "1 1 1 10101010101010" | ../bin/median_filter -10| (read res &&
if [[ $res == "Wrong argument: out of range!" ]] 
then 
    echo "sixth main test passed!" 
else 
    echo "sixth main test doesnt passed!" 
fi);

echo "1 1 1 10101010101010" | ../bin/median_filter 13120312312312312312351234135| (read res &&
if [[ $res == "Wrong argument: out of range!" ]] 
then 
    echo "seventh main test passed!" 
else 
    echo "seventh main test doesnt passed!" 
fi);
rm -f test_main test.txt;
