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
		int r = 2 * node + 2;
		if (r < heap)
			return r;
		return -1;
	}
	
	int left(int node) {
		int l =  2 * node + 1;
		if (l < heap)
			return l;
		return -1;
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
	if (rightHeap >= 0 && leftHeap >= 0 && data[leftHeap] >= data[rightHeap]) {
		leftHeap = rightHeap;
	}
	if (leftHeap >= 0 && data[node]>data[leftHeap]) {
		temp = data[node];
		data[node] = data[leftHeap];
		data[leftHeap] = temp;
		HeapifyDown(leftHeap);
	}
	
	
}

int Heap::RemoveHeap() {
	if (isEmpty()) {
		cout <<"Heap is empty" << endl;
		return -1;
	}
	else {
		int temp = data[0];
		data[0] = data[heap-1];
		heap--;
		if (heap > 0)
			HeapifyDown(0);
		return temp;
	}
}

void Heap::DisplayHeap() {
	cout << "     Heap     " << endl;
	cout << "==============" << endl;
	for(int i = 0; i <heap; i++)
	{
		cout << "Data: " << data[i]<< endl;
	}
	
} 