#ifndef _STYPE
#define _STYPE

#include "ItemType.h"

class Sorting {

public:
    Sorting(int size);
    int SelectionSort(ItemType * unsorted);
    int HeapSort(ItemType * unsorted);

    //recursive ones
    int MergeSort(ItemType * unsorted,  int first, int last, int MAX_LENGTH);
    // int QuickSort_R(ItemType * unsorted);
    int QuickSort_R(ItemType values[ ], int first, int last);
    int QuickSort_FP( ItemType  values[ ], int first, int last);	
    

    int Split(ItemType values[], int first, int last);
    int SplitRandomly(ItemType values[], int first, int last);
    void swap(ItemType* a, ItemType* b);  
    int Merge(ItemType values[], int leftFirst, int leftLast, int rightFirst, int rightLast, int MAX_LENGTH);
    
    void resetComparisons();
    int getComparisons();
    int g_count;
    int MAX_LENGTH;
};

#endif

// Sorting::SelectionSort(raw data)