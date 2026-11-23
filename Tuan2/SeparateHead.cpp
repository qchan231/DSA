/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Cấu trúc của một node
struct NODE {
	int info;
	NODE* pNext;
};
// Cấu trúc của một DSLK
struct LIST {
	NODE* pHead;
	NODE* pTail;
};

NODE* CreateNode(int x) {
	NODE* p;
	p = new NODE;
	//if (p == NULL)
	//		exit(1);

	p->info = x;
	p->pNext = NULL;
	return p;
}

void CreateEmptyList(LIST& L) {
	L.pHead = NULL;
	L.pTail = NULL;
}

void CreateList(LIST& L) {
	int n, value;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> value;
		NODE* newNode = CreateNode(value);
		if (L.pHead == NULL) {
			L.pHead = L.pTail = newNode;
		}
		else {
			L.pTail->pNext = newNode;
			L.pTail = newNode;
		}
	}
}

NODE* SeparateHead(LIST& L) {
	if (L.pHead == NULL) return NULL;
	NODE* p = L.pHead;
	L.pHead = L.pHead->pNext;
	if (L.pHead == NULL) L.pTail = NULL;
	p->pNext = NULL;
	return p;
}

void PrintList(NODE* head) {
	if (head == NULL) {
		cout << "Empty List." << endl;
		return;
	}
	NODE* temp = head;
	while (temp) {
		cout << temp->info;
		if (temp->pNext) cout << " ";
		temp = temp->pNext;
	}
	cout << endl;
}

int main() {
	LIST L;
	CreateEmptyList(L);

	CreateList(L);
	NODE* p = SeparateHead(L);
	if (p != NULL) cout << p->info << endl;
	PrintList(L.pHead);

	return 0;
}
