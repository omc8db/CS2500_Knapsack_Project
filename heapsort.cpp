#include "heapsort.h"
#include <iostream>


void HeapSort::heapsort(int* array, int size)
{
	int temp;
	buildheap(array, size);
	//Precondition:array(size+1...i) is in a heap
	//Invariant:array(0...size) is in a heap and array(size...i) is sorted
	//Assert(testSorted(array, end+1, count))
	for(int i=size; i>1; i--)
	{
		temp=array[i];
		array[i]=array[1];
		array[1]=temp;
		heapify(array, 1, i-1);
	}
	//Invariant:array(0...size) is in a heap
	//Assert(testSorted(array, size, i))
	//Postcondition:array(1...i) is sorted
	return;
}

void HeapSort::buildheap(int* array, int size)
{
	for(int i=size/2; i>=1; i--)
	{
		heapify(array,i,size);
	}
	return;
}

void HeapSort::heapify(int* array, int i, int size)
{
	int j, temp;
	temp=array[i];
	j=2*i;
	while(j<=size)
	{
		if(j<size && array[j+1]>array[j])
		{
			j++;
		}
		if (temp>array[j])
		{
			break;
		}
		else if(temp<=array[j])
		{
			array[j/2]=array[j];
			j=j*2;
		}
	}
	array[j/2]=temp;
	return;
}

