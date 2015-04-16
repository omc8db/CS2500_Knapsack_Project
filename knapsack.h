#ifndef KNAPSACK_H
#define KNAPSACK_H

#include "heapsort.h"
#include "knapsack_types.h"
#include <vector>    //std::vector
#include <algorithm> //std::max
#include <iostream>

using namespace std;

// Solves the knapsack problem using a greedy algorithm
// pre: input is a list of values and weights that gets sorted into knapsack of the specified capacity
// post: 
knapsackResult greedyKnapsackSolve(const vector<knapsackItem>& input, int capacity);

knapsackResult dynamicKnapsackSolve(const vector<knapsackItem>& input, int capacity);

#endif
