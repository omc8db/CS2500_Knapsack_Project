
#include <iostream>
#include <cstring>

#include "KnapsackTester.h"

using namespace std;

int main()
{
	int choice;

	int customItemsCount;
	int customCapacity;
	knapsackItem customItemBuffer;
	combinedTestResult customResult;
	vector<knapsackItem> customList;


	KnapsackTester tester("results.csv");

	srand(time(NULL));

	cout << "Knapsack Problem Tester" << endl;

	do
	{

		cout << "Options: \n"
		     << "\t1. Run an automated set of tests" << endl
		     << "\t2. Optimize a specific knapsack" << endl
		     << "\t3. Exit " << endl;

		cin >> choice;

		switch(choice)
		{
			case 1: //Automated Test
				cout << "Starting tests. Results will be output to console and results.csv" << endl;
				tester.runAutomatedTests();

				break;

			case 2: //Custom Test
				cout << "Enter number of items: " << endl;
				cin >> customItemsCount;
				customList.clear();
				
				for(int i = 0; i < customItemsCount; i++)
				{
					cout << i << ": Enter Weight " << endl;
					cin >> customItemBuffer.weight;
					cout << i << ": Enter Value " << endl;
					cin >> customItemBuffer.value;

					customList.push_back(customItemBuffer);
				}
				cout << "List entry complete.\n\nEnter knapsack capacity" << endl;
				cin >> customCapacity;
				customResult = tester.test(customList, customCapacity);
				cout << "Test result: \n";
				cout << customResult;

								
				break;

			case 3: //Exit
				break;

			default:
				cout << "Command not recognized. Try again" << endl << endl;
				break;

		}
	} while(choice != 3);


	return 0;
}
