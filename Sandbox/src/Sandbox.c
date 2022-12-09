#include <Butterfly.h>

int RunApplication(void *PlatformData)
{
    BTRACE("Initialized Application");
    
    while(TRUE)
    {
        UpdatePlatform();
    }
}