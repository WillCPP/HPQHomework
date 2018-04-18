#pragma once

class Node
{
public:
	Node();
	~Node();

	int priority;
	int data;
	Node* next;
private:

};

Node::Node()
{
}

Node::~Node()
{
}