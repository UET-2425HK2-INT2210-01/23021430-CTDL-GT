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

void push(node*& queue, int x)
{
	node* newNode = makeNode(x);
	if (queue == NULL)
	{
		queue = newNode;
		return;
	}
	node* temp = queue;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;
}

void pop(node*& queue)
{
	if (queue == NULL) return;
	node* temp = queue;
	queue = queue->next;
	delete temp;
}

void print(node* queue)
{
	while (queue != NULL)
	{
		cout << queue->data << ' ';
		queue = queue->next;
	}
}

int main()
{
	node* queue = NULL;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		if (str == "enqueue")
		{
			int x;
			cin >> x;
			push(queue, x);
		}
		else if (str == "dequeue")
		{
			pop(queue);
		}
	}
	print(queue);

	return 0;
}