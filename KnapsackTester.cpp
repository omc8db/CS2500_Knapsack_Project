#include "KnapsackTester.h"

//------ KnapsackTester ---------//
KnapsackTester::KnapsackTester(const char* output_filename)
{
	//Open file in overwrite mode
	m_output_file.open(output_filename, ios::trunc); 
}

KnapsackTester::~KnapsackTester()
{
	m_output_file.close();
}

void KnapsackTester::runAutomatedTests()
{
	m_output_file << "COLUMN NAMES HERE" << endl;
	vector<knapsackItem> input;
	
	
	return;
}

combinedTestResult KnapsackTester::test(const vector<knapsackItem>& input, int capacity)
{
	int time_start, time_stop;
	combinedTestResult result;

	time_start = clock();
	result.greedyResult = greedyKnapsackSolve(input, capacity);
	time_stop = clock();

	result.greedyTime = time_stop - time_start;

	time_start = clock();
	result.dynamicResult = dynamicKnapsackSolve(input, capacity);
	time_stop = clock();

	result.dynamicTime = time_stop - time_start;

	return result;
}

ostream& operator << (ostream& out, const combinedTestResult& in)
{
	out << "Not yet implemented" << endl;

	return out;
}