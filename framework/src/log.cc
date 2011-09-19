/**
 * This file is in PUBLIC DOMAIN. You can use it freely. No guarantee.
 * Author: Fan Hongtao <fanhongtao@gmail.com>
 * Date: 2011-07-19
 */

#include "log.h"
#include <stdio.h>
#include <stdarg.h>

const int BUF_SIZE = 1024;

LOG_LEVEL g_log_level = DEBUG;

void set_log_level(LOG_LEVEL level) {
    g_log_level = level;
}

void write_log(LOG_LEVEL level, const char * tag, const char * file, int line, const char * fmt, ...) {
    if (level < g_log_level) return;

    char buff[BUF_SIZE];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buff, BUF_SIZE, fmt, args);
    va_end(args);

    printf("[%s:%d] %s, %s\n", file, line, tag,  buff);
}


void write_msg(LOG_LEVEL level, const char * fmt, ...) {
    if (level < g_log_level) return;

    char buff[BUF_SIZE];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buff, BUF_SIZE, fmt, args);
    va_end(args);

    printf("%s\n", buff);
}

