#ifndef _STYPE
#define _STYPE

#include "ItemType.h"

class Sorting {

public:
    int SelectionSort(ItemType * unsorted);
    int HeapSort(ItemType * unsorted);

    //recursive ones
    int MergeSort(ItemType * unsorted,  int first, int last);
    int QuickSort_R(ItemType * unsorted);
    int QuickSort_FP(ItemType * unsorted);
    void Merge(ItemType values[], int leftFirst, int leftLast, int rightFirst, int rightLast)
};

#endif

// Sorting::SelectionSort(raw data)