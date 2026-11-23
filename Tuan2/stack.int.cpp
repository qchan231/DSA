#include <iostream>
using namespace std;

struct NODE 
{
    int data;
	NODE* next;
};

struct stack
{
	NODE* top = NULL;
};

bool isEmpty(stack s)
{
	return s.top == NULL;
}

void push(stack& s, int value)
{
	NODE* newNode = new NODE;
	newNode->data = value;
	newNode->next = s.top;
	s.top = newNode;
}

void pop(stack& s)
{
	if (isEmpty(s)) return;
	NODE* temp = s.top;
	s.top = s.top->next;
	delete temp;
}

int top(stack s)
{
	if (isEmpty(s)) return -1;
	return s.top->data;
}

void Testing_Push_Pop_Top_Stack(stack& s)
{
	int res[10000];
	int count = 0;
	int x;
	while (cin >> x && x != -1)
	{
		if (x != 0)
		{
			push(s, x);
		}
		else
		{
			if (!isEmpty(s))
			{
				res[count++] = top(s);
				pop(s);
			}
		}
	}
	cout << "output: ";
	for (int i = 0; i < count; i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;

	cout << "top: ";
	if (!isEmpty(s))
	{
		cout << top(s);
	}
}

int main() {
    stack s;
    Testing_Push_Pop_Top_Stack(s);
    return 0;
}
