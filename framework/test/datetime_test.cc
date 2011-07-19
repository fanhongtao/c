/*
 * This file is used to test CDateTime
 *      g++ -I../include -g -o datetime_test datetime_test.cc ../src/datetime.cc
 *
 * Author: Fan Hongtao <fanhongtao@gmail.com>
 * Date: 2011-07-19
 */

#include "datetime.h"
#include <iostream>
using std::cout;
using std::endl;

int main (int argc, char *argv[])
{
    CDateTime dt1;
    cout << dt1 << endl;

    return 0;
}

