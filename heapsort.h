/*
 * heapsort.h
 *
 * author: Alex Shamroe
 *
 * Driver for comparison of MergeSort and
 * HeapSort
 *
 */

#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <assert.h>

class HeapSort
{
public:
	//This function will do the sorting of the heap array passed to it
	//Pre:none
	//Post:The heap array passed to it will be sorted
  void heapsort(int* array, int size);
  //This function will turn the array passed to it into a heap
  //Pre:none
  //Post:the array passed to it will be arranged in a heap
  void buildheap( int* array, int size);
  //This function will move around nodes in the heap to sort it 
  //Pre:none
  //Post:The heap at that root will be sorted
  void heapify(int* array, int i, int size);

private:
};


#endif
