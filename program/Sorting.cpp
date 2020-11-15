
#include "ItemType.h"
#include "Heap.h"
#include "Sorting.h"
#include <exception>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <string>
#include <cstdlib>

// counting will be alot easier if we instantiate an object
Sorting::Sorting(int size){
    MAX_LENGTH = size;
    g_count = 0;
}


//This recursively pushes the count back up, doesn't use global variable tracker
// sorts the array we pass in
int Sorting::MergeSort(ItemType  values[], int first, int last, int MAX_LENGTH)		
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
        g_count++;
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
int Sorting::QuickSort_R(ItemType values[ ], int first, int last )	
	
//  Pre:   first <= last
//  Post: Sorts array values[ first .  . last ] into ascending order
{
    // cout << "entered quick" << endl;
    // int count = 0;
	if  ( first < last ) 	         //  general case
	{	
        int splitPoint = SplitRandomly(values, first, last);

	   QuickSort_R(values,  first,  splitPoint - 1);
	   QuickSort_R(values,  splitPoint + 1,  last);
	}    
    return 0;      
} 

// TODO cite geeksforgeeks
int Sorting::QuickSort_FP(ItemType values[ ], int first, int last )	
	
//  Pre:   first <= last
//  Post: Sorts array values[ first .  . last ] into ascending order
{
    // cout << "entered quick" << endl;
    int count = 0;
	if  ( first < last ) 	         //  general case
	{	
        int splitPoint = Split(values, first, last);

	   count += QuickSort_FP(values,  first,  splitPoint - 1);
	   count += QuickSort_FP(values,  splitPoint + 1,  last);
	}    
    return count;      
} 

int Sorting::Split(ItemType values[], int first, int last) {
    ItemType piv = values[last];
    int i = first - 1;

    for (int j = first; j <= last - 1; j++)  
    {    
        g_count++;
        if (values[j].compareTo(piv) == ItemType::LESS)  
        {  
            i++;  
            swap(&values[i], &values[j]);  
        }  
    }  
    swap(&values[i + 1], &values[last]);  
    return (i + 1); 
}

int Sorting::SplitRandomly(ItemType values[], int first, int last) {
    int randomIndex = first + rand() % (last - first);
    cout << "Random Pivot index: " << randomIndex << endl;
    ItemType piv = values[randomIndex];
    int i = first - 1;
    // g_count++;

    for (int j = first; j <= last - 1; j++)  
    {  
          
        g_count++;
        if (values[j].compareTo(piv) == ItemType::LESS)  
        {  
            i++;  
            swap(&values[randomIndex], &values[last]);
        }  
    }  
    swap(&values[randomIndex], &values[last]);  
    return (i + 1); 
}

int Sorting::getComparisons() {
    return g_count;
}

void Sorting::resetComparisons() {
    g_count = 0;
    return;
}

void Sorting::swap(ItemType * a, ItemType* b)  
{  
    ItemType t = *a;   
    *a = *b;  
    *b = t;  
} 

