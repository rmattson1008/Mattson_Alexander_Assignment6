
#include "ItemType.h"
#include "Heap.h"
#include "Sorting.h"
#include <exception>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <string>



int Sorting::MergeSort(ItemType  values[], int first, int last, int MAX_LENGTH)		
//  Pre:   first <= last
//  Post: Array values[first..last] sorted into 
//    ascending order.
{
    int count = 0;
    // cout << count << endl;
    // cout << "Entered MergeSort" << endl;
	if  ( first < last ) 	           //  general case
	{	
        int  middle = ( first  +  last ) / 2;
		count += MergeSort( values, first , middle, MAX_LENGTH);	
		count += MergeSort( values, middle + 1, last, MAX_LENGTH);
        count += Merge(values, first, middle, middle + 1, last, MAX_LENGTH);
		// return count;
	}           
    return count;
}
// 1501
int Sorting::Merge(ItemType values[], int leftFirst, int leftLast, int rightFirst, int rightLast, int MAX_LENGTH){
    int index = leftFirst;
    int saveFirst = leftFirst;
    int count = 0;
    // cout << "Array length " << length <<  endl;
    ItemType tempArray[MAX_LENGTH];

    while ((leftFirst <= leftLast) && (rightFirst <= rightLast)){
        // cout << "making a comparison" << endl;
        count++;
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
    for (index = saveFirst; index <= rightLast; index++) {
        values[index] = tempArray[index];
    }
    // cout << "went through " << MAX_LENGTH << endl;
    // cout << "count is " << count << endl;;
    return count;
}
// TODO cite geeksforgeeks

void Sorting::QuickSort_FP(ItemType values[ ], int first, int last )	
	
//  Pre:   first <= last
//  Post: Sorts array values[ first .  . last ] into ascending order
{
    cout << "entered quick" << endl;
	if  ( first < last ) 	         //  general case
	{	
        int splitPoint = Split(values, first, last);
	//    Split(values, first, last, splitPoint ) ;	
	   // values [first]..values[splitPoint - 1] <= splitVal
	   // values  [splitPoint] = splitVal
	   // values [splitPoint + 1]..values[last] > splitVal
	   QuickSort_FP(values,  first,  splitPoint - 1);
	   QuickSort_FP(values,  splitPoint + 1,  last);
	}          
} 
int Sorting::Split(ItemType values[], int first, int last) {
    ItemType piv = values[last];
    int i = first - 1;

    for (int j = first; j <= last - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (values[j].compareTo(piv) == ItemType::LESS)  
        {  
            i++; // increment index of smaller element  
            swap(&values[i], &values[j]);  
        }  
    }  
    swap(&values[i + 1], &values[last]);  
    return (i + 1); 
}

void Sorting::swap(ItemType * a, ItemType* b)  
{  
    ItemType t = *a;   
    *a = *b;  
    *b = t;  
} 

