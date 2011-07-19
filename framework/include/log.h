/**
 * This file is in PUBLIC DOMAIN. You can use it freely. No guarantee.
 * Author: Fan Hongtao <fanhongtao@gmail.com>
 * Date: 2011-07-13
 */

#ifndef LOG_H
#define LOG_H

enum LOG_LEVEL{
    TRACE,
    DEBUG,
    INFO,
    WARN,
    ERROR,
    FATAL
};

#ifndef LOG_TAG
#define LOG_TAG "NULL"
#endif

#define LOG(level, ...) write_log(level, LOG_TAG, __FILE__, __LINE__, __VA_ARGS__)
#define LOGT(...)  LOG(TRACE, __VA_ARGS__)
#define LOGD(...)  LOG(DEBUG, __VA_ARGS__)
#define LOGI(...)  LOG(INFO, __VA_ARGS__)
#define LOGW(...)  LOG(WARN, __VA_ARGS__)
#define LOGE(...)  LOG(ERROR, __VA_ARGS__)
#define LOGF(...)  LOG(FATAL, __VA_ARGS__)


#define LOG_MSG(level, ...) write_msg(level, __VA_ARGS__)
#define LOGT_MSG(...)  LOG_MSG(TRACE, __VA_ARGS__)
#define LOGD_MSG(...)  LOG_MSG(DEBUG, __VA_ARGS__)
#define LOGI_MSG(...)  LOG_MSG(INFO, __VA_ARGS__)
#define LOGW_MSG(...)  LOG_MSG(WARN, __VA_ARGS__)
#define LOGE_MSG(...)  LOG_MSG(ERROR, __VA_ARGS__)
#define LOGF_MSG(...)  LOG_MSG(FATAL, __VA_ARGS__)


void set_log_level(LOG_LEVEL level);

void write_log(LOG_LEVEL level, char * tag, char * file, int line, char * fmt, ...);

void write_msg(LOG_LEVEL level, char * fmt, ...);

#endif // LOG_H
