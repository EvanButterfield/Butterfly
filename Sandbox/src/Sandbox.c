#include <Butterfly.h>

static b32 Initialized;

b32 InitApplication()
{
    void *Thing = BAlloc(MEM_TYPE_STRING, Gibibytes(1));
    BPrintMemUsage();
    BFree(MEM_TYPE_STRING, Thing, Gibibytes(1));
    BPrintMemUsage();
    
    BTRACE("Initialized Application");
    return(TRUE);
}

int RunApplication()
{
    return(0);
}
