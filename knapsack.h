#ifndef KNAPSACK_H
#define KNAPSACK_H


#include "knapsack_types.h"
#include <vector>    //std::vector
#include <algorithm> //std::max
#include <iostream>
#include "heapsort.h"

using namespace std;

// Solves the knapsack problem using a greedy algorithm
// pre: input is a list of values and weights that gets sorted into knapsack of the specified capacity
// post: 
knapsackResult greedyKnapsackSolve(const vector<knapsackItem>& input, int capacity);

knapsackResult dynamicKnapsackSolve(const vector<knapsackItem>& input, int capacity);

void outputTable(int** table, int items, int capacity);

#endif
