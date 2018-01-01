#include "jump_totals.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int * list_jumptotals(char *argv[])
{
    srand((unsigned int)time(NULL));

    int option = atoi(argv[1]);
    int i;
    int j;
    float t;
    float rand_samp;
    int jump_path;
    float h;
    static int jump_totals_array[1000];
    static float time_of_jump[100];
    static int jump_total_at_time[100];
    int loop;

    /*a = atof(argv[1]);*/
    t = 1.0;
    h = .01;

    /* This is the number of Trajectories */
    for (j=0;j<1000;j++) {

      jump_path = 0;

      /* This is the movement along a single trajectory */
        for (i=0;i<100;i++) {

	  /* This takes the random sample at the i'th segment of a trajectory */
            rand_samp = ((float)rand()/(float)(RAND_MAX)) * t;

	    /* This tests the sample. If sample less than h, add one to the collection of jumps for the current trajectory */
	    if( rand_samp < h ) {
	      jump_path++;
	    }
	    time_of_jump[i] = (float)i*h;
	    jump_total_at_time[i] = jump_path;
	}

	/* Append the jump total for each trajectory to an array */
	jump_totals_array[j] = jump_path;
    }
    /*printf("%f\n", (float) jump_path/j);*/

    /* A for loop to print the list out, will need to direct this to output file */
    if( option == 1 ) {
      for(loop = 0; loop < 100; loop++) {
	printf("%f \t %d \n", time_of_jump[loop],jump_total_at_time[loop]);
      }
    }

    return jump_totals_array;
}
