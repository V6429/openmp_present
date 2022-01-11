
/**
 * Worksharing-----share a workload construct among threads
    * loop construct <----- divide a loop worked load onto threads
    * section construct
    * single construct 
    * task construct
    *
 */






// #pragma omp parallel 
// {
//     #pragma omp for
//     for(i=0;i<x,i++)
//     { code to be parallelized}
// } 
//************above short handed to************* 
//
// #pragma omp parallel for
// for(condition)
//  {code}






/**
 * HOW are the loops are mapped to threads 
 * ans: Scheduling
 * 
 * schedule(static [,optionalchunksize])  // breakup iterations to optionalchunksize ( 1 by default)
 *                                       // feed it to threads
 *                                       //--when amount of work is predermined or is predictable
 * 
 * schedule(dynamic [,optionalchunksize]) // put iteration into a task q
 *                                        // threads dynamically take chunks from the q @ runtime
 *                                        // blocks of optionalchunksize
 *                                        // no idea so dynamic for better balanced load
 *                      
 * 
 * schedule(guided [,optionalchunksize])
 * 
 * schedule(runtime)   // use env vars to specify schedule and chunksize
 *  
 * schedule(auto)     // let compiler decide 
 * 
 */




/**
 *
 * LOOP CARRIED DEPENDENCY
 *      can not run loop in parllel 
 * 
 *         SLIDE for REDUCTION
 * 
 * 
 */











#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

long num_steps = 10000000;
double step;



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