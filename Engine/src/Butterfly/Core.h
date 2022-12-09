/* date = December 8th 2022 4:50 pm */

#ifndef _CORE_H
#define _CORE_H

#ifdef BTF_PLATFORM_WINDOWS
#    include <Windows.h>

#    ifdef BTF_ENGINE
#        define BTF_API __declspec(dllexport)
#    elif BTF_SANDBOX
#        define BTF_API __declspec(dllimport)
#    endif
#else
#    error Butterfly only supports Windows!
#endif

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
