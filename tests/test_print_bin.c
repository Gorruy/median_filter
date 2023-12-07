#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include <time.h>

#include "../src/median_filter.h"


int check(int cycle)
{
  srand(time(NULL));
  freopen("output_print_bin.txt", "a+", stdout);
  char buf[32];
  
  for (size_t i = 0; i < cycle; i++)
  {
    scanf("%s[ \n]", buf);
    int number = strtol(buf, NULL, 2);
    print_bin(number, 1);
  }

  return 0;
}

int main(int argc, char* argv[])
{
  check(atoi(argv[1]));
  printf("\n");
}
