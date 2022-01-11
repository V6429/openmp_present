/**
 * Synchnorisation of threads to control race conditions aka the hazards
 * 1) barrier -- all threads stop at the barrier
 * 2) mutual exclusion -- 1 thread at a time
 *
 */

/**
 *  openmp constructs availale
 * 
 * High level:
    *  Critical   #pragma omp Critical // a thread pauses here until all threads reach here
    *  Atomic                          // atomic update operations makes use of h/w support
    *  Barrier
    *  Ordered
 * Low level:
    * Flush
    * LOCKS
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

long num_steps = 10000000;
double step;

#define NUMOF_THREADS 4

void main()
{
    int nthreads;
    double pi = 0.0;
    double totalsum = 0.0; // we are going to take sum(s) from individual thread stack to shared heap
    step = (1.0 - 0.0) / num_steps;

#pragma omp parallel
    {

        int i = 0;
        int thread_id, nthreads_at_thread_stack;
        double x = 0.0;
        double sum = 0.0; // each thread have its own sum

        thread_id = omp_get_thread_num();
        nthreads_at_thread_stack = omp_get_num_threads();

        if (thread_id == 0)
            nthreads = nthreads_at_thread_stack;

        ////////////////////////////////////////////////////////////////////////////

        for (i = thread_id; i < num_steps; i = i + nthreads_at_thread_stack)
        {
            x = (i + 0.5) * step;
            for (int x = 0; x < 1000; x++)
                ;
            sum = sum + 4.0 / (1.0 + x * x);
        }

        printf("Sum=%f \n", sum);
#pragma omp barrier // waiting for all threads to complete (so as to print individual sums neatly)

#pragma omp Critical // hey threads, execute the following ONE AT A TIME!!! stop causing race conditions
        {
            printf("Total sum = %f = %f +%f \n", totalsum + sum, totalsum, sum);
            totalsum = totalsum + sum;
        }
    }

    pi = totalsum * step;

    printf("\nResult=%f\n", pi);
    printf("used %d no.of threads for computation\n", nthreads);
}