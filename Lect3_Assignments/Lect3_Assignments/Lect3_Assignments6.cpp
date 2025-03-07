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

class stack {
	node* head = NULL;;
public:
	// thêm 1 phần tử vào ngăn xếp
	void push()
	{
		int x;
		cin >> x;
		node* newNode = makeNode(x);
		newNode->next = head;
		head = newNode;
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
	stack st;
	for (int i = 0; i < n; i++)
	{
		st.push();
	}
	st.pop();
	st.pop();

	st.print();

	return 0;
}

// giả code
// tạo 1 struct node 
// tạo 1 class với node head = NULL
// hàm thêm 1 phần tử vào ngăn xếp tạo 1 newNode cho phần next của newNode = head
// sau đó cho head = newNode
// tạo 1 hàm check xem ngăn xếp có rỗng không nếu head == NULL thì return true
// hàm xóa 1 phần tử khỏi ngăn xếp đầu tiên nếu phần tử rỗng thì return
// tạm 1 node* tmp = head cho head = head->next sau đó delete tmp
