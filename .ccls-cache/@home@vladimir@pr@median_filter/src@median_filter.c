#include <stdlib.h>
#include <stdio.h>

#include "median_filter.h"


#define SWAP(a, b) (a ^= b ^= a ^= b)

int print_bin(int number, long window_size)
{
  printf("NUMBER IS: %i\n", number);
  return 0;
}

int partition(int* numbers, int left, int right)
{
  int pivot = numbers[left];
  for (size_t i = left + 1; i < right; i++)
  {
    if (numbers[i] < pivot)
    {
      SWAP(numbers[i], numbers[left+1]);
      SWAP(numbers[left+1], numbers[left]);
      left++;
    }
  }

  return left;

}

int 
k_order(int numbers[], int k, long size)
{
  int right = size, left = 0;
  while (1)
  {
    int mid = partition(numbers, left, right);
    printf("%i %i\n", mid, k);
    if (mid == k) 
    {
      break;
      return numbers[mid];
    }
    else if (mid < k) left = mid;
    else right = mid;
  }

  return -1;
}

int
median_filter(int* numbers, long window_size)
{
  if (window_size == 1) print_bin(numbers[0], 1);

  int middle = window_size >> 1;
  if (window_size % 2 == 1)
  {
    return (k_order(numbers, middle, window_size) 
          + k_order(numbers, middle + 1, window_size)) >> 1;
  }

  return k_order(numbers, middle, window_size);
}

