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


template <typename T>
void heapSort(T* array, int size);

template <typename T>
void buildheap(T* array, int size);

template <typename T>
void heapify(T* array, int size);


template <typename T>
void heapPropertyAdjust(T* array, int index, int size);

//In place swap
template <typename T>
void swap(T* left, T* right);

#endif
