#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

#include "main.h"


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
  scanf("%32s", word);
  do
  {
    // Считали необходимое число слов, фильтруем
    if (counter == window_size)
    {
      median_filter(window, window_size);
      counter = 0;
    }
    
    window[counter++] = (int)strtol(word, NULL, 2);

    // В буфере символ конца строки - закончился поток данных
    if (fgetc(stdin) == '\n') break;
    scanf("%32s", word);
  } while (1);


  // Фильтруем оствавшиеся слова
  if (counter != 0) median_filter(window, counter);
  printf("\n");
 
  return 0;
}
