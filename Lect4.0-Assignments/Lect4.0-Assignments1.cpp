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

class linkedlist {
	node* head = NULL;
public:
	// thêm 1 phần tử vào cuối linkedlist
	void append()
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

	// check xem linkedlist có rỗng không
	bool check()
	{
		if (head == NULL) return true;
		else return false;
	}

	//tìm kiếm
	void search()
	{
		int x;
		cin >> x;
		node* tmp = head;
		int sum = 0;
		while (tmp->data != x)
		{
			sum++;
			tmp = tmp->next;
		}
		cout << sum << endl;
	}

	// in nguoc
	void reverse()
	{
		node* tmp = head;
		int array[100];
		int n = 0;
		while (tmp != NULL)
		{
			array[n] = tmp->data;
			tmp = tmp->next;
			n++;
		}

		for (int i = n - 1; i >= 0; i--)
		{
			cout << array[i] << ' ';
		}
		cout << endl;
	}
};

int main()
{
	int n;
	cin >> n;
	node* head = NULL;
	linkedlist l;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		if (str == "append")
		{
			l.append();
		}
		else if (str == "search")
		{
			l.search();
		}
		else if (str == "reverse")
		{
			l.reverse();
		}
	}

	return 0;
}