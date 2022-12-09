/* date = December 8th 2022 4:50 pm */

#ifndef _CORE_H
#define _CORE_H

//NOTE(evan): WE ARE GOING TO ASSUME MSVC ON WINDOWS
//            THIS IS VERY IMPORTANT
#ifdef BTF_PLATFORM_WINDOWS
#    include <Windows.h>
#    include <intrin.h>

#define DebugBreak() __debugbreak()

#    ifdef BTF_ENGINE
#        define BTF_API __declspec(dllexport)
#    elif BTF_APP
#        define BTF_API __declspec(dllimport)
#    endif
#else
#    error Butterfly only supports Windows!
#endif

#define BASSERT(X, Message) \
{ \
if(X) \
{ \
} \
else \
{ \
BFATAL("%s: Assertion failed in file: %s on line: %d", Message, __FILE__, __LINE__); \
DebugBreak(); \
}\
}

#include <stdint.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

typedef float f32;

typedef s32 b32;
#define TRUE  1
#define FALSE 0

#endif //_CORE_H
