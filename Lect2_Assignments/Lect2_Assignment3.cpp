#include <iostream>
using namespace std;

struct node {
	int data;
	node* next;
	node* prev;
};

node* makeNode(int x)
{
	node* newNode = new node();
	newNode->data = x;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

void pushFront(node*& head, int x)
{
	node* newNode = makeNode(x);
	if (head != NULL)
	{
		newNode->next = head;
		head->prev = newNode;
	}
	head = newNode;
}

void pushBack(node*& head, int x)
{
	node* newNode = makeNode(x);
	if (head == NULL)
	{
		head = newNode;
		return;
	}
	node* temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
}

int count_triplets(node*& head)
{
	node* temp = head->next;
	if (temp->prev == NULL || temp == NULL || temp->next == NULL)
	{
		return 0;
	}
	int count = 0;
	while (temp->next != NULL)
	{
		if (temp->prev->data + temp->data + temp->next->data == 0)
		{
			count++;
		}
		temp = temp->next;
	}
	return count;
}

int main()
{
	node* head = NULL;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		pushBack(head, x);
	}
	cout << count_triplets(head);

	return 0;
}
