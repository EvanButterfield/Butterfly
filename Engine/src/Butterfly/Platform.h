/* date = December 8th 2022 5:04 pm */

#ifndef _PLATFORM_H
#define _PLATFORM_H

#include "Core.h"

BTF_API void *InitializePlatform(wchar_t *WindowName);
BTF_API void UpdatePlatform();

BTF_API void PlatformConsoleWrite(char *Message, u8 Color);

#endif //_PLATFORM_H
