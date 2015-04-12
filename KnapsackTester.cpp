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

void KnapsackTester::runTests()
{
	m_output_file << "COLUMN NAMES HERE" << endl;
	vector<knapsackItem> input;
	
	
	return;
}

