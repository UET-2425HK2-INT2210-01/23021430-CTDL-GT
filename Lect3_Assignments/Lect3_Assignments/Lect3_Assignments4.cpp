#include <iostream>
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

class queue {
	node* head = NULL;;
public:
	// thêm 1 phần tử vào ngăn xếp
	void push()
	{
		int x;
		cin >> x;
		node* newNode = makeNode(x);
		if (check())
		{
			newNode->next = head;
			head = newNode;
			return;
		}
		else {
			node* tmp = head;
			while (tmp->next != NULL)
			{
				tmp = tmp->next;
			}
			tmp->next = newNode;
		}

	}

	// lấy 1 phần tử ra khỏi ngăn xếp
	void pop()
	{
		if (check()) return;
		else {
			node* tmp = head;
			head = head->next;
			delete tmp;
		}
	}
	// check xem ngăn xếp có rỗng không
	bool check()
	{
		if (head == NULL) return true;
		else return false;
	}
	// in stack
	void print()
	{
		node* tmp = head;
		while (tmp != NULL)
		{
			cout << tmp->data << ' ';
			tmp = tmp->next;
		}
	}
};



int main()
{
	int n;
	cin >> n;
	node* head = NULL;
	queue q;
	for (int i = 0; i < n; i++)
	{
		q.push();
	}
	q.pop();
	q.pop();

	q.print();

	return 0;
}
