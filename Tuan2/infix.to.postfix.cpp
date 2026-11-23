
#include <iostream>
using namespace std;
#define MAXN 100

struct NODE {
    char info;
    NODE* pNext;
};

NODE* CreateNode(char x) {
    NODE* p = new NODE;
    p->info = x;
    p->pNext = NULL;
    return p;
}
struct stack {
    NODE* top;
};
bool empty(const stack& s) {
    return (s.top == NULL);
}
void CreateEmptyStack(stack& s) {
    s.top = NULL;
}
void push(stack& s, char x) {
    NODE* p = CreateNode(x);
    if (s.top == NULL) s.top = p;
    else {
        p->pNext = s.top;
        s.top = p;
    }
}
void pop(stack& s) {
    if (s.top == NULL) return;
    NODE* p = s.top;
    s.top = s.top->pNext;
    delete p;
}
char& top(stack s) {
    return s.top->info;
}

int priority(char c) 
{
	if (c == '+' || c == '-') return 1;
	if (c == '*' || c == '/') return 2;
	if (c == '^') return 3;
	return 0;
}

bool isOperator(char c)
{
	return (c == '+' || c == '-' || c == '^' || c == '*' || c == '/');
}

void Input_infix(char infix[], int& ni)
{
	ni = 0;
    char x;
	while (cin >> x && x != '#') 
    {
		infix[ni++] = x;
	}
}

void infix_to_postfix(char infix[], int ni, char postfix[], int& np)
{
	stack s;
	CreateEmptyStack(s);
	np = 0;
	for (int i = 0; i < ni; i++)
	{
		char c = infix[i];
		if (isalnum(c))
		{
			postfix[np++] = c;
		}
		else if (c == '(')
		{
			push(s, c);
		}
		else if (c == ')')
		{
			while (!empty(s) && top(s) != '(')
			{
				postfix[np++] = top(s);
				pop(s);
			}
			if (!empty(s)) pop(s);
		}
		else if (isOperator(c))
		{
			while (!empty(s) && priority(top(s)) >= priority(c))
			{
				postfix[np++] = top(s);
				pop(s);
			}
			push(s, c);
		}
	}
	while (!empty(s))
	{
		postfix[np++] = top(s);
		pop(s);
	}
}

void Output(char postfix[], int np)
{
	for (int i = 0; i < np; i++)
	{
		cout << postfix[i] << " ";
	}
}

int main() 
{
    char infix[MAXN], postfix[MAXN];
    int ni, np;

    Input_infix(infix, ni);

    infix_to_postfix(infix, ni, postfix, np);

    Output(postfix, np);

    return 0;
}
