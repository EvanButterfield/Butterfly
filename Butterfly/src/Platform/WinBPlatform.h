/* date = December 8th 2022 6:49 pm */

#ifndef _WIN_B_PLATFORM_H
#define _WIN_B_PLATFORM_H

#include "BDefines.h"
#include "Core/BMemory.h"

typedef struct btf_win_state
{
    HINSTANCE Instance;
    HWND Window;
} btf_win_state;

#endif //_WIN_B_PLATFORM_H
