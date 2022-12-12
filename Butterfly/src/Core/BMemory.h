/* date = December 10th 2022 0:07 pm */

#ifndef _B_MEMORY_H
#define _B_MEMORY_H

#include "BDefines.h"

typedef enum btf_mem_types
{
    MEM_TYPE_UNKNOWN,
    MEM_TYPE_STRING,
    
    MEM_TYPE_COUNT
} btf_mem_types;

BTF_API void *BAlloc(btf_mem_types Type, u64 Size);
BTF_API void BFree(btf_mem_types Type, void *Memory, u64 Size);
BTF_API void BPrintMemUsage(void);

#endif //_B_MEMORY_H
