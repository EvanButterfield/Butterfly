/* date = December 8th 2022 6:49 pm */

#ifndef _WIN_PLATFORM_H
#define _WIN_PLATFORM_H

#include "Core/Core.h"

#include <Windows.h>

typedef struct win_state
{
    HINSTANCE Instance;
    HWND Window;
} win_state;

#endif //_WIN_PLATFORM_H
