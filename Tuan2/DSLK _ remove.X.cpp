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
	int n;
	cin >> n;
	while (n != -1)
	{
		Node* p = CreateNode(n);
		if (L.pHead == NULL) L.pHead = L.pTail = p;
		else
		{
			L.pTail->next = p;
			L.pTail = p;
		}
		cin >> n;
	}
}

void RemoveX(LIST& L, int x)
{
	if (L.pHead == NULL) return;
	if (L.pHead->data == x)
	{
		Node* t = L.pHead;
		L.pHead = L.pHead->next;
		if (L.pHead == NULL) L.pTail = NULL;
		delete t;
		return;
	}
	Node* q = L.pHead;
	while (q->next != NULL && q->next->data != x) q = q->next;
	if (q->next == NULL) return;
	Node* t = q->next;
	q->next = t->next;
	if (t == L.pTail) L.pTail = q;              
	delete t;
}

void PrintList(LIST& L)
{
	if (L.pHead == NULL)
	{
		cout << "Empty List.";
		return;
	}
	Node* p = L.pHead;
	while (p != NULL)
	{
		cout << p->data;
		if (p->next != NULL) cout << " ";
		p = p->next;
	}
}

int main() {
	LIST L;
	int X;
	CreateEmptyList(L);

	CreateList(L);
	std::cin >> X;
	RemoveX(L, X);
	PrintList(L);

	return 0;
}
