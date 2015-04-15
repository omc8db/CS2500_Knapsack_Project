#include "knapsack.h"

knapsackResult greedyKnapsackSolve(const vector<knapsackItem>& input, int capcity)
{
	knapsackResult result;
	
	return result;
}

knapsackResult dynamicKnapsackSolve(const vector<knapsackItem>& input, int capacity)
{
	knapsackResult result;
	
	//Allocate table
	int **table = new int*[input.size()+1]; // add an extra row for 0s
	for(int i = 0; i < input.size()+1; i++)
	{
		table[i] = new int[capacity+1];
	}

	//Initialize first row and column to 0
	for(int i = 0; i <= input.size(); i++)
	{
		table[i][0] = 0;
	}
	for(int j = 0; j <= capacity; j++)
	{
		table[0][j] = 0;
	}

	//Fill out the table
	for(int i = 1; i <= input.size(); i++)
	{
		for(int j = 1; j <= capacity; j++)
		{
			if(j < input[i].weight)
			{
				table[i][j] = table[i-1][j];
			} else 
			{
				table[i][j] = max(
					  (table[i-1][j-input[i].weight] + table[i][j-1])
					, table[i-1][j]
					);
			}

		}
	}

	//Deallocate table
	for(int i = 0; i < input.size(); i++)
	{
		delete[] table[i];
	}
	delete[] table;
	return result;
}
