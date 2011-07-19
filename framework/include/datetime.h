/**
 * This file is in PUBLIC DOMAIN. You can use it freely. No guarantee.
 * Author: Fan Hongtao <fanhongtao@gmail.com>
 * Date: 2011-07-19
 */

#ifndef DATE_TIME_H
#define DATE_TIME_H

#include <time.h>

#include <string>
using std::string;

#include <iostream>
using std::ostream;

class CDateTime
{
public:
    CDateTime();
    CDateTime(long seconds);
    void SetTime(long seconds);

    inline int Year()   const { return tm_.tm_year + 1900; }
    inline int Month()  const { return tm_.tm_mon + 1; }
    inline int Day()    const { return tm_.tm_mday; }
    inline int Hour()   const { return tm_.tm_hour; }
    inline int Minute() const { return tm_.tm_min; }
    inline int Second() const { return tm_.tm_sec; }

    string ToString() const;

    friend ostream & operator<< (ostream & os, const CDateTime & dateTime);

private:
    time_t time_;
    struct tm  tm_;

private:
    static int MONTH_DAYS[13];
};

#endif // DATE_TIME_H
