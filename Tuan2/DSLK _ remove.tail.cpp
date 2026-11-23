#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
};

struct LIST
{
	Node* pHead;
	Node* pTail;
};

Node* CreateNode(int x)
{
	Node* p = new Node;
	p->data = x;
	p->next = NULL;
	return p;
}

void CreateEmptyList(LIST& L)
{
	L.pHead = L.pTail = NULL;
}

void CreateList(LIST& L)
{
	int x;
	cin >> x;
	if (x == -1) cout << "Empty List.";
	while (x != -1)
	{
		Node* p = CreateNode(x);
		if (L.pHead == NULL) L.pHead = L.pTail = p;
		else
		{
			L.pTail->next = p;
			L.pTail = p;
		}
		cin >> x;
	}
}

void RemoveTail(LIST& L)
{
	if (L.pHead == NULL) return;
	if (L.pHead == L.pTail)
	{
		delete L.pHead;
		L.pHead = L.pTail = NULL;
		cout << "Empty List.";
		return;
	}
	Node* q = L.pHead;
	while (q->next != L.pTail) q = q->next;
	delete L.pTail;
	q->next = NULL;
	L.pTail = q;
}

void PrintList(LIST& L)
{
	Node* p = L.pHead;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
}

int main() {
	LIST L;
	CreateEmptyList(L);

	CreateList(L);
	RemoveTail(L);
	PrintList(L);

	return 0;
}
