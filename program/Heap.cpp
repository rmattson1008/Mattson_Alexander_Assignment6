#include "Heap.h"
#include "ItemType.h"
#include <iostream>
#include <ostream>
#include <algorithm>
using namespace std;

void Heap::ReheapDown(int root, int bottom) {
  int maxChild;
  int rightChild;
  int leftChild;

  leftChild = root * 2 + 1;
  rightChild = root * 2 + 2;
  if (leftChild <= bottom) {
    if (leftChild == bottom){
      maxChild = leftChild;

    }
    else
      {
        if (elements[leftChild].compareTo(elements [rightChild]) == (ItemType::LESS || ItemType::GREATER)) // <= elements [rightChild])
          maxChild = rightChild;

        else
          maxChild = leftChild;
      }
    if (elements [root].compareTo(elements[maxChild]) == ItemType::LESS) { // < elements [maxChild]) {
      swap(elements [root], elements [maxChild]);
      ReheapDown(maxChild, bottom);
      hCount++;
    }
  }
}

void Heap::ReheapUp ( int  root,  int  bottom )

//  Pre:  bottom is the index of the node that may violate the heap
//  order property.  The order property is satisfied from root to
//  next-to-last node.
//  Post:  Heap order property is restored between root and bottom

{
    int  parent ;

    if  ( bottom  > root )
    {
        parent = ( bottom - 1 ) / 2;
        if ( elements [ parent ].compareTo(elements[bottom]) == ItemType:: LESS)//  <  elements [ bottom ] )
        {
           swap ( elements [ parent ], elements [ bottom ] );
           ReheapUp ( root, parent );
           hCount++;
        }
    }
}

