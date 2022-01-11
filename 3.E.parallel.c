
// a talk on barriers , use one thread , use master thread & sections

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

long num_steps = 1000000000;
double step;

void main()
{
    double pi = 0.0, sum = 0.0;
    int nthreads;

    step = (1.0 - 0.0) / num_steps;

#pragma omp parallel
    {
        int nthreads_at_thread_stack;
        double x = 0.0;

#pragma omp for schedule(static, 2) reduction(+ : sum)
        for (int i = 0; i < num_steps; i++)
        {
            x = (i + 0.5) * step;
            sum = sum + 4.0 / (1.0 + x * x);
        }
#pragma omp nowait  // dont put a barrier here

#pragma omp single                          //  #pragma omp master
       { nthreads_at_thread_stack=omp_get_num_threads();
        nthreads = nthreads_at_thread_stack;}   
                                            // automatic implicit barrier here
    }

    pi = sum * step;
    printf("Result=%f\n", pi);
    printf("used %d no.of threads for computation\n", nthreads);
}