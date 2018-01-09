#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main(int argc, char *argv[])
{

  int loop;
  FILE *myFile;
  int jump_totals[1000];

  /* Get the output data containing the list of trajectory jump totals */
  myFile = fopen("experimental_output.txt", "r");

  /* Build the jump_totals array from file */
  for (loop = 0; loop < 1000; loop++) {
    fscanf(myFile, "%d", &jump_totals[loop]);
  }

  /* for (loop = 0; loop < 1000; loop++) {
    printf("Number is: %d\n\n", jump_totals[loop]);
    }*/
 
  fclose(myFile);

  double prob_theory;
  int k;
  int total_jump_equalk;
  total_jump_equalk = 0;
  k = 2;

  /* Find all trajectories with jump total equal to k */
  /* If the jump total is equal to k, increment a count by 1 */
  for (loop = 0; loop < 1000; loop++) {
    if ( jump_totals[loop] == k ) {
      total_jump_equalk++;
    }
  }

  printf("The experimental probability for finding a trajectory with %d jumps is %f\n", k, ((float) total_jump_equalk / 1000));

  /* A function for factorial calculation */
  int long long factorial_fun(int  n)
  {
    int i;
    unsigned long long factorial;

    factorial = 1;
   
    for(i=1; i<=n; ++i)
      {
            factorial *= i;              
      }
    return factorial;
  }

  
  /* Calculate the theoretical probaility of a jump total being equal to k on the entire interval */
  /* lambda = 1, t = 1, s = 0 */
  prob_theory = 1.0 / ( exp(1.0) * (double) factorial_fun( k ) );

  printf("The theoretical probability for finding a trajectory with %d jumps is %f\n", k, prob_theory);

  return 0;

}
