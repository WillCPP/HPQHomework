#include <iostream>
using namespace std;

int main() {
	int input = -1;
	int input_test = -1;
	do
	{
		cout << "Menu:" << endl;
		cout << "[1] Test Priority Queue" << endl;
		cout << "[2] Test Heap" << endl;
		cout << "[0] Exit" << endl;
		cin >> input;
		if (input == 1)
		{
			input_test = -1;
			do
			{
				cout << "Priority Queue:" << endl;
				cout << "[1] Insert()" << endl;
				cout << "[2] Remove()" << endl;
				cout << "[3] PrintQueue()" << endl;
				cout << "[0] Exit" << endl;
				cin >> input_test;
				if (input_test == 1)
				{
					//call Insert
				}
				else if (input_test == 2)
				{
					//call Remove
				}
				else if (input_test == 3)
				{
					//call PrintQueue
				}
				else if (input_test == 0)
				{
					exit;
				}
				else
				{
					cout << "Invalid input." << endl;
				}
			} while (input_test != 0);
		}
		else if (input == 2)
		{
			input_test = -1;
			do
			{
				cout << "Heap:" << endl;
				cout << "[1] Insert()" << endl;
				cout << "[2] Remove()" << endl;
				cout << "[3] PrintHeap()" << endl;
				cout << "[0] Exit" << endl;
				cin >> input_test;
				if (input_test == 1)
				{
					//call Insert
				}
				else if (input_test == 2)
				{
					//call Remove
				}
				else if (input_test == 3)
				{
					//call PrintHeap
				}
				else if (input_test == 0)
				{
					exit;
				}
				else
				{
					cout << "Invalid input." << endl;
				}
			} while (input_test != 0);
		}
		else if (input != 0)
		{
			cout << "Invalid input." << endl << endl;
		}
	} while (input != 0);
	return 0;
}