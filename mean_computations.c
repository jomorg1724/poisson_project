#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(int argc, char *argv[])
{
  int i;
  int loop;
  int sum;
  float u;
  FILE *myFile;
  int jump_totals[1000];
  float mean_list[100];
  /* int mean_list_at_interval[100];*/
  char buf[32];

  for (i = 1; i < 101; i++) {

    /* pass a buffer to the system function */
    /* call the jump_total function i_max amount of times */
    /* i will be passed as the endpoint for the poisson interval */
    sprintf(buf, "./jump_totals 0 %d", i);
    system(buf);

    /* jump_total called with 0; outputs a text file*/
    /* text file contains a 1000 different trajectory jump counts*/
    /* jump counts are all calculated using i as endpoint*/
    myFile = fopen("experimental_output.txt", "r");
    for (loop = 0; loop < 1000; loop++) {
      fscanf(myFile, "%d", &jump_totals[loop]);
    }
    fclose(myFile);

    /* set sum to 0 before every iteration */
    /* sum up all the trajectory jump totals */
    sum = 0;
    for (loop = 0; loop < 1000; loop++) {
      sum = sum + jump_totals[loop];
    }

    /* set mean to 0*/
    /* divide by 1000 because that is the hardcoded number of trajectories*/
    /* use an array to collect the i_max amount of means */
    u = 0;
    u = (float) sum / 1000;
    mean_list[i] = u;
  }

  /* output the list of means to a file */
  FILE *f = fopen("mean_list_output.txt", "wb");

  for(loop = 1; loop < 101; loop++) {
    /* fprintf(f,"%f ", mean_list[loop]);*/
    fprintf(f,"%d \t %f \n", loop, mean_list[loop]);
  }

  fclose(f);


  return 0;
}
