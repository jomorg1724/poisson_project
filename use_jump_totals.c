#include "jump_totals.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{


  bool isNumber(char number[])
  {
    int i = 0;

    /*checking for negative numbers*/
    if (number[0] == '-')
        i = 1;
    for (; number[i] != 0; i++)
      {
        /*if (number[i] > '9' || number[i] < '0')*/
        if (!isdigit(number[i]))
	  return false;
      }
    return true;
  }


  if ( isNumber(argv[1]) ) {
  }
  else {
    printf("Must enter either 1 or 0\n");
    exit(-1);
  }



 
  int option = atoi(argv[1]);


  /* Tests whether user only gave exacly one input with function call */
  if( argc != 2) {
    fprintf(stderr, "Number of arguments jump_totals takes is precisely 1\n");
    exit(-1);
  }


  /* Tests whether user input was 1 or 0 */
  if(option != 0 && option != 1) {
    printf("Must enter either 1 or 0\n");
    printf("1 for single trajectory path\n");
    printf("0 for total jumps of several paths\n");
    exit(-1);
  }


  int loop;
  int j;
  int *jumptotals;

  jumptotals = list_jumptotals(argv);
  j = 1000;

  if ( option == 0 ) {
    for(loop = 0; loop < j; loop++) {
      printf("%d", jumptotals[loop]);
    }

    /*Cannot use this easily in gnuplot, use column method. This works well for C scripts though*/
    FILE *f = fopen("client.data", "wb");
    fwrite(jumptotals, sizeof(int), sizeof(jumptotals), f);
    fclose(f);
    printf("\n");
  }

    /*FILE *ifp = fopen("client.data", "rb"); fread(jumptotals, sizeof(int), sizeof(jumptotals), ifp);
    for(loop = 0; loop < j; loop++)
    printf("%d", jumptotals[loop]);
    }*/

  return 0;
}
