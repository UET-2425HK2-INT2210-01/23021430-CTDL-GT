#include <iostream>
#include <string>
using namespace std;

struct node {
    char data;
    node* next;
};

node* makeNode(char x)
{
    node* newNode = new node();
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

class stack {
    node* head = NULL;
public:
    // thêm 1 phần tử vào ngăn xếp
    void push(char x)
    {
        node* newNode = makeNode(x);
        newNode->next = head;
        head = newNode;
    }
    // lấy 1 phần tử ra khỏi ngăn xếp
    char pop()
    {
        if (check()) return '\0';
        node* tmp = head;
        char topdata = tmp->data;
        head = head->next;
        delete tmp;
        return topdata;
    }
    // check xem ngăn xếp có rỗng không
    bool check()
    {
        if (head == NULL) return true;
        else return false;
    }
};

bool isValid(string s)
{
    stack st;
    for (char x : s)
    {
        if (x == '(' || x == '[' || x == '{')
        {
            st.push(x);
        }
        else {
            if (st.check()) return false;
            char top = st.pop();
            if ((x == ')' && top != '(') || (x == ']' && top != '[') || (x == '}' && top != '{'))
            {
                return false;
            }
        }
    }
    return st.check();
}

int main()
{
    string str;
    cin >> str;

    if (isValid(str))
    {
        cout << "Valid" << endl;
    }
    else
    {
        cout << "Invalid" << endl;
    }

    return 0;
}