#include "Logger.h"
#include "Platform.h"

#include <stdio.h>
#include <stdarg.h>

void _LogMessage(log_levels LogLevel, char *Format, ...)
{
    char *LevelStrings[6] =
    {
        "[FATAL]: ",
        "[ERROR]: ",
        "[WARN]: ",
        "[INFO]: ",
        "[DEBUG]: ",
        "[TRACE]: "
    };
    
    char Buffer[16384];
    
    va_list Args;
    va_start(Args, Format);
    s32 Written = vsnprintf(Buffer, 16384, Format, Args);
    va_end(Args);
    
    char OutBuffer[16384];
    Written = sprintf(OutBuffer, "%s%s\n", LevelStrings[LogLevel], Buffer);
    
    PlatformConsoleWrite(OutBuffer, LogLevel);
}