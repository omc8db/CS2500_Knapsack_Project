#include "heapsort.h"
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void heapSort(T* array, int size)
{
	
	heapify(array, size);

	while((size - 1) > 0)
	{
		//Put the next largest element in the solution
		swap(array[size-1], array[0]);
		//Solution is array[size .. originial size]

		//Ensure the heap property is followed
		heapPropertyAdjust(array, 0, size-1);

		//Shrink the remaining maxtree
		size --;
	}
	//Postcondition: Array is sorted
	return;
}

template <typename T>
void buildheap(T* array, int size)
{
	return;
}

template <typename T>
void heapify(T* array, int size)
{
	for(int i = size/2; i>= 0; i--)
	{
		heapPropertyAdjust(array, i, size);
	}
	return;
}

template <typename T>
void heapPropertyAdjust(T* array, int index, int size)
{
	while( (index * 2 + 1) < size )
	{
		//Get the locations of the children
		int child_A = 2 * index + 1;
		int child_B = child_A + 1;
		int bigger_child;

		//Select the biggest child
		if((child_B < size) && array[child_B] > array[child_A])
		{
			bigger_child = child_B;
		} else
		{
			bigger_child = child_A;
		}

		// Check if the heap is out of order
		if(array[index] < array[bigger_child])
		{
			swap(array[index], array[bigger_child]);
			index = bigger_child;
		} else
		{
			return;
		}
	}

	return;
}

template <typename T>
void swap(T* left, T* right)
{
	T tmp;
	tmp  = *right;
	*right = *left;
	*left = *tmp;
	return;
}