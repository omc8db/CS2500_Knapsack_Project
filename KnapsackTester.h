#ifndef KNAPSACK_TESTER_H
#define KNAPSACK_TESTER_H

#include <iostream>
#include <fstream>

using namespace std;

class KnapsackTester
{
public:
	KnapsackTester(const char* output_filename);
	~KnapsackTester();
	void runTests();
private:
	ofstream m_output_file;
};


#endif
