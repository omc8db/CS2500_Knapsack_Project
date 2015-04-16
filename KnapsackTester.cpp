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
	
	int capacity, input_size;
	vector<knapsackItem> test_input;
	combinedTestResult test_result;

	m_output_file << "Capacity, Input size, input type, dynamic time, greedy time, dynamic value, greedy value, dynamic list, greedy list" << endl;

	for(capacity = MIN_CAPACITY; capacity <= MAX_CAPACITY; capacity*=2)
	{
		cout << "Testing capacity " << capacity << "\n================" << endl;

		for(input_size = 1; input_size < MAX_INPUT_SIZE; input_size+= TEST_INPUT_SIZE_STEP)
		{

			// Direct test (easy)
			// Inputs have values corresponding to their weights
			test_input = generateDirect(input_size);
			test_result = test(test_input, capacity);

			m_output_file << capacity << ',' << input_size << ",direct," 
			              << test_result.dynamicTime << ','
			              << test_result.greedyTime << ','
			              << test_result.dynamicResult.totalValue << ','
			              << test_result.greedyResult.totalValue << ','
			              << test_result.dynamicResult.solution_set << ','
			              << test_result.greedyResult.solution_set << ','
			              << endl;

			 // Random test (hard)
			 // Weights and values randomly assigned
			test_input = generateRandom(input_size);			              
			test_result = test(test_input, capacity);

			m_output_file << capacity << ',' << input_size << ",random," 
			              << test_result.dynamicTime << ','
			              << test_result.greedyTime << ','
			              << test_result.dynamicResult.totalValue << ','
			              << test_result.greedyResult.totalValue << ','
			              << test_result.dynamicResult.solution_set << ','
			              << test_result.greedyResult.solution_set << ','
			              << endl;

			 // Inverse test (easy)
			 // Weights are inversely related to value
			test_input = generateInverse(input_size);			              
			test_result = test(test_input, capacity);

			m_output_file << capacity << ',' << input_size << ",inverse," 
			              << test_result.dynamicTime << ','
			              << test_result.greedyTime << ','
			              << test_result.dynamicResult.totalValue << ','
			              << test_result.greedyResult.totalValue << ','
			              << test_result.dynamicResult.solution_set << ','
			              << test_result.greedyResult.solution_set << ','
			              << endl;

		}
	}

	
	
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

vector<knapsackItem> KnapsackTester::generateRandom(int size)
{
	vector<knapsackItem> result;
	//Allocate enough space for the vector
	result.reserve(size);

	knapsackItem tmp;

	for(int i = 0; i < size; i++)
	{
		//Generate a knapsack object
		tmp.value = rand()%MAX_RANDOM_VAL;
		tmp.weight = rand()%MAX_RANDOM_VAL;

		//add it to the result
		result.push_back(tmp);
	}

	return result;
}

vector<knapsackItem> KnapsackTester::generateDirect(int size)
{
	vector<knapsackItem> result;
	//Allocate enough space for the vector
	result.reserve(size);

	knapsackItem tmp;

	for(int i = 0; i < size; i++)
	{
		//Generate a knapsack object
		tmp.value = i;
		tmp.weight = i;

		//add it to the result
		result.push_back(tmp);
	}

	return result;	
}

vector<knapsackItem> KnapsackTester::generateInverse(int size)
{
	vector<knapsackItem> result;
	//Allocate enough space for the vector
	result.reserve(size);

	knapsackItem tmp;

	for(int i = 0; i < size; i++)
	{
		//Generate a knapsack object
		tmp.value = size;
		tmp.weight = size - i;

		//add it to the result
		result.push_back(tmp);
	}

	return result;
}
	


ostream& operator << (ostream& out, const combinedTestResult& in)
{
	out << "Dynamic Solution: value = " << in.dynamicResult.totalValue
	    << ", time = " << in.dynamicTime <<  endl;
	out << "Uses items: " << in.dynamicResult.solution_set << endl << endl;

	out << "greedy Solution: value = " << in.greedyResult.totalValue
	    << ", time = " << in.greedyTime <<  endl;
	out << "Uses items: " << in.greedyResult.solution_set << endl;
	out << endl << endl;
	return out;
}

ostream& operator << (ostream& out, const vector<knapsackItem>& input)
{
	for(int i = 0; i < input.size(); i ++)
	{
		out << "{w" << input[i].weight << " v" << input[i].value << "}";
	}

	return out;
}



