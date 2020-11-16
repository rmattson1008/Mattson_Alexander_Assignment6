#ifndef HTYPE
#define HTYPE

#include "ItemType.h"

class Heap
{
  struct HeapType {
    void ReheapDown(int root, int bottom);
    void ReheapUp(int root, int bottom);
    ItemType * elements;
    int numElements;
  };
public:
  // incorrect headers
  void ReheapUp(int root, int bottom);
  void ReheapDown(int root, int bottom);


private:
  ItemType * elements;
  int length;
  int hCount = 0;
};

#endif
