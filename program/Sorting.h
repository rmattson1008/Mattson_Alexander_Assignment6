#ifndef _STYPE
#define _STYPE

#include "ItemType.h"

class Sorting {

public:
    Sorting(int size);
    // Deconstructor- only thing to delete is data array created in main
    int MinIndex(ItemType values[], int start, int end);
  int SelectionSort(ItemType values[], int numValues);
  int HeapSort(ItemType * unsorted);


    //recursive ones
    int MergeSort(ItemType * unsorted,  int first, int last);
    // int QuickSort_R(ItemType * unsorted);
    int QuickSort_R(ItemType values[ ], int first, int last);
    int QuickSort_FP( ItemType  values[ ], int first, int last);	
    

    int Split(ItemType values[], int first, int last);
    int SplitRandomly(ItemType values[], int first, int last);
    void swap(ItemType* a, ItemType* b);  
    int Merge(ItemType values[], int leftFirst, int leftLast, int rightFirst, int rightLast);
    
    void resetComparisons();
    int getComparisons();
    int g_count;
    int MAX_LENGTH;
    
};

#endif

// Sorting::SelectionSort(raw data)
