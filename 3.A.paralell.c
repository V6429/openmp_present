
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

long num_steps = 100000000;
double step;

#define NUMOF_THREADS 4

void main()
{
    int i, nthreads;
    double pi = 0.0;
    double sum[NUMOF_THREADS]; //  this is now an array (1.e for each thread)
    step = (1.0 - 0.0) / num_steps;

#pragma omp parallel // hey compiler, use threads on the following block ( not being specific so env variable)
    {

        int i;
        int thread_id, nthreads_at_thread_stack;
        double x;

        //////////////////new stuff here////////////////////////////////////////////////////////

        thread_id = omp_get_thread_num();
        nthreads_at_thread_stack = omp_get_num_threads();

        if (thread_id == 0)                      // the 0th thread
            nthreads = nthreads_at_thread_stack; // if main thread, save this value to heap 
                                                 // we need this info for further  processing
                                                 // the env can choose to give lower no of threads

        ////////////////////////////////////////////////////////////////////////////

        // // this loop simply computes the sum(s) on each thread ( heights of each slices)
        for (i = thread_id, sum[thread_id] = 0; i < num_steps; i = i + nthreads)
        {
            x = (i + 0.5) * step;
            sum[thread_id] = sum[thread_id] + 4.0 / (1.0 + x * x);
        }
    }

    for (i = 0; i < nthreads; i++)
        pi = pi + sum[i] * step; // taking the sums

    printf("\nResult=%f\n", pi);
    printf("used %d no.of threads for computation\n",nthreads);
}


// this  code has an issue of false sharing
// padding -- depending on size of cache promote the array again to avoid this
// too much work