#include <stdlib.h>
#include <stdio.h>

#include "median_filter.h"


#define SWAP(a, b) do{\
  int buf = a;\
  a = b;\
  b = buf;\
} while(0)


int print_bin(int number, long window_size)
{
  char buf[33];
  buf[32] = 0;
  int counter = 31;
  while (number != 0)
  {
    buf[counter--] = number % 2 + '0';
    number = number >> 1;
  }
  buf[counter] = 0;
  for (size_t i = 0; i < window_size; i++)
  {
    printf("%s ", (buf + counter + 1));
  }
  printf(" ");
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
k_order(int* numbers, int k, long size)
{
  int right = size, left = 0;
  while (1)
  {
    int mid = partition(numbers, left, right);
    if (mid == k) 
    {
      return numbers[mid];
    }
    else if (mid < k)
      left = mid + 1;
    else
      right = mid;
  }

  return -1;
}

int
median_filter(int* numbers, long window_size)
{
  if (window_size == 1) 
  {
    print_bin(numbers[0], 1);
    return 0;
  }

  int middle;
  if (window_size % 2 == 0)
  {
    middle = (window_size >> 1) - 1;
    print_bin((k_order(numbers, middle, window_size) 
          + k_order(numbers, middle + 1, window_size)) >> 1, window_size);
  }
  else
  {
    middle = window_size >> 1;
    print_bin(k_order(numbers, middle, window_size), window_size);
  }

  return 0;
}

