



#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

long num_steps = 1000000000;
double step;


// everything related to threads,passing variables back etc is hidden

void main()
{
    double pi = 0.0,sum=0.0,nthreads;
    step = (1.0 - 0.0) / num_steps;

#pragma omp parallel
    {

        double x = 0.0;
                                                                            // for schedule(staticaly_during_compile,chunks_of_2_iterations) to rip apart the for loop & feed it to the threads
        #pragma omp for schedule (static,2) reduction(+:sum)                // reduction takes care of the dependency between threads
        for (int i = 0; i < num_steps; i++)                                 // Basically > give each threads its own copy of sum
        {                                                                   //           > at the end use + operaror beween the copys
            x = (i + 0.5) * step;                                           // !!try different schedulings
            sum = sum + 4.0 / (1.0 + x * x);
        }
        // there is a default barrier here automatically added by openmp use "nowait" to  remove this if required 



        // #pragma omp master      #pragma omp single
        // nthreads = nthreads_at_thread_stack;
        //                         #pragma omp nowait
    }

    pi = sum * step;
    printf("Result=%f\n", pi);
    // printf("used %d no.of threads for computation\n", nthreads);
}