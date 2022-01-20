

#include <omp.h>
#include <stdio.h>

int taskprinter(int taskCreaterID);

int main()
{
    int  Thread_ID;

#pragma omp parallel private(Thread_ID)
    {
        Thread_ID = omp_get_thread_num(); // individual ids for each thread

        #pragma omp task
        taskprinter(Thread_ID+100);          // each thread will create a task
        #pragma omp barrier        // synchnorizing threads to ensure all task till here are completed




        // a more common methord: where a  single thread will create all the tasks
        #pragma omp single 
        {
            
            printf("\n\nT-%d is creating a lot of tasks\n", Thread_ID);
            for (int i = 0; i < 50; i++)
            {
            #pragma omp task 
                    taskprinter(Thread_ID);
            }                                     // system will do load balancing of the task work


        } // remember single has an implied barrier
    }






}






int taskprinter(int taskCreaterID)
{

    int taskExecuterID = omp_get_thread_num(); // just to make this point clear
                                             // task creater and executer can be different

    for (int i = 0; i < (100000 * (taskCreaterID+1)); i++); // just stalling to create a delay


    printf("\nThis was a task CREATED by T-%d and is EXECUTED BY T-%d", taskCreaterID, taskExecuterID);
}