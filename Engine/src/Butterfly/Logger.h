/* date = December 8th 2022 7:44 pm */

#ifndef _LOGGER_H
#define _LOGGER_H

#include "Core.h"

typedef enum log_levels
{
    LOG_LEVEL_FATAL,
    LOG_LEVEL_ERROR,
    LOG_LEVEL_WARN,
    LOG_LEVEL_INFO,
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_TRACE
} log_levels;

BTF_API void _LogMessage(log_levels LogLevel, char *Format, ...);

#define BFATAL(Format, ...) _LogMessage(LOG_LEVEL_FATAL, Format, ##__VA_ARGS__)
#define BERROR(Format, ...) _LogMessage(LOG_LEVEL_ERROR, Format, ##__VA_ARGS__)
#define BWARN(Format, ...) _LogMessage(LOG_LEVEL_WARN, Format, ##__VA_ARGS__)
#define BINFO(Format, ...) _LogMessage(LOG_LEVEL_INFO, Format, ##__VA_ARGS__)
#define BDEBUG(Format, ...) _LogMessage(LOG_LEVEL_DEBUG, Format, ##__VA_ARGS__)
#define BTRACE(Format, ...) _LogMessage(LOG_LEVEL_TRACE, Format, ##__VA_ARGS__)

#endif //_LOGGER_H
