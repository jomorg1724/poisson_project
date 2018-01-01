#include "jump_totals.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int option = atoi(argv[1]);
  int loop;
  int j;
  int *jumptotals;

  if(option != 0 || option != 1) {
      printf("Must enter either 1 or 0\n");
      printf("1 for single trajectory path\n");
      printf("0 for total jumps of several paths\n");
    }

  jumptotals = list_jumptotals(argv);
  j = 1000;

  if ( option == 0 ) {
    for(loop = 0; loop < j; loop++)
      printf("%d ", jumptotals[loop]);
  }
  return 0;
}
