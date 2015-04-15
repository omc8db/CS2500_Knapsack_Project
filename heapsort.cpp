#include "heapsort.h"
#include <iostream>
#include <vector>
using namespace std;


template <typename T>
void HeapSort<T>::heapsort(vector<T>& array, int size)
{
	int i;
	T temp;
	buildheap(array, size);
	for(int i=size; i>1; i--)
	{
		temp=array[i];
		array[i]=array[1];
		array[1]=temp;
		heapify(array, 1, i-1);
	}
	return;
}

template <typename T>
void HeapSort<T>::buildheap(vector<T>& array, int size)
{
	for(int i=size/2; i>=1; i--)
	{
		heapify(array,i,size);
	}
	return;
}

template <typename T>
void HeapSort<T>::heapify(vector<T>& array, int i, int size)
{
	int j;
	T temp;
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
		else if (temp<=array[j])
		{
			array[j/2]=array[j];
			j=j*2;
		}
	}
	array[j/2]=temp;

	return;
}

