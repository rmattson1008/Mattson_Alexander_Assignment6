#ifndef HTYPE
#define HTYPE

#include "ItemType.h"

class Heap
{
public:
// incorrect headers
    void ReheapUp();
    void ReHeapDown();

private:
    ItemType * elements;
    int length;
};

#endif
