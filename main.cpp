#define _SCL_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>
#include <chrono>
#include "EmptyListException.h"
#include "PriorityQueue.h"
#include "Heap.h"
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
	int dataarr_5000[S_5000];
	//fill arrays with random numbers
	for (int i = 0; i < S_5000; ++i) {
		int temp_500 = static_cast<int>(dist_500(rng));
		int temp_1000 = static_cast<int>(dist_1000(rng));
		int temp_2000 = static_cast<int>(dist_2000(rng));
		int temp_5000 = static_cast<int>(dist_5000(rng));
		int data_5000 = static_cast<int>(dist_5000(rng));
		if (i < S_500) { arr_500[i] = temp_500; }
		if (i < S_1000) { arr_1000[i] = temp_1000; }
		if (i < S_2000) { arr_2000[i] = temp_2000; }
		if (i < S_5000) { arr_5000[i] = temp_5000; }
		if (i < S_5000) { dataarr_5000[i] = data_5000; }
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


	//***** INSERT STARTS*******

	PriorityQueue priqueue500 = PriorityQueue();
	PriorityQueue priqueue1000 = PriorityQueue();
	PriorityQueue priqueue2000 = PriorityQueue();
	PriorityQueue priqueue5000 = PriorityQueue();

	Heap heap500 = Heap(500);
	Heap heap1000 = Heap(1000);
	Heap heap2000 = Heap(2000);
	Heap heap5000 = Heap(5000);
	{
		auto start_time_500_Priory = high_resolution_clock::now();
		for (int i = 0; i < S_500; i++) {
			priqueue500.Insert(dataarr_5000[i], arr_500_Priory[i]);//Calls add function 500
		}
		auto stop_time_500_Priory = high_resolution_clock::now();
		auto duration_500_Priory = duration_cast<nanoseconds>(stop_time_500_Priory - start_time_500_Priory);
		auto start_time_1000_Priory = high_resolution_clock::now();
		for (int i = 0; i < S_1000; i++) {
			priqueue1000.Insert(dataarr_5000[i], arr_1000_Priory[i]);//Calls add function 1000
		}
		auto stop_time_1000_Priory = high_resolution_clock::now();
		auto duration_1000_Priory = duration_cast<nanoseconds>(stop_time_1000_Priory - start_time_1000_Priory);
		auto start_time_2000_Priory = high_resolution_clock::now();
		for (int i = 0; i < S_2000; i++) {
			priqueue2000.Insert(dataarr_5000[i], arr_2000_Priory[i]);//Calls add function 2000
		}
		auto stop_time_2000_Priory = high_resolution_clock::now();
		auto duration_2000_Priory = duration_cast<nanoseconds>(stop_time_2000_Priory - start_time_2000_Priory);
		auto start_time_5000_Priory = high_resolution_clock::now();
		for (int i = 0; i < S_5000; i++) {
			priqueue5000.Insert(dataarr_5000[i], arr_5000_Priory[i]);//Calls add function 5000
		}
		auto stop_time_5000_Priory = high_resolution_clock::now();
		auto duration_5000_Priory = duration_cast<nanoseconds>(stop_time_5000_Priory - start_time_5000_Priory);


		auto start_time_500_Heap = high_resolution_clock::now();
		for (int i = 0; i < S_500; i++) {
			heap500.InsertHeap(arr_500_Heap[i]);//Calls add function 500
		}
		auto stop_time_500_Heap = high_resolution_clock::now();
		auto duration_500_Heap = duration_cast<nanoseconds>(stop_time_500_Heap - start_time_500_Heap);
		auto start_time_1000_Heap = high_resolution_clock::now();
		for (int i = 0; i < S_1000; i++) {
			heap1000.InsertHeap(arr_1000_Heap[i]);//Calls add function 1000
		}
		auto stop_time_1000_Heap = high_resolution_clock::now();
		auto duration_1000_Heap = duration_cast<nanoseconds>(stop_time_1000_Heap - start_time_1000_Heap);
		auto start_time_2000_Heap = high_resolution_clock::now();
		for (int i = 0; i < S_2000; i++) {
			heap2000.InsertHeap(arr_2000_Heap[i]);//Calls add function 2000
		}
		auto stop_time_2000_Heap = high_resolution_clock::now();
		auto duration_2000_Heap = duration_cast<nanoseconds>(stop_time_2000_Heap - start_time_2000_Heap);
		auto start_time_5000_Heap = high_resolution_clock::now();
		for (int i = 0; i < S_5000; i++) {
			heap5000.InsertHeap(arr_5000_Heap[i]);//Calls add function 5000
		}
		auto stop_time_5000_Heap = high_resolution_clock::now();
		auto duration_5000_Heap = duration_cast<nanoseconds>(stop_time_5000_Heap - start_time_5000_Heap);

		cout << "Priority Queue: Insert" << endl;
		cout << "===========" << endl;
		cout << "Number of Items | Execution Time (ns)" << endl;
		cout << setw(16) << "500" << "|" << setw(15) << right << duration_500_Priory.count() << " ns" << endl;
		cout << setw(16) << "1000" << "|" << setw(15) << right << duration_1000_Priory.count() << " ns" << endl;
		cout << setw(16) << "2000" << "|" << setw(15) << right << duration_2000_Priory.count() << " ns" << endl;
		cout << setw(16) << "5000" << "|" << setw(15) << right << duration_5000_Priory.count() << " ns" << endl;
		cout << endl;

		cout << "Heap: Insert" << endl;
		cout << "===========" << endl;
		cout << "Number of Items | Execution Time (ns)" << endl;
		cout << setw(16) << "500" << "|" << setw(15) << right << duration_500_Heap.count() << " ns" << endl;
		cout << setw(16) << "1000" << "|" << setw(15) << right << duration_1000_Heap.count() << " ns" << endl;
		cout << setw(16) << "2000" << "|" << setw(15) << right << duration_2000_Heap.count() << " ns" << endl;
		cout << setw(16) << "5000" << "|" << setw(15) << right << duration_5000_Heap.count() << " ns" << endl;
		cout << endl;
	}

	//***** REMOVE STARTS*******
	auto start_time_500_Priory = high_resolution_clock::now();
	for (int i = 0; i < S_500; i++) {
		priqueue500.Remove();//Calls Remove function 500 
	}
	auto stop_time_500_Priory = high_resolution_clock::now();
	auto duration_500_Priory = duration_cast<nanoseconds>(stop_time_500_Priory - start_time_500_Priory);
	auto start_time_1000_Priory = high_resolution_clock::now();
	for (int i = 0; i < S_1000; i++) {
		priqueue1000.Remove();//Calls Remove function 1000 
	}
	auto stop_time_1000_Priory = high_resolution_clock::now();
	auto duration_1000_Priory = duration_cast<nanoseconds>(stop_time_1000_Priory - start_time_1000_Priory);
	auto start_time_2000_Priory = high_resolution_clock::now();
	for (int i = 0; i < S_2000; i++) {
		priqueue2000.Remove();//Calls Remove function 2000 
	}
	auto stop_time_2000_Priory = high_resolution_clock::now();
	auto duration_2000_Priory = duration_cast<nanoseconds>(stop_time_2000_Priory - start_time_2000_Priory);
	auto start_time_5000_Priory = high_resolution_clock::now();
	for (int i = 0; i < S_5000; i++) {
		priqueue5000.Remove();//Calls Remove function 5000 
	}
	auto stop_time_5000_Priory = high_resolution_clock::now();
	auto duration_5000_Priory = duration_cast<nanoseconds>(stop_time_5000_Priory - start_time_5000_Priory);


	auto start_time_500_Heap = high_resolution_clock::now();
	for (int i = 0; i < S_500; i++) {
		heap500.RemoveHeap();//Calls remove function 500
	}
	auto stop_time_500_Heap = high_resolution_clock::now();
	auto duration_500_Heap = duration_cast<nanoseconds>(stop_time_500_Heap - start_time_500_Heap);
	auto start_time_1000_Heap = high_resolution_clock::now();
	for (int i = 0; i < S_1000; i++) {
		heap1000.RemoveHeap();//Calls remove function 1000
	}
	auto stop_time_1000_Heap = high_resolution_clock::now();
	auto duration_1000_Heap = duration_cast<nanoseconds>(stop_time_1000_Heap - start_time_1000_Heap);
	auto start_time_2000_Heap = high_resolution_clock::now();
	for (int i = 0; i < S_2000; i++) {
		heap2000.RemoveHeap();//Calls remove function 2000
	}
	auto stop_time_2000_Heap = high_resolution_clock::now();
	auto duration_2000_Heap = duration_cast<nanoseconds>(stop_time_2000_Heap - start_time_2000_Heap);
	auto start_time_5000_Heap = high_resolution_clock::now();
	for (int i = 0; i < S_5000; i++) {
		heap5000.RemoveHeap();//Calls remove function 5000
	}
	auto stop_time_5000_Heap = high_resolution_clock::now();
	auto duration_5000_Heap = duration_cast<nanoseconds>(stop_time_5000_Heap - start_time_5000_Heap);

	cout << "Priority Queue: Remove" << endl;
	cout << "===========" << endl;
	cout << "Number of Items | Execution Time (ns)" << endl;
	cout << setw(16) << "500" << "|" << setw(15) << right << duration_500_Priory.count() << " ns" << endl;
	cout << setw(16) << "1000" << "|" << setw(15) << right << duration_1000_Priory.count() << " ns" << endl;
	cout << setw(16) << "2000" << "|" << setw(15) << right << duration_2000_Priory.count() << " ns" << endl;
	cout << setw(16) << "5000" << "|" << setw(15) << right << duration_5000_Priory.count() << " ns" << endl;
	cout << endl;

	cout << "Heap: Remove" << endl;
	cout << "===========" << endl;
	cout << "Number of Items | Execution Time (ns)" << endl;
	cout << setw(16) << "500" << "|" << setw(15) << right << duration_500_Heap.count() << " ns" << endl;
	cout << setw(16) << "1000" << "|" << setw(15) << right << duration_1000_Heap.count() << " ns" << endl;
	cout << setw(16) << "2000" << "|" << setw(15) << right << duration_2000_Heap.count() << " ns" << endl;
	cout << setw(16) << "5000" << "|" << setw(15) << right << duration_5000_Heap.count() << " ns" << endl;
	cout << endl;

	//menu
	int input = -1;
	int input_queue = -1;
	int input_heap = -1;

	do
	{
		cout << endl << "Menu:" << endl;
		cout << "[1] Test Priority Queue" << endl;
		cout << "[2] Test Heap" << endl;
		cout << "[0] Exit" << endl;
		cin >> input;
		if (input == 1)
		{
			PriorityQueue pri_queue = PriorityQueue();
			input_queue = -1;
			do
			{
				cout << endl << "Priority Queue:" << endl;
				cout << "[1] Insert()" << endl;
				cout << "[2] Remove()" << endl;
				cout << "[3] PrintQueue()" << endl;
				cout << "[0] Exit" << endl;
				cin >> input_queue;
				if (input_queue == 1)
				{
					//call Insert
					int d = -1;
					int p = -1;
					cout << "Enter data (integer): ";
					cin >> d;
					cout << "Enter priority (integer): ";
					cin >> p;
					pri_queue.Insert(d, p);
				}
				else if (input_queue == 2)
				{
					Node n(-1, -1);
					try
					{
						n = pri_queue.Remove();
						cout << "Node remove" << endl;
						cout << "Data: " << n.data << " Priority: " << n.priority;
					}
					catch (EmptyListException e)
					{
						cout << e.Message << endl;
					}
				}
				else if (input_queue == 3)
				{
					//call PrintQueue
					pri_queue.DisplayQueue();
				}
				else if (input_queue == 0)
				{
					exit;
				}
				else
				{
					cout << "Invalid input." << endl;
				}
			} while (input_queue != 0);
		}
		else if (input == 2)
		{
			Heap heap = Heap(100);
			input_heap = -1;
			do
			{
				int i;
				cout << endl << "Heap:" << endl;
				cout << "[1] Insert()" << endl;
				cout << "[2] Remove()" << endl;
				cout << "[3] PrintHeap()" << endl;
				cout << "[0] Exit" << endl;
				cin >> input_heap;
				if (input_heap == 1)
				{
					//call Insert
					cout << "Enter item (integer): " << endl;
					cin >> i;
					heap.InsertHeap(i);
				}
				else if (input_heap == 2)
				{
					//call Remove
					int temp = heap.RemoveHeap();
					if ( temp == -1) {
						cout << "Empty Heap" << endl;
					}
					else {
						cout << "Removed: " << temp << endl;
					}
				}
				else if (input_heap == 3)
				{
					//call PrintHeap
					heap.DisplayHeap();
				}
				else if (input_heap == 0)
				{
					exit;
				}
				else
				{
					cout << "Invalid input." << endl;
				}
			} while (input_heap != 0);
		}
		else if (input != 0)
		{
			cout << "Invalid input." << endl << endl;
		}
	} while (input != 0);
	return 0;
}