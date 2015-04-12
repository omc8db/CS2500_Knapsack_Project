#ifndef KNAPSACK_TESTER_H
#define KNAPSACK_TESTER_H

#include <iostream>
#include <fstream>

//I'm not writing my own list support
#include <vector>

#include "knapsack.h"

using namespace std;

enum testType { ascending, descending, random };

class KnapsackTester
{
public:
	KnapsackTester(const char* output_filename);
	~KnapsackTester();
	
	// Runs the tests and outputs the results to a file
	void runTests();
private:
	vector<knapsackItem> generateRandom(int size);
	vector<knapsackItem> generateAscending(int size);
	vector<knapsackItem> generateDescending(int size);
	
	ofstream m_output_file;

};

#endif

