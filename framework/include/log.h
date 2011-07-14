/**
 * This file is in PUBLIC DOMAIN. You can use it freely. No guarantee.
 * Author: Fan Hongtao <fanhongtao@gmail.com>
 * Date: 2011-07-13
 */

#ifndef LOG_H
#define LOG_H

#include <stdio.h>

#ifdef TRACE
#define LOG_T(...)  do { printf(__VA_ARGS__); printf("\n"); } while(0)
#else
#define LOG_T(...)
#endif

#define LOG_D(...)  do { printf(__VA_ARGS__); printf("\n"); } while(0)

#endif // MUTEX_H
