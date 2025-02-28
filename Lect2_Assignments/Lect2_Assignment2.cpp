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

int size(node* head)
{
	int sum = 0;
	while (head != NULL)
	{
		sum++;
		head = head->next;
	}
	return sum;
}

void print(node* head)
{
	while (head != NULL)
	{
		cout << head->data << ' ';
		head = head->next;
	}
}

// ham them vao dau DSLK
void pushFront(node*& head, int x)
{
	node* newNode = makeNode(x);
	newNode->next = head;
	head = newNode;
}

// ham chen x vao vi tri p
void insert(node*& head, int p, int x)
{
	int n = size(head);
	if (p < 0 || p > n + 1) return;
	if (p == 0)
	{
		pushFront(head, x);
		return;
	}
	node* temp = head;
	for (int i = 1; i <= p - 1; i++)
	{
		temp = temp->next;
	}
	node* newNode = makeNode(x);
	newNode->next = temp->next;
	temp->next = newNode;
}

// ham xoa phan tu dau DSLK
void popFront(node*& head)
{
	if (head == NULL) return;
	node* temp = head;
	head = head->next;
	delete temp;
}

// ham xoa phan tu tai vi tri x
void erase(node*& head, int x)
{
	int n = size(head);
	if (x < 0 || x > n) return;
	if (x == 0)
	{
		popFront(head);
	}
	else {
		node* temp = head;
		for (int i = 1; i <= x - 1; i++)
		{
			temp = temp->next;
		}
		node* k_node = temp->next;
		temp->next = k_node->next;
		delete k_node;
	}
}

int main()
{
	node* head = NULL;
	int n;
	cin >> n;
	string str;

	for (int i = 1; i <= n; i++)
	{
		cin >> str;
		if (str == "insert")
		{
			int p, x;
			cin >> p >> x;
			insert(head, p, x);
		}
		else if (str == "delete")
		{
			int x;
			cin >> x;
			erase(head, x);
		}
	}
	print(head);

	return 0;
}