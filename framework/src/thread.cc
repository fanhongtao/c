/**
 * This file is in PUBLIC DOMAIN. You can use it freely. No guarantee.
 * Author: Fan Hongtao <fanhongtao@gmail.com>
 * Date: 2011-07-14
 */

#include "thread.h"
#include "log.h"

void * thread_loop(void * p) {
    CThread * thread = (CThread*)p;
    thread->Run();
}

CThread::CThread() : thread_attr_(NULL), stop(false) {
};

CThread::CThread(pthread_attr_t * attr_) : thread_attr_(attr_), stop(false) {
};

CThread::CThread(string & name, pthread_attr_t * attr_) : thread_attr_(attr_), thread_name_(name), stop(false) {
};

CThread::~CThread() {
}

void CThread::Start() {
    pthread_create(&thread_handle_, thread_attr_, thread_loop, (void*)this);
}

bool CThread::isStop() {
    CMutexGuard guard(thread_mutex_);
    return stop;
}

void CThread::Stop() {
    CMutexGuard guard(thread_mutex_);
    stop = true;
}

