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
			if(j < input[i-1].weight)
			{
				table[i][j] = table[i-1][j];
			} else 
			{
				table[i][j] = max(
					  (table[i-1][j-input[i-1].weight] + input[i-1].value)
					, table[i-1][j]
					);

			}

		}
	}

	//Calculate results
	result.totalValue = table[input.size()][capacity];

	int current_item = input.size(); //Start at last entry in table
	int current_weight = capacity;
	while(current_weight > 0)
	{
		//Find when this item was added
		while(table[current_item][current_weight] == table[current_item-1][current_weight])
		{
			current_item --;
		}
		while(table[current_item][current_weight] == table[current_item][current_weight-1])
		{
			current_weight--;
		}

		//Subtract 1 from the current item because vectors start at 0
		result.solution_set.push_back(input[current_item-1]); 

		current_weight = current_weight - input[current_item-1].weight;
		current_item --;
	}

	//Deallocate table
	for(int i = 0; i < input.size(); i++)
	{
		delete[] table[i];
	}
	delete[] table;
	return result;
}
