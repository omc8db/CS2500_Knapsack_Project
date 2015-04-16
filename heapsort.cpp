#include "heapsort.h"
#include <iostream>
#include <vector>
#include "knapsack.h"
using namespace std;

void outputListOfKnapsackItems(knapsackItem* list, int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << "{W: " << list[i].weight << ", V:" << list[i].value << "} ";
	}
	cout << endl;
}


void HeapSort::heapsort(knapsackItem* array, int size)
{
	int i;
	knapsackItem temp;
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

void HeapSort::buildheap(knapsackItem* array, int size)
{
	for(int i=size/2; i>=1; i--)
	{
		heapify(array,i,size);
	}
	return;
}

void HeapSort::heapify(knapsackItem* array, int i, int size)
{
	int j;
	knapsackItem temp;
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

