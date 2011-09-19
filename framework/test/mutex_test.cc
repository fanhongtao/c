#include "gtest/gtest.h"
#include "synchronization.h"

/**
 * Test if guard works well
 */
TEST(Mutex, none) {
    CMutex mutex;
    CMutexGuard guard(mutex);
}

/**
 * Test if we can unlock the mutex manully.
 * Which will result unlock the mutex twice.
 */
TEST(Mutex, unlock_manual) {
    CMutex mutex;
    CMutexGuard guard(mutex);
    mutex.UnLock(); // unlock manual
}

/**
 * Test if we can unlock the mutex, and lock it again.
 */
TEST(Mutex, unlock_lock_manual) {
    CMutex mutex;
    CMutexGuard guard(mutex);
    mutex.UnLock(); // unlock manual
    mutex.Lock();   // lock again manual
}
