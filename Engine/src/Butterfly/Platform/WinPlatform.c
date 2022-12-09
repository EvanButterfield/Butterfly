#ifdef BTF_PLATFORM_WINDOWS

#include "Platform.h"
#include "WinPlatform.h"
#include "Core/Logger.h"

static LRESULT CALLBACK
Win32WindowProc(HWND Window,
                UINT Message,
                WPARAM WParam,
                LPARAM LParam)
{
    LRESULT Result = 0;
    
    switch(Message)
    {
        default:
        {
            Result = DefWindowProc(Window, Message, WParam, LParam);
        } break;
    }
    
    return(Result);
}

void *InitializePlatform(wchar_t *WindowName)
{
    win_state *State = VirtualAlloc(0, sizeof(win_state), MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);
    State->Instance = GetModuleHandle(0);
    
    WNDCLASSW WindowClass = {0};
    WindowClass.style = CS_HREDRAW|CS_VREDRAW;
    WindowClass.lpfnWndProc = Win32WindowProc;
    WindowClass.hInstance = State->Instance;
    WindowClass.hCursor = LoadCursorW(0, IDC_ARROW);
    WindowClass.lpszClassName = L"ButterflyWindowClass";
    
    BASSERT(RegisterClassW(&WindowClass), "Failed to Register Window Class");
    
    State->Window = CreateWindowW(WindowClass.lpszClassName, WindowName,
                                  WS_OVERLAPPEDWINDOW|WS_VISIBLE,
                                  CW_USEDEFAULT, CW_USEDEFAULT,
                                  CW_USEDEFAULT, CW_USEDEFAULT,
                                  0, 0, State->Instance, 0);
    BASSERT(State->Window, "Failed to Create Window");
    
    BTRACE("Initialized Platform");
    
    return State;
}

void UpdatePlatform()
{
    MSG Message;
    while(PeekMessageA(&Message, 0, 0, 0, PM_REMOVE))
    {
        TranslateMessage(&Message);
        DispatchMessageA(&Message);
    }
}

void PlatformConsoleWrite(char *Message, u8 Color)
{
    HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
    
    u8 Levels[6] = {64, 4, 6, 2, 1, 8};
    SetConsoleTextAttribute(Console, Levels[Color]);
    
    OutputDebugStringA(Message);
    DWORD Length = (DWORD)strlen(Message);
    WriteConsoleA(Console, Message, Length, 0, 0);
}

#endif