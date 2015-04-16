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
	out << "Dynamic Solution: value = " << in.dynamicResult.totalValue
	    << ", time = " << in.dynamicTime <<  endl;
	out << "Uses items: " << endl;
	for(int i = 0; i < in.dynamicResult.solution_set.size(); i++)
	{
		out << "{w" << in.dynamicResult.solution_set[i].weight << ", v"
		     << in.dynamicResult.solution_set[i].value << "}" << endl;
	}

	out << "greedy Solution: value = " << in.greedyResult.totalValue
	    << ", time = " << in.greedyTime <<  endl;
	out << "Uses items: " << endl;
	for(int i = 0; i < in.greedyResult.solution_set.size(); i++)
	{
		out << "{w" << in.greedyResult.solution_set[i].weight << ", v"
		     << in.greedyResult.solution_set[i].value << "}" << endl;
	}
	out << endl << endl;
	return out;
}