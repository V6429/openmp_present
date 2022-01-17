

#include <omp.h>
#include <stdio.h>

int main()
{
    int commonvalue = 0;
    int var1 = 1,
        var2 = 100,
        var3 = 3,
        sum = 0;


//// a common value among threads, sum  :: how can we take it out
#pragma omp parallel firstprivate(sum)
    {

#pragma omp for
        for (int i = 0; i < 100; i++)
        {
            sum = sum + i;
        }
        printf("\n T-%d  has the value %d for its private sum  ", omp_get_thread_num(), sum);

#pragma omp critical
        commonvalue = commonvalue + sum;
    }


    printf("\nTotal value=%d",commonvalue);

    commonvalue=0;




//////////////////////////////////// the neat way

#pragma omp parallel for reduction(+:sum)
 for (int i = 0; i < 100; i++)
    sum =sum + i;

printf("\n\n\nTotal value=%d\n",sum);

}
