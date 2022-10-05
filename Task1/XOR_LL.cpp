#include "XOR_LL.h"
XOR_LL::XOR_LL()
{
	head = tail = nullptr;
}
XOR_LL::~XOR_LL()
{
	while (head)
	{
		removeAtHead();
	}
}
void XOR_LL::insertAtHead(int val)
{
	Node* newNode = new Node(val);
	if (!head)
	{
		head = newNode;
		tail = head;
		return;
	}
	if (head == tail)
	{
		newNode->npx = head;
		head->npx = newNode;
		head = newNode;
		return;
	}
	newNode->npx = head;
	head->npx = (Node*)(uintptr_t(newNode) ^ uintptr_t(head->npx));
	head = newNode;
}
void XOR_LL::insertAtTail(int val)
{
	Node* newNode = new Node(val);
	if (!tail)
	{
		tail = newNode;
		head = tail;
		return;
	}
	if (tail == head)
	{
		newNode->npx = tail;
		tail->npx = newNode;
		tail = newNode;
		return;
	}
	newNode->npx = tail;
	tail->npx = (Node*)(uintptr_t(tail->npx) ^ uintptr_t(newNode));
	tail = newNode;
}
int XOR_LL::removeAtHead()
{
	if (!head)
	{
		return 0;
	}
	if (head == tail)
	{
		delete head;
		head = tail = nullptr;
		return 1;
	}
	if (head->npx == tail)
	{
		delete head;
		tail->npx = nullptr;
		head = tail;
		return 1;
	}
	Node* newHead = head->npx;
	newHead->npx = (Node*)(uintptr_t(head) ^ uintptr_t(newHead->npx));
	delete head;
	head = newHead;
	return 1;
}

int XOR_LL::removeAtTail()
{
	if (!tail)
	{
		return 0;
	}
	if (head == tail)
	{
		delete tail;
		head = tail = nullptr;
		return 1;
	}
	if (tail->npx == head)
	{
		delete tail;
		head->npx = nullptr;
		tail = head;
		return 1;
	}
	Node* newTail = tail->npx;
	newTail->npx = (Node*)(uintptr_t(tail) ^ uintptr_t(newTail->npx));
	delete tail;
	tail = newTail;
	return 1;
}
void XOR_LL::printList()
{
	if (head == nullptr)
	{
		cout << "List is empty" << endl;
		return;
	}
	Node* p = head;
	Node* q = nullptr;
	Node* r = nullptr;
	while (p)
	{
		r = (Node*)(uintptr_t(q) ^ uintptr_t(p->npx));
		if (r)
		{
			cout << p->data << "-->";
		}
		else
		{
			cout << p->data;
		}
		q = p;
		p = r;
	}
	cout << endl;
}
void XOR_LL::insertAfter(int key, int val)
{
	Node* p = head;
	Node* q = nullptr;
	Node* r = nullptr;
	r = (Node*)(uintptr_t(q) ^ uintptr_t(p->npx));
	while (p && p->data != key)
	{
		q = p;
		p = r;
		r = (Node*)(uintptr_t(q) ^ uintptr_t(p->npx));
	}
	if (!p)
	{
		cout << "The node you entered does not exist" << endl;
		return;
	}
	if (p == tail)
	{
		insertAtTail(val);
		return;
	}
	Node* nextOfr = (Node*)(uintptr_t(p) ^ uintptr_t(r->npx));
	Node* newNode = new Node(val);
	p->npx = (Node*)(uintptr_t(q) ^ uintptr_t(newNode));
	newNode->npx = (Node*)(uintptr_t(p) ^ uintptr_t(r));
	r->npx = (Node*)(uintptr_t(newNode) ^ uintptr_t(nextOfr));
}
void XOR_LL::deletetBefore(int key)
{
	Node* p = head;
	Node* q = nullptr;
	Node* r = nullptr;
	//r = (Node*)(uintptr_t(q) ^ uintptr_t(p->npx));
	while (p && p->data != key)
	{
		r = (Node*)(uintptr_t(q) ^ uintptr_t(p->npx));
		q = p;
		p = r;
	}
	if (!p)
	{
		cout << "No node with the value " << key << " exists" << endl;
		return;
	}
	r = (Node*)(uintptr_t(q) ^ uintptr_t(p->npx));
	if (p == head)
	{
		cout << "No node exists before " << key << endl;
		return;
	}
	if (q == head)
	{
		removeAtHead();
		return;
	}
	Node* prevOfQ = (Node*)(uintptr_t(q->npx) ^ uintptr_t(p));
	Node* doublePrevOfQ = (Node*)(uintptr_t(prevOfQ->npx) ^ uintptr_t(q));
	p->npx = (Node*)(uintptr_t(prevOfQ) ^ uintptr_t(r));
	prevOfQ->npx = (Node*)(uintptr_t(doublePrevOfQ) ^ uintptr_t(p));
	delete q;
	q = nullptr;
}