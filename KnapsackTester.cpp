#include "KnapsackTester.h"

KnapsackTester::KnapsackTester(const char* output_filename)
{
	m_output_file.open(output_filename);
}

KnapsackTester::~KnapsackTester()
{
	m_output_file.close();
}

void KnapsackTester::runTests()
{
	return;
}
