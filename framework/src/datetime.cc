/**
 * This file is in PUBLIC DOMAIN. You can use it freely. No guarantee.
 * Author: Fan Hongtao <fanhongtao@gmail.com>
 * Date: 2011-07-19
 */

#include "datetime.h"

int MONTH_DAYS[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

CDateTime::CDateTime() {
    this->SetTime(time(NULL));
}

CDateTime::CDateTime(time_t time) {
    this->SetTime(time);
}

void CDateTime::SetTime(time_t time) {
    time_ = time;
    localtime_r(&time_, &tm_);
}

string CDateTime::ToString() const {
    char buff[32];
    sprintf(buff, "%04d-%02d-%02d %02d:%02d:%02d",
            Year(), Month(), Day(), Hour(), Minute(), Second());
    return buff;
}


ostream & operator<< (ostream & os, const CDateTime & dateTime) {
    os << dateTime.ToString();
    return os;
}


