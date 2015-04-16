#ifndef KNAPSACK_H
#define KNAPSACK_H

#include "heapsort.h"
#include <vector>    //std::vector
#include <algorithm> //std::max
#include <iostream>

using namespace std;

struct knapsackItem
{
	int weight;
	int value;
};


struct knapsackResult
{
	int totalValue;
	vector<knapsackItem> solution_set;
};

// Solves the knapsack problem using a greedy algorithm
// pre: input is a list of values and weights that gets sorted into knapsack of the specified capacity
// post: 
knapsackResult greedyKnapsackSolve(const vector<knapsackItem>& input, int capcity);

knapsackResult dynamicKnapsackSolve(const vector<knapsackItem>& input, int capacity);


bool operator>(knapsackItem lhs, knapsackItem rhs);

bool operator<(knapsackItem lhs, knapsackItem rhs);


#endif
