#include <Butterfly.h>

int RunApplication()
{
    PlatformConsoleWrite("This is a test!", 3);
    
    while(TRUE)
    {
        UpdatePlatform();
    }
}