/**
 * @file 4.locks.c
 * 
 * Locks are the lowest level of mutual exclusion avialable in multithreaded
 * 
 * basically if a thread holds lock it can update the variable 
 * else it has to wait for that lock to be available
 * 
 */


/**
 * omp.h 
 * 
 * lock_t  <----- the lock type avialble under the header
 * 
 * omp_init_lock() <---- initialize a lock
 * omp_set_lock()  <----- if the thread wants to hold the lock
 *                  if an other thread is using the lock, the thread that uses 
 *                  this function will SIT AND WAIT!!! for the lock to be available
 * omp_unset_lock() <---- give the lock back so other threads can use it
 * omp_destroy_lock <---- remove the lock
 * 
 * omp_test_lock() <------check if the lock is available
 *                        use this with setlock to minimize waittime
 *
 * 
 * 
 * 
 * omp_get_num_threads()<---------- get the number of threads in the region
 * omp_get_max_threads() <----- max threads the system will give to the program
 *  
 * 
 * omp_in_parallel()  <---- check whether code execution is in a parallel region
 * 
 * omp_set_dynamic()
 * omp_get_dynamic()
 * 
 */