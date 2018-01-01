#include "jump_totals.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  int loop;
  int j;
  int *jumptotals;

  jumptotals = list_jumptotals();
  j = 1000;
  for(loop = 0; loop < j; loop++)
  printf("%d ", jumptotals[loop]);
  return 0;
}
