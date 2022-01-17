

#include <omp.h>
#include <stdio.h>

int taskprinter(int taskCreaterID);

int main()
{
    int  T_ID;

#pragma omp parallel private(T_ID)
    {
        T_ID = omp_get_thread_num(); // individual ids for each thread

        #pragma omp task
        taskprinter(T_ID);          // each thread will create a task
        #pragma omp barrier        // synchnorizing threads to ensure all task till here are completed




        // a more common methord: where a  single thread will create all the tasks
        #pragma omp single 
        {
            printf("\n\nT-%d is creating a lot of tasks\n", T_ID);
            for (int i = 0; i < 50; i++)
            {
            #pragma omp task 
                    taskprinter(T_ID);
            } // system will do load balancing of the work

        } // remember single has an implied barrier
    }
}








int taskprinter(int taskCreaterID)
{

    int taskExecuter = omp_get_thread_num(); // just to make this point clear
                                             // task creater and executer can be different

    for (int i = 0; i < (100000 * (taskCreaterID+1)); i++); // just stalling to create a delay


    printf("\nThis was a task CREATED by T-%d and is EXECUTED BY T-%d", taskCreaterID, taskExecuter);
}