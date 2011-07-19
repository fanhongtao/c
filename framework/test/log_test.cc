/*
 * This file is used to test log
 *      g++ -I../include -g -o log_test log_test.cc ../src/log.cc
 *
 * Author: Fan Hongtao <fanhongtao@gmail.com>
 * Date: 2011-07-19
 */
#define LOG_TAG "LOG_TEST"

#include "log.h"
#include <iostream>

int main (int argc, char *argv[])
{
    LOGT("trace %d", 1);
    LOGD("debug %d", 2);
    LOGD_MSG("\tThis is a message");
    LOGD("debug no arg");

    set_log_level(INFO);

    LOGD("debug, should not display");
    LOGW("warning");

    return 0;
}

