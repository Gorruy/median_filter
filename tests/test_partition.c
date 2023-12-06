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

int partition_check()
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

  assert(num == array[k] && "Partition doesnt work!!\n");

  return 0;
}

int main()
{
  for (size_t i = 0; i < 100; i++)
  {
    assert(partition_check() == 0 && "Partition fault!\n");
  }
  printf("partition tests passed!\n");
}

