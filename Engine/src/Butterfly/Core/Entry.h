/* date = December 8th 2022 4:48 pm */

#ifndef _ENTRY_H
#define _ENTRY_H

#include "Core.h"
#include "Platform/Platform.h"

extern int RunApplication(void *PlatformData);

int main()
{
    void *PlatformData = InitializePlatform(L"Butterfly Engine");
    
    int ErrorCode = RunApplication(PlatformData);
    
    return(ErrorCode);
}

#endif //_ENTRY_H
