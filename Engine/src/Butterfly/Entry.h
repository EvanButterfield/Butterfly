/* date = December 8th 2022 4:48 pm */

#ifndef _ENTRY_H
#define _ENTRY_H

#include "Core.h"
#include "Platform.h"

extern int RunApplication();

int main()
{
    void *PlatformData = InitializePlatform(L"Butterfly Engine");
    
    int ErrorCode = RunApplication();
    
    return(ErrorCode);
}

#endif //_ENTRY_H
