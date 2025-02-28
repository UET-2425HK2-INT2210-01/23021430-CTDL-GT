#include <iostream>
#include <string>
using namespace std;

struct node {
	int data;
	node* next;
};

node* makeNode(int x)
{
	node* newNode = new node();
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

void push(node*& top, int x)
{
	node* newNode = makeNode(x);
	if (top == NULL)
	{
		top = newNode;
		return;
	}
	newNode->next = top;
	top = newNode;
}

void pop(node*& top)
{
	if (top == NULL) return;
	node* temp = top;
	top = top->next;
	delete temp;
}

void print(node* top)
{
	if (top == NULL) return;
	print(top->next);
	cout << top->data << " ";
}

int main()
{
	node* st = NULL;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		if (str == "push")
		{
			int x;
			cin >> x;
			push(st, x);
		}
		else if (str == "pop")
		{
			pop(st);
		}
	}
	print(st);

	return 0;
}