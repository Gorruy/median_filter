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

void partition_check()
{
  srand(time(NULL));
  int array[1024];

  // Генерируется случайная тестовая последовательность
  for (size_t i = 0; i < 1024; i++)
  {
    array[i] = rand();
  }
  int k = partition(array, 0, 1024);
  int num = array[k];
  // Стандартной функцией сортировки полностью сортируется массив
  qsort(array, 1024, sizeof(int), cmpfunc);

  if (num != array[k])
    exit(1);
}

int main()
{
  for (size_t i = 0; i < 100; i++)
  {
    partition_check();
  }
  exit(0);
}

