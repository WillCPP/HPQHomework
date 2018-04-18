#pragma once
#include <iostream>
#include "node.h"
using namespace std;

class PriorityQueue
{
public:
	PriorityQueue() { head = nullptr; }
	~PriorityQueue() {}

	Node* head;

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

	void Remove() {
		Node *ptr = nullptr;
		if (head == nullptr)
		{
			throw;
		}
		else
		{
			ptr = head;
			head = head->next;
			delete ptr;
		}
	}

	void DisplayQueue() {
		Node* ptr = head;
		cout << "Priority Queue" << endl;
		cout << "==============" << endl;
		while (ptr != nullptr)
		{
			cout << "Data: "<< ptr->data << " Priority: " << ptr->priority;
			ptr = ptr->next;
		}
	}

private:

};