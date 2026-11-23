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

void AddTail(LIST& L, Node* p)
{
    if (L.pHead == NULL) L.pHead = L.pTail = p;
    else
    {
        L.pTail->next = p;
        L.pTail = p;
    }
}

void AddHead(LIST& L, Node* p)
{
    if (L.pHead == NULL) L.pHead = L.pTail = p;
    else
    {
        p->next = L.pHead;
        L.pHead = p;
    }
}

void CreateList(LIST& L)
{
    int type, x;
    cin >> type;
    if (type == -1) cout << "Empty List.";
    while (type != -1)
    {
        if (type == -1) break;
        cin >> x;
        Node* p = CreateNode(x);
        if (type == 0) AddHead(L, p);
        else AddTail(L, p);
        cin >> type;
    }
}

void PrintList(LIST L)
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
    PrintList(L);

    return 0;
}
