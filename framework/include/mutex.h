/**
 * This file is in PUBLIC DOMAIN. You can use it freely. No guarantee.
 * Author: Fan Hongtao <fanhongtao@gmail.com>
 * Date: 2011-07-01
 */

#ifndef MUTEX_H
#define MUTEX_H

#include <pthread.h>

/**
 * GNU/Linux provides mutexes, short for MUTual EXclusion locks. A mutex is a special lock 
 * that only one thread may lock at a time. If a thread locks a mutex and then a second
 * thread also tries to lock the same mutex, the second thread is blocked, or put on hold.
 * Only when the first thread unlocks the mutex is the second thread unblocked -- allowed
 * to resume execution. GNU/Linux guarantees that race conditions do not occur among threads
 * attempting to lock a mutex; only one thread will ever get the lock, and all other threads 
 * will be blocked.
 */
class CMutex {
public:
    CMutex() {
        pthread_mutex_init(&mutex_, NULL);
    }

    ~CMutex() {
        pthread_mutex_destroy(&mutex_);
    }

    int Lock() {
        return pthread_mutex_lock(&mutex_);
    }

    int UnLock() {
        return pthread_mutex_unlock(&mutex_);
    }

    pthread_mutex_t & mutex() {
        return mutex_;
    }

private:
    pthread_mutex_t mutex_;
};


class CMutexGuard {
public:
    CMutexGuard(CMutex& mutex):mutex_(mutex) {
        mutex_.Lock();
    }

    ~CMutexGuard() {
        mutex_.UnLock();
    }

private:
    CMutex mutex_;
};

#endif // MUTEX_H
