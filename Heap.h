#pragma once
#include "node.h"

class Heap
{
public:
	Heap(int size){
		data = new int[size];
		heap = 0;
		array = size;
	}
	 }
	~Heap();
	
private:
	int *data;
	int array;
	int heap;
	
	
	

};

Heap::Heap()
{
}

Heap::~Heap()
{
	delete[] data;
}

void Heap::insert() {
	
	
}