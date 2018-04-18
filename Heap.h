#ifndef HEAP_H
#define HEAP_H

//used for reference: http://www.algolist.net/Data_structures/Binary_heap/Insertion
class Heap
{
public:
	Heap(int size){
		data = new int[size];
		heap = 0;
		array = size;
	}
	bool isEmpty() {
		return (heap == 0);
	}
	~Heap();
	Heap(){};
	void HeapifyUp(int node);
	void InsertHeap(int item);
	void HeapifyDown(int node);
	int RemoveHeap();
	void DisplayHeap();
	
private:
	int *data;
	int array;
	int heap;
	
	int parent(int node) {
		return (node - 1) / 2;
	}
	
	int right(int node) {
		return 2 * node + 2;
	
	}
	
	int left(int node) {
		return 2 * node + 1;
	}

};
#endif


Heap::~Heap()
{
	delete[] data;
}

void Heap::HeapifyUp(int node) {
	int heapParent, temp;
	if (node != 0) {
		heapParent = parent(node);
		if (data[heapParent] > data[node]) {
			temp = data[heapParent];
			data[heapParent] = data[node];
			data[node] = temp;
			HeapifyUp(heapParent);
		}
	}
}

void Heap::InsertHeap(int item) {
	if (heap == array) {
		cout << "Overflow error." << endl;
	}
	else {
		heap++;
		data[heap - 1] = item;
		HeapifyUp(heap - 1);
	}
	
}

void Heap::HeapifyDown(int node) {
	int leftHeap, rightHeap, temp;
	leftHeap = left(node);
	rightHeap = right(node);
	if (rightHeap >= 0 && leftHeap >= 0 && heap[leftHeap] >= heap[rightHeap]) {
		leftHeap = rightHeap;
	}
	if (leftHeap > 0) {
		temp = heap[node];
		heap[node] = heap[rightHeap];
		heap[node] = temp;
		HeapifyDown(leftHeap);
	}
	
	
}
int Heap::RemoveHeap() {
	if (isEmpty()) {
		cout <<"Heap is empty" << endl;
	}
	else {
		data[0] = data[heap-1];
		heap--;
		if (heap > 0)
			HeapifyDown(0);
	}
}

void Heap::DisplayHeap() {
	vector<int>::iterator loc = heap.begin();
	cout << "     Heap     " << endl;
	cout << "==============" << endl;
	while (loc != heap.end())
	{
		cout << "Data: " << *loc << endl;
		++loc;
	}
	
}