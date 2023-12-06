#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

#include "main.h"

#define RAISE_WRONG_DATA do {\
  printf("Wrong input data, not binary!\n");\
  exit(1);\
} while(0)

int
main (int argc, char* argv[])
{
  if (argc != 2)
  {
    printf("Wrong usage!\n");
    exit(1);
  }

  // Получаем размер окна из первого аргумента
  long window_size = strtol(argv[1], NULL, 10);
  if (window_size > INT_MAX || window_size < 1)
  {
    printf("Wrong argument: out of range!\n");
    exit(1);
  }

  // Буфер для фильтруемого числа значений
  int window[window_size];
  size_t counter = 0;

  // Буфер для одного значения, будем считывать по размеру окна и сразу выводить
  char word[33];
  while (scanf("%32s", word))
  {
    // Считали необходимое число слов, фильтруем
    if (counter == window_size)
    {
      median_filter(window, window_size);
      counter = 0;
    }
    
    char* number_check;
    window[counter++] = (int)strtol(word, &number_check, 2);
    if (*number_check != '\0') 
      RAISE_WRONG_DATA;

    // В буфере символ конца строки - закончился поток данных
    char ch;
    while (ch = fgetc(stdin), ch == ' ') {}
    if (ch == '\n' || ch == EOF || ch == '\r') 
      break;
    else if (ch != '0' && ch != '1') 
      RAISE_WRONG_DATA;
    else
      ungetc(ch, stdin);
  }

  // Фильтруем оставшиеся слова
  if (counter != 0) median_filter(window, counter);
  printf("\n");
 
  return 0;
}
