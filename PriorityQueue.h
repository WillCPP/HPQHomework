#pragma once
#include <iostream>
#include "node.h"
#include "EmptyListException.h"
using namespace std;

class PriorityQueue
{
private:
	Node *head;
public:
	PriorityQueue() { head = nullptr; }
	~PriorityQueue() {}

	void Insert(int data, int priority) {
		Node *ptrNew = new Node(data, priority);
		if (head == nullptr || priority < head->priority)
		{
			ptrNew->next = head;
			head = ptrNew;
		}
		else
		{
			Node *ptr = head;
			while (ptr->next != nullptr && ptr->next->priority <= priority)
			{
				ptr = ptr->next;
			}
			ptrNew->next = ptr->next;
			ptr->next = ptrNew;
		}
	}

	Node Remove() {
		Node retVal(-1, -1);
		Node *ptr = nullptr;
		if (head == nullptr)
		{
			throw EmptyListException();
		}
		else
		{
			ptr = head;
			head = head->next;
			retVal.data = ptr->data;
			retVal.priority = ptr->priority;
			delete ptr;
		}
		return retVal;
	}

	void DisplayQueue() {
		Node* ptr = head;
		cout << "Priority Queue" << endl;
		cout << "==============" << endl;
		while (ptr != nullptr)
		{
			cout << "Data: "<< ptr->data << " Priority: " << ptr->priority << endl;
			ptr = ptr->next;
		}
	}
};