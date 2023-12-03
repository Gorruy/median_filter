#include "median_filter.h"


int print_bin(int number, long window_size)
{
  return 0;
}

int partition(int* numbers, int left, int right)
{
  int mid = 0;

}

int
median_filter(int* numbers, long window_size)
{
  if (window_size == 1) print_bin(numbers[0], 1);

  int middle = window_size >> 1;
  int left = 0, right = window_size, k;
  
  while (1)
  {
    int k = partition(numbers, left, right);
    if (k == middle) break;
    else if (k < middle) left = k;
    else right = k;
  }

  print_bin(numbers[k], window_size);
  return 0;
}
