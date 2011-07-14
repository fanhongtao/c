/**
 * This file is in PUBLIC DOMAIN. You can use it freely. No guarantee.
 * Author: Fan Hongtao <fanhongtao@gmail.com>
 * Date: 2011-07-14
 */

#ifndef CTHREAD_H
#define CTHREAD_H

#include "synchronization.h"
#include <pthread.h>

#include <string>
using std::string;

/* This is a mimic class of Java Thread */
class CThread {
public:
    friend void * thread_loop(void * p);

    CThread();
    CThread(pthread_attr_t * attr);
    CThread(string & name, pthread_attr_t * attr);

    virtual ~CThread();

    virtual void Run() = 0;

    void Start();
    void Stop();
    bool isStop();

    pthread_t & thread_handle() { return thread_handle_; }

private:
    pthread_t       thread_handle_;
    pthread_attr_t* thread_attr_;
    string          thread_name_;
    CMutex          thread_mutex_;
    bool            stop;
};

#endif // CTHREAD_H
