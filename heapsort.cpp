#include "heapsort.h"
#include <iostream>
#include <vector>
using namespace std;

void heapSort(knapsackItem* array, int size)
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

void heapify(knapsackItem* array, int size)
{
	for(int i = size/2; i>= 0; i--)
	{
		heapPropertyAdjust(array, i, size);
	}
	return;
}

void heapPropertyAdjust(knapsackItem* array, int index, int size)
{
	while( (index * 2 + 1) < size )
	{
		//Get the locations of the children
		int child_A = 2 * index + 1;
		int child_B = child_A + 1;
		int smaller_child;

		//Select the biggest child
		if((child_B < size) && array[child_B] < array[child_A])
		{
			smaller_child = child_B;
		} else
		{
			smaller_child = child_A;
		}

		// Check if the heap is out of order
		if(array[index] > array[smaller_child])
		{
			swap(array[index], array[smaller_child]);
			index = smaller_child;
		} else
		{
			return;
		}
	}

	return;
}

void swap(knapsackItem* left, knapsackItem* right)
{
	knapsackItem tmp;
	tmp.value  = right->value;
	tmp.weight = right->weight;

	right->value = left->value;
	right->weight = left->weight;

	left->value = tmp.value;
	left->weight = tmp.weight;
	return;
}