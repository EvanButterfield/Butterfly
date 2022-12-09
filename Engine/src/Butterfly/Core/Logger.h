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

BTF_API void _LogMessage(log_levels LogLevel, char *Prefix, char *Format, ...);

#ifdef BTF_ENGINE
#    define BFATAL(Format, ...) \
_LogMessage(LOG_LEVEL_FATAL, "[Engine]: ", Format, ##__VA_ARGS__)
#    define BERROR(Format, ...) \
_LogMessage(LOG_LEVEL_ERROR, "[Engine]: ", Format, ##__VA_ARGS__)
#    define BWARN(Format, ...) \
_LogMessage(LOG_LEVEL_WARN, "[Engine]: ", Format, ##__VA_ARGS__)
#    define BINFO(Format, ...) \
_LogMessage(LOG_LEVEL_INFO, "[Engine]: ", Format, ##__VA_ARGS__)
#    define BDEBUG(Format, ...) \
_LogMessage(LOG_LEVEL_DEBUG, "[Engine]: ", Format, ##__VA_ARGS__)
#    define BTRACE(Format, ...) \
_LogMessage(LOG_LEVEL_TRACE, "[Engine]: ", Format, ##__VA_ARGS__)
#elif BTF_APP
#    define BFATAL(Format, ...) \
_LogMessage(LOG_LEVEL_FATAL, "[App]:    ", Format, ##__VA_ARGS__)
#    define BERROR(Format, ...) \
_LogMessage(LOG_LEVEL_ERROR, "[App]:    ", Format, ##__VA_ARGS__)
#    define BWARN(Format, ...) \
_LogMessage(LOG_LEVEL_WARN, "[App]:    ", Format, ##__VA_ARGS__)
#    define BINFO(Format, ...) \
_LogMessage(LOG_LEVEL_INFO, "[App]:    ", Format, ##__VA_ARGS__)
#    define BDEBUG(Format, ...) \
_LogMessage(LOG_LEVEL_DEBUG, "[App]:    ", Format, ##__VA_ARGS__)
#    define BTRACE(Format, ...) \
_LogMessage(LOG_LEVEL_TRACE, "[App]:    ", Format, ##__VA_ARGS__)
#endif

#endif //_LOGGER_H
