#pragma once

class Node
{
public:
	Node() {}
	Node(int d, int p) { data = d; priority = p; }
	~Node() {}

	int data;
	int priority;
	
	Node* next;

private:

};
