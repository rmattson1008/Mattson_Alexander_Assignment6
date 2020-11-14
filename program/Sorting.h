#ifndef _STYPE
#define _STYPE

#include "ItemType.h"

class Sorting {

public:
    int SelectionSort(ItemType * unsorted);
    int HeapSort(ItemType * unsorted);

    //recursive ones
    int MergeSort(ItemType * unsorted);
    int QuickSort_R(ItemType * unsorted);
    int QuickSort_FP(ItemType * unsorted);
};

#endif

// Sorting::SelectionSort(raw data)