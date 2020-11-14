
#include "ItemType.h"
#include "Heap.h"
#include "Sorting.h"
#include <exception>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <string>



int Sorting::MergeSort(ItemType  values[], int first, int last )		
//  Pre:   first <= last
//  Post: Array values[first..last] sorted into 
//    ascending order.
{
	if  ( first < last ) 	           //  general case
	{	
      int  middle = ( first  +  last ) / 2;
		MergeSort ( values, first,      middle );	
		MergeSort ( values, middle + 1, last   );

		// now  merge two subarrays
		// values [ first . . . middle ] with 
		// values [ middle + 1,  . . . last ].

		Merge(values,  first, middle, middle + 1, last);
	}           
}

void Sorting::Merge(ItemType values[], int leftFirst, int leftLast, int rightFirst, int rightLast){
    int index = leftFirst;
    int saveFirst = leftFirst;
    int length = sizeof(values)/sizeof(values[0]);
    ItemType * tempArray = new ItemType[length];

    while ((leftFirst <= leftLast) && (rightFirst <= rightLast)){
        if (values[leftFirst].compareTo(values[rightFirst]) == ItemType::LESS) {
            tempArray[index] = values[leftFirst];
            leftFirst++;
        } else {
            tempArray[index] = values[rightFirst];
            rightFirst++;
        }
        index++;
    }
    while ((leftFirst <= leftLast)){
        tempArray[index] = values[leftFirst];
        leftFirst++;
        index++;
    }
    while ((rightFirst <= rightLast)){
        tempArray[index] = values[rightFirst];
        rightFirst++;
        index++;
    }
    for (index = saveFirst; index <= rightLast; index++){
        values[index] = tempArray[index];
    }
}