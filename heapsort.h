/*
 * heapsort.h
 *
 * author: Owen Chiaventone
 *
 * Driver for comparison of MergeSort and
 * HeapSort
 *
 */

#ifndef HEAPSORT_H
#define HEAPSORT_H
#include <vector>

#include <assert.h>

template <typename T>
class HeapSort
{
public:
	//This function will do the sorting of the heap array passed to it
	//Pre:none
	//Post:The heap array passed to it will be sorted
  void heapsort(std::vector<T>& array, int size);
  //This function will turn the array passed to it into a heap
  //Pre:none
  //Post:the array passed to it will be arranged in a heap
  void buildheap(std::vector<T>& array, int size);
  //This function will move around nodes in the heap to sort it 
  //Pre:none
  //Post:The heap at that root will be sorted
  void heapify(std::vector<T>& array, int i, int size);

private:
};


#endif
