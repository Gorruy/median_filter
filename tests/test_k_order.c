#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include <time.h>

#include "../src/median_filter.h"


int cmpfunc (const void * a, const void * b) 
{
   return *(int*)a - *(int*)b;
}

int main()
{
  srand(time(NULL));
  int numbers[10];
  for (size_t i = 0; i < 1000; i++)
  {
    for (size_t j = 0; j < 10; j++)
    {
      numbers[j] = (int) rand();
    }
    int tst = k_order(numbers, 6, 10);
    qsort(numbers, 10, sizeof(int), cmpfunc);
    assert(tst == numbers[6] && "k_order test doesn't passed!\n");
  }

  printf("k_order test passed!\n");
  return 0;
}
