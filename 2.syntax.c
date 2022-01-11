

#include <omp.h> 
#include <stdio.h>

int main()
{
    // omp_set_num_threads(2);

    #pragma omp parallel num_threads(2)
    { 
    int ID = omp_get_thread_num();
    printf("\n1-Hello world from T-%d", ID);
    printf("\n2-Hello world from T-%d", ID);


    }
}




