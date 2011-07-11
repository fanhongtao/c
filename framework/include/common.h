/**
 * This file is in PUBLIC DOMAIN. You can use it freely. No guarantee.
 * Author: Fan Hongtao <fanhongtao@gmail.com>
 * Date: 2011-07-11
 */

#ifndef COMMON_H
#define COMMON_H

#define DELETE(ptr) \
    do { \
        if (ptr != NULL) { \
            delete ptr; \
            ptr = NULL; \
        } \
    } while (0)

#define DELETE_A(ptr) \
    do { \
        if (ptr != NULL) { \
            delete [] ptr; \
            ptr = NULL; \
        } \
    } while (0)

#endif // COMMOH_H
