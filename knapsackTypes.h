#ifndef KNAPSACK_TYPES_H
#define KNAPSACK_TYPES_H

#include <vector>    //std::vector


struct knapsackItem
{
	int weight;
	int value;
};


struct knapsackResult
{
	int totalValue;
	std::vector<knapsackItem> solution_set;
};

#endif