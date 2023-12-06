#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include <time.h>

#include "../src/median_filter.h"


int gen(int cycle)
{
  srand(time(NULL));
  for (size_t i = 0; i < cycle; i++)
  {
    int k = rand() - (INT_MAX >> 1);
    print_bin(k, 1);
  }
  printf("1101010010101\n");
  return 0;
}

int main(int argc, char* argv[])
{
  gen(atoi(argv[1]));
}



