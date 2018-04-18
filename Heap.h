#pragma once
#include "node.h"

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

Heap::Heap()
{
}

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

void Heap::Insert(int item) {
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
	int leftHeap, rightHeap;
	leftHeap = left(node);
	rightHeap = right(node);
	if (rightHeap >= heap && leftHeap >= heap) {
		return;
	}
	
	
}
void Heap::Remove() {
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