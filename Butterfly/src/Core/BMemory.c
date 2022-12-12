#include "BMemory.h"
#include "Platform/BPlatform.h"
#include "Core/BLogger.h"

typedef struct mem_stats
{
    u64 TotalAllocated;
    u64 TypeAllocated[MEM_TYPE_COUNT];
} mem_stats;
static mem_stats MemoryStats;

const char *MemTypeStrings[MEM_TYPE_COUNT] =
{
    "[Memory Type Unknown]",
    "[Memory Type String] "
};

void *BAlloc(btf_mem_types Type, u64 Size)
{
    if(Type == MEM_TYPE_UNKNOWN)
    {
        BWARN("\"BAlloc\" called with \"MEM_TYPE_UNKNOWN\", please re-type this");
    }
    
    MemoryStats.TotalAllocated += Size;
    MemoryStats.TypeAllocated[Type] += Size;
    
    void *Memory = BPlatformAlloc(Size);
    return Memory;
}

void BFree(btf_mem_types Type, void *Memory, u64 Size)
{
    if(Type == MEM_TYPE_UNKNOWN)
    {
        BWARN("\"BFree\" called with \"MEM_TYPE_UNKNOWN\", please re-type this");
    }
    
    MemoryStats.TotalAllocated -= Size;
    MemoryStats.TypeAllocated[Type] -= Size;
    
    BPlatformFree(Memory, Size);
}

void BPrintMemUsage(void)
{
    BDEBUG("Total Memory Allocated: %lu bytes", MemoryStats.TotalAllocated);
    for(int TypeIndex = 0;
        TypeIndex < MEM_TYPE_COUNT;
        ++TypeIndex)
    {
        BDEBUG("Total Memory Allocated for %s is %lu bytes", MemTypeStrings[TypeIndex], MemoryStats.TypeAllocated[TypeIndex]);
    }
}
