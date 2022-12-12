/* date = December 8th 2022 5:04 pm */

#ifndef _B_PLATFORM_H
#define _B_PLATFORM_H

#include "BDefines.h"

BTF_API void BInitializePlatform(wchar_t *WindowName);
BTF_API void BUpdatePlatform();

BTF_API void BPlatformConsoleWrite(char *Message, u8 Color);
BTF_API void *BPlatformAlloc(u64 Size);
BTF_API void BPlatformFree(void *Memory, u64 Size);

#endif //_B_PLATFORM_H
