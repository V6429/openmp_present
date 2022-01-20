

#include <omp.h>
#include <stdio.h>

int main()
{
    int commonvalue = 0;
    int sum = 0;


//// a common value among threads, sum  :: how can we take this out from stack to heap
#pragma omp parallel firstprivate(sum)
    {

    #pragma omp for
        for (int i = 0; i < 100; i++)
        {
            sum = sum + i;
        }

        printf("\n T-%d  has the value %5d for its private sum  ", omp_get_thread_num(), sum);

    #pragma omp critical
        commonvalue = commonvalue + sum;


    }




    printf("\nTotal value=%d",commonvalue);

    commonvalue=0;




    //////////////////////////////////// the neat way

    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < 100; i++)
        sum =sum + i;


    printf("\n\n\n Sum=%d\n",sum);

}
