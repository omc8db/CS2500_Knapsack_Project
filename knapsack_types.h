#ifndef KNAPSACK_TYPES
#define KNAPSACK_TYPES

#include <vector>

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


//Compares knapsack items by the greedy criteria
bool operator <(const knapsackItem& lhs, const knapsackItem& rhs);
bool operator >(const knapsackItem& lhs, const knapsackItem& rhs);
bool operator <=(const knapsackItem& lhs, const knapsackItem& rhs);
bool operator >=(const knapsackItem& lhs, const knapsackItem& rhs);

#endif