#include "Logger.h"
#include "Platform/Platform.h"

#include <stdio.h>
#include <stdarg.h>

void _LogMessage(log_levels LogLevel, char *Prefix, char *Format, ...)
{
    char *LevelStrings[6] =
    {
        "[FATAL]: ",
        "[ERROR]: ",
        "[WARN]:  ",
        "[INFO]:  ",
        "[DEBUG]: ",
        "[TRACE]: "
    };
    
    char Buffer[16384];
    
    va_list Args;
    va_start(Args, Format);
    vsnprintf(Buffer, 16384, Format, Args);
    va_end(Args);
    
    char OutBuffer[16384];
    sprintf(OutBuffer, "%s%s", LevelStrings[LogLevel], Buffer);
    
    char OutBuffer2[16384];
    sprintf(OutBuffer2, "%s%s\n", Prefix, OutBuffer);
    
    PlatformConsoleWrite(OutBuffer2, LogLevel);
}