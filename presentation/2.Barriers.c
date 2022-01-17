

#include <omp.h>
#include <stdio.h>

int main()
{

#pragma omp parallel
    {

        int ID = omp_get_thread_num(); // runtimelibraryroutine  to get unique id for each thread
        printf("\nHello world from T-%d", ID);

        for (int i = 0; i < (100000000 / (ID + 1)); i++); // puuting the threads in seperate no of iterations
        for (int i = 0; i < (100000000 / (ID + 1)); i++); // insane no of times
        for (int i = 0; i < (100000000 / (ID + 1)); i++);
        for (int i = 0; i < (100000000 / (ID + 1)); i++);
        for (int i = 0; i < (100000000 / (ID + 1)); i++);
        for (int i = 0; i < (100000000 / (ID + 1)); i++);
        for (int i = 0; i < (100000000 / (ID + 1)); i++);
        for (int i = 0; i < (100000000 / (ID + 1)); i++);
        for (int i = 0; i < (100000000 / (ID + 1)); i++);
        for (int i = 0; i < (100000000 / (ID + 1)); i++);
        for (int i = 0; i < (100000000 / (ID + 1)); i++);
        for (int i = 0; i < (100000000 / (ID + 1)); i++);
        for (int i = 0; i < (100000000 / (ID + 1)); i++);
        for (int i = 0; i < (100000000 / (ID + 1)); i++);

        printf("\n\tT-%d has completed the loops", ID);
       

#pragma omp barrier
        printf("\n T-%d is over the barrier", ID);
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
