#define _SCL_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;

const int S_500 = 500;
const int S_1000 = 1000;
const int S_2000 = 2000;
const int S_5000 = 5000;

int main() {
	//initialize random number generator and distributions
	random_device rd;

	default_random_engine rng{ rd() };

	uniform_real_distribution<double> dist_500(0, 2 * S_500);
	uniform_real_distribution<double> dist_1000(0, 2 * S_1000);
	uniform_real_distribution<double> dist_2000(0, 2 * S_2000);
	uniform_real_distribution<double> dist_5000(0, 2 * S_5000);

	//initialize arrays
	int arr_500[S_500];
	int arr_1000[S_1000];
	int arr_2000[S_2000];
	int arr_5000[S_5000];

	//fill arrays with random numbers
	for (int i = 0; i < S_5000; ++i) {
		int temp_500 = static_cast<int>(dist_500(rng));
		int temp_1000 = static_cast<int>(dist_1000(rng));
		int temp_2000 = static_cast<int>(dist_2000(rng));
		int temp_5000 = static_cast<int>(dist_5000(rng));

		if (i < S_500) { arr_500[i] = temp_500; }
		if (i < S_1000) { arr_1000[i] = temp_1000; }
		if (i < S_2000) { arr_2000[i] = temp_2000; }
		if (i < S_5000) { arr_5000[i] = temp_5000; }
	}

	int arr_500_Priory[S_500];
	int arr_500_Heap[S_500];
	copy(begin(arr_500), end(arr_500), begin(arr_500_Priory));
	copy(begin(arr_500), end(arr_500), begin(arr_500_Heap));

	int arr_1000_Priory[S_1000];
	int arr_1000_Heap[S_1000];
	copy(begin(arr_1000), end(arr_1000), begin(arr_1000_Priory));
	copy(begin(arr_1000), end(arr_1000), begin(arr_1000_Heap));

	int arr_2000_Priory[S_2000];
	int arr_2000_Heap[S_2000];
	copy(begin(arr_2000), end(arr_2000), begin(arr_2000_Priory));
	copy(begin(arr_2000), end(arr_2000), begin(arr_2000_Heap));

	int arr_5000_Priory[S_5000];
	int arr_5000_Heap[S_5000];
	copy(begin(arr_5000), end(arr_5000), begin(arr_5000_Priory));
	copy(begin(arr_5000), end(arr_5000), begin(arr_5000_Heap));

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