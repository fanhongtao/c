/*
 * This file is a variant of demoes/thread/condition_demo.c
 * The original copy is from https://computing.llnl.gov/tutorials/pthreads/
 * Use the fellowing command to compile:
 *      g++ -lpthread -I../include -g -o condition_test condition_test.c
 *
 * Example Code - Using Condition Variables
 *
 * This simple example code demonstrates the use of several Pthread condition variable routines.
 * The main routine creates three threads. Two of the threads perform work and update a "count"
 * variable. The third thread waits until the count variable reaches a specified value.
 */
#include "mutex.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

#define NUM_THREADS  3
#define TCOUNT 10
#define COUNT_LIMIT 12

int     count = 0;
int     thread_ids[3] = {0,1,2};

CCondition condition;

void *inc_count(void *t)
{
    int i;
    long my_id = (long)t;

    for (i=0; i<TCOUNT; i++) {
        /* Do some "work" so threads can alternate on mutex lock */
        sleep(1);

        CMutexGuard guard(condition.mutex());
        count++;

        /*
           Check the value of count and signal waiting thread when condition is
           reached.  Note that this occurs while mutex is locked.
           */
        if (count == COUNT_LIMIT) {
            condition.Signal();
            printf("inc_count(): thread %ld, count = %d  Threshold reached.\n",
                    my_id, count);
        }
        printf("inc_count(): thread %ld, count = %d, unlocking mutex\n",
                my_id, count);
    }
    pthread_exit(NULL);
}

void *watch_count(void *t)
{
    long my_id = (long)t;

    printf("Starting watch_count(): thread %ld\n", my_id);

    /*
       Lock mutex and wait for signal.  Note that the pthread_cond_wait
       routine will automatically and atomically unlock mutex while it waits.
       Also, note that if COUNT_LIMIT is reached before this routine is run by
       the waiting thread, the loop will be skipped to prevent pthread_cond_wait
       from never returning.
       */
    CMutexGuard gurad(condition.mutex());
    while (count<COUNT_LIMIT) {
        condition.Wait();
        printf("watch_count(): thread %ld Condition signal received.\n", my_id);
        count += 125;
        printf("watch_count(): thread %ld count now = %d.\n", my_id, count);
    }
    printf(".................\n");

    /*
     * Note: Beacuse pthread_exit() does not release resources.
     *     So here we use the implicit call to pthread_exit().
     *
     *  If call pthread_exit(), We MUST unlock the mutex manully before call pthread_exit()!
     * */
    // condition.mutex().UnLock();
    // pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
    int i, rc;
    long t1=1, t2=2, t3=3;
    pthread_t threads[3];
    pthread_attr_t attr;

    /* For portability, explicitly create threads in a joinable state */
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    pthread_create(&threads[0], &attr, watch_count, (void *)t1);
    pthread_create(&threads[1], &attr, inc_count, (void *)t2);
    pthread_create(&threads[2], &attr, inc_count, (void *)t3);

    /* Wait for all threads to complete */
    for (i=0; i<NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    printf ("Main(): Waited on %d  threads. Done.\n", NUM_THREADS);

    /* Clean up and exit */
    pthread_attr_destroy(&attr);
    pthread_exit(NULL);

    return 0;
}

