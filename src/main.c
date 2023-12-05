#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

#include "main.h"


int
main (int argc, char* argv[])
{
  printf("%i %s", argc, argv[1]);
  if (argc != 2 && strcmp(argv[1], "--help") != 0)
  {
    printf("Wrong usage!\n");
    exit(1);
  }

  long window_size = strtol(argv[1], NULL, 10);
  if (window_size > INT_MAX || window_size < 1)
  {
    printf("Wrong argument: out of range!\n");
    exit(1);
  }

  int window[window_size];
  size_t counter = 0;
  char ch[32];
  scanf("%s", ch);
  do
  {
    if (counter == window_size)
    {
      median_filter(window, window_size);
      counter = 0;
    }
    
    window[counter++] = (int)strtol(ch, NULL, 2);

    if (fgetc(stdin) == '\n') break;
    scanf("%s", ch);
  } while (1);

  if (counter != 0) median_filter(window, counter);
  printf("\n");
 
  return 0;
}
