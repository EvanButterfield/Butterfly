/* date = December 8th 2022 4:48 pm */

#ifndef _B_ENTRY_H
#define _B_ENTRY_H

#include "BDefines.h"
#include "Core/BLogger.h"
#include "Platform/BPlatform.h"

extern b32 InitApplication();
extern int RunApplication();

int main(int argc, char *argv)
{
    BInitializePlatform(L"Butterfly Engine");
    
    BASSERT(InitApplication(), "Application failed to initialize");
    
    int ErrorCode = 0;
    while(TRUE)
    {
        BUpdatePlatform();
        
        ErrorCode = RunApplication();
        if(ErrorCode != 0)
        {
            break;
        }
    }
    
    BINFO("Exited with code: %d", ErrorCode);
    return(ErrorCode);
}

#endif //_B_ENTRY_H
