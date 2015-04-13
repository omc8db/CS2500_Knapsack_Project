#ifndef KNAPSACK_TESTER_H
#define KNAPSACK_TESTER_H

#include <iostream>
#include <fstream>

//I'm not writing my own list support
#include <vector>

#include "knapsack.h"

using namespace std;

struct combinedTestResult
{
	knapsackResult greedyResult;
	knapsackResult dynamicResult;
	int greedyTime;
	int dynamicTime;
};

class KnapsackTester
{
public:
	KnapsackTester(const char* output_filename);
	~KnapsackTester();
	
	// Runs the tests and outputs the results to a file
	void runTests();

	//Runs the given input through a greedy and dynamic approach to solving the
	//knapsack problem. 
	//
	// Inputs: List of items to knapsack
	//         Capacity
	// Outputs: Time for dynamic approach
	//          Time for greedy approach
	//          knapsackResult for dynamic approach
	//          knapsackResult for greedy approach
	combinedTestResult test(const vector<knapsackItem>& input, int capacity);
private:
	vector<knapsackItem> generateRandom(int size);
	vector<knapsackItem> generateAscending(int size);
	vector<knapsackItem> generateDescending(int size);
	
	ofstream m_output_file;

};



#endif

