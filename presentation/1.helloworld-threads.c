

#include <omp.h>  // any types and function prototypes available with openmp
#include <stdio.h>

int main()
{

    // omp_set_num_threads(2);

    #pragma omp parallel // HEY compiler !! use threads (how many threads ?? ans:Default )
    { //ANY CODE HERE IS EXECUTED BY A TEAM OF THREADS

    // int ID = 0;       // 
    int ID = omp_get_thread_num(); // runtimelibraryroutine  to get unique id for each thread
    printf("\n1-Hello world from T-%d", ID);
    printf("\n2-Hello world from T-%d", ID);

    }
}



//#pragma instructs compiler to do a specific task
//////////////////////////////////////////////////////////
/**
 * 
 * HOW to compile ON linux
 * gcc -fopenmp  helloworld.c
 * 
 * export OMP_NUM_THREADS=4   // or in win  SET OMP_NUM_THREADS=4
 */
