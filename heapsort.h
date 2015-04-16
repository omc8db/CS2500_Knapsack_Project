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
#include <assert.h>
#include "knapsack_types.h"


void heapSort(knapsackItem* array, int size);

void heapify(knapsackItem* array, int size);

void heapPropertyAdjust(knapsackItem* array, int index, int size);

//In place swap
void swap(knapsackItem* left, knapsackItem* right);

#endif
