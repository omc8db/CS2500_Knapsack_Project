#include "knapsack_types.h"

bool operator <(const knapsackItem& lhs, const knapsackItem& rhs)
{
	float lhsVal = lhs.value;
	lhsVal = lhsVal / lhs.weight;
	float rhsVal = rhs.value;
	rhsVal = rhsVal / rhs.weight;

	return (lhsVal < rhsVal);
}

bool operator >(const knapsackItem& lhs, const knapsackItem& rhs)
{
	float lhsVal = lhs.value;
	lhsVal = lhsVal / lhs.weight;
	float rhsVal = rhs.value;
	rhsVal = rhsVal / rhs.weight;

	return (lhsVal > rhsVal);
}

bool operator <=(const knapsackItem& lhs, const knapsackItem& rhs)
{
	float lhsVal = lhs.value;
	lhsVal = lhsVal / lhs.weight;
	float rhsVal = rhs.value;
	rhsVal = rhsVal / rhs.weight;

	return (lhsVal > rhsVal);
}

bool operator >=(const knapsackItem& lhs, const knapsackItem& rhs)
{
	float lhsVal = lhs.value;
	lhsVal = lhsVal / lhs.weight;
	float rhsVal = rhs.value;
	rhsVal = rhsVal / rhs.weight;

	return (lhsVal > rhsVal);
}