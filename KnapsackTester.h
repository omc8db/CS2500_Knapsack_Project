#ifndef KNAPSACK_TESTER_H
#define KNAPSACK_TESTER_H

#include <iostream>
#include <fstream>
#include <vector>

//Used for performance benchmarking
// And seeding RNG
#include <time.h>

//used for Random Number Generator
#include <stdlib.h>

#include "knapsack.h"

using namespace std;

const int MAX_CAPACITY = 8192; // Test up to 2^16
const int MIN_CAPACITY = 4;


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
	// Iterates through capacities, doubling each time.
	// 	Runs with inputs of size 1 to MAX_INPUT_SIZE
	// 	Steps in TEST_INPUT_SIZE_STEP
	// results output in CSV to specified output file
	// Individual results displayed on screen

	void runAutomatedTests();

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
	vector<knapsackItem> generateRandom(int size, int max_val);
	vector<knapsackItem> generateDirect(int size);
	vector<knapsackItem> generateInverse(int size);
	
	ofstream m_output_file;

};

//Outputs the combined test result in human readable format
ostream& operator << (ostream& out, const combinedTestResult& in);

//Outputs a list of knapsack items
ostream& operator << (ostream& out, const vector<knapsackItem>& input);

#endif

