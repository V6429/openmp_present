

#include <omp.h>
#include <stdio.h>

int main()
{
    int commonvalue = 0;
    int var1 = 1,
        var2 = 100,
        var3 = 3,
        sum = 0;


///////////////////// a simple for loop handled by threads 
#pragma omp parallel for
    for (int i = 0; i < 20; i++)
    {
        printf("\n Iteration %d is done by T%d ", i, omp_get_thread_num());
    }




#pragma omp parallel for schedule(static,2) // asking every thread to take a batch of 2 iteration at a time for processing
    for (int i = 0; i < 20; i++)
    {
        printf("\n BATCHED Iteration %d is done by T%d ", i, omp_get_thread_num());
    }



}
