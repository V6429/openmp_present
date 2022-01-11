
// a talk on barriers , use one thread , use master thread & sections


/**
 * @file 5.Data env.c
 * 
 *  private   <--- create private copy inside stack & it goes away when outside
 *  shared
 *  firstprivate <--- 
 *  last private <--- create private copy inside stack & the last value is retained ( the last thread that used it taken out) 
 * 
 */







#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

long num_steps = 1000000000;
double step;

void main()
{
    double pi = 0.0, sum = 0.;
    double x=0.0;
    int nthreads;

    step = (1.0 - 0.0) / num_steps;

#pragma omp parallel  firstprivate(x) 
    {
      
#pragma omp for schedule(static, 2) reduction(+ : sum)
        for (int i = 0; i < num_steps; i++)
        {
            x = (i + 0.5) * step;
            sum = sum + 4.0 / (1.0 + x * x);
        }
#pragma omp nowait  // dont put a barrier here

#pragma omp single                          //  #pragma omp master
       {
           nthreads =omp_get_num_threads();// automatic implicit barrier here
         }
    }
    pi = sum * step;
    printf("Result=%f\n", pi);
    printf("used %d no.of threads for computation\n", nthreads);
}