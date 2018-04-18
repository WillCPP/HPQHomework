#pragma once

class Node
{
public:
	Node() { data = -1; priority = -1; }
	Node(int d, int p) { data = d; priority = p; }
	~Node() {}

	int data = -1;
	int priority = -1;
	
	Node *next;

private:

};
