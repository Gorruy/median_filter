#!/usr/bin/bash
# Тест всей программ

set -e

cycles=10000;
window_size=10;
let res=$cycles/$window_size+1;
./test_main $cycles | ../bin/median_filter $window_size > test_main.txt;

grep -o '[^[:space:]]*' test_main.txt | sort -u | wc -l| { read words &&
if [[ $(($words)) -ne $res ]] 
then
    exit 1
fi }

echo "1 10101001 11111111111111111111111111111111 1" | ../bin/median_filter 2 | { read res && 
if [[ $res != "1010101 1010101 0 0" ]];
then
    exit 1;
fi }

echo "100 11111 100101 1010110 1010100 1010101 11111 11111110110111101111110111000011" | ../bin/median_filter 3 | { read res && 
if [[ $res != "11111 11111 11111 1010101 1010101 1010101 11111111011011110111111011110001 11111111011011110111111011110001" ]] 
then
    exit 1
fi }

echo "1 1 1 1001 10010 10101010 11010 10101010 111 0 0 0 0 1 1 1" | ../bin/median_filter 1 | { read res &&
if [[ $res != "1 1 1 1001 10010 10101010 11010 10101010 111 0 0 0 0 1 1 1" ]] 
then 
    exit 1
fi }

echo "1 1 1 10101010101010" | ../bin/median_filter | { read res &&
if [[ $res != "Wrong usage!" ]] 
then 
    exit 1
fi }

echo "1 1 1 10101010101010" | ../bin/median_filter -10| { read res &&
if [[ $res != "Wrong argument: out of range!" ]] 
then 
    exit 1
fi }

echo "1 1 1 10101010101010" | ../bin/median_filter 13120312312312312312351234135| { read res &&
if [[ $res != "Wrong argument: out of range!" ]] 
then 
    exit 1
fi }

exit 0

