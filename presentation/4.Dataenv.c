

#include <omp.h>
#include <stdio.h>

int main()
{
    int  commonvalue=1234;
    int var1=1,
        var2=100,
        var3=3,
        var4=404;

    omp_set_num_threads(4);



#pragma omp parallel  private(var1) shared(var2) firstprivate(var3) //default(none)   
    {

        int ID = omp_get_thread_num();  // how do we move this out ? (this is ugly )
        printf("\nHello world from T-%d", ID);


        printf("\nT-%d says commonvalue=%d",ID,commonvalue);
        printf("\nT-%d says private var1=%d",ID,var1); //  this can spitout any garbage value or 0  
        printf("\nT-%d says shared var2=%d",ID,var2);
        printf("\nT-%d says firstprivate var3=%d ",ID,var3);


    }




 #pragma omp parallel for lastprivate(var4)
    for(int i = 0; i < omp_get_num_threads(); i++)
    {   
    
        
        if(omp_get_thread_num()==0)    // just stalling thread 0 only 
        for(int i =0;i<1000000000;i++);


        
        var4 = omp_get_thread_num()*i;
        printf("\nlastprivate var4=%d * %d ",omp_get_thread_num(),i);
    }
 
    printf("\nlastprivate var4=%d ",var4);

}
