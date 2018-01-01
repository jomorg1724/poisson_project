#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>

int main()
{
  FILE *fp;
  int myInt = 5;
  fp = fopen("Output.txt", "w");/*"w" means that we are going to write on this file*/
  fprintf(fp, "This is being written in the file. This is an int variable: %d", myInt);
  return 0;
}
