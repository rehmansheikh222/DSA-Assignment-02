#pragma once
#include <iostream>
#include <stdint.h>
using namespace std;
struct Node
{
	int data;
	Node* npx;
	Node(int d)
	{
		data = d;
		npx = nullptr;
	}
};
class XOR_LL
{
	Node* head;
	Node* tail;
public:
	XOR_LL();
	void insertAtHead(int val);
	void insertAtTail(int val);
	void insertAfter(int key, int val);
	void deletetBefore(int key);
	int removeAtHead();
	int removeAtTail();
	void printList();
	~XOR_LL();
	bool isEmpty(){ return head == nullptr; }
};