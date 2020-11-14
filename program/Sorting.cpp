
#include "ItemType.h"
#include "Heap.h"
#include "Sorting.h"
#include <exception>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <string>



int Sorting::MergeSort(ItemType  values[], int first, int last, int MAX_LENGTH )		
//  Pre:   first <= last
//  Post: Array values[first..last] sorted into 
//    ascending order.
{
    // cout << "Entered MergeSort" << endl;
	if  ( first < last ) 	           //  general case
	{	
      int  middle = ( first  +  last ) / 2;
		MergeSort ( values, first,middle, MAX_LENGTH);	
		MergeSort ( values, middle + 1, last, MAX_LENGTH);

		Merge(values,  first, middle, middle + 1, last, MAX_LENGTH);
	}           
}

void Sorting::Merge(ItemType values[], int leftFirst, int leftLast, int rightFirst, int rightLast, int MAX_LENGTH){
    int index = leftFirst;
    int saveFirst = leftFirst;
    // cout << "Array length " << length <<  endl;
    ItemType tempArray[MAX_LENGTH];

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
/*
void QuickSort( ItemType  values[ ], int first, int last )	
	
//  Pre:   first <= last
//  Post: Sorts array values[ first .  . last ] into ascending order
{
	if  ( first < last ) 	         //  general case
	{	
     int  splitPoint ;
	   Split( values, first, last, splitPoint ) ;	
	   // values [first]..values[splitPoint - 1] <= splitVal
	   // values  [splitPoint] = splitVal
	   // values [splitPoint + 1]..values[last] > splitVal
	   QuickSort(values,  first,  splitPoint - 1);
	   QuickSort(values,  splitPoint + 1,  last);
	}          
} ;
*/

