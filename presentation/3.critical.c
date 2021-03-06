

#include <omp.h>
#include <stdio.h>

int main()
{
    int  commonvalue=0;                                     // a value shared by all threads

#pragma omp parallel  
    {

        int ID = omp_get_thread_num();                     // runtimelibraryroutine  to get unique id for each thread
        printf("\nHello world from T-%d", ID);

        for(int j=0;j<6;j++)
        for (int i = 0; i < (100000000 / (ID + 1)); i++); // puuting the threads in seperate no of iterations
         // insane no of times
         
        printf("\n\tT-%d has completed the loops", ID);
       

    #pragma omp critical
        {   
            printf("\n T-%d is at the ****critical***** section", ID);
            for (int j = 0; j < 10 ; j++)
            for (int i = 0; i < (100000000 / (ID + 1)); i++);

            commonvalue +=ID;                                       // a  simple example of sharing a variable across threads
            printf("\n T-%d is exiting the ***critical*** section", ID);
            
        }
    
    }

    printf("\nCommonvalue=%d",commonvalue);
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
