#include <iostream>
#include <string>
using namespace std;
template<typename Type>
class Stack
{
	struct Node
	{
		Type data;
		Node *next;
	};
	Node *top;
public:
	Stack() :top(NULL){}
	Type getTop()
	{
		if (!isEmpty())
		{
			return top->data;
		}
	}
	bool isEmpty()
	{
		if (top == NULL)
			return true;
		else
			return false;
	}
	void push(Type n)
	{
		Node *ptr = new Node;
		ptr->data = n;
		ptr->next = NULL;
		if (!isEmpty())
			ptr->next = top;
		top = ptr;
	}
	Type pop()
	{
		if (!isEmpty())
		{
			Node *ptr = top;
			top = top->next;
			Type n = ptr->data;
			delete ptr;
			return n;
		}
	}
	void display()
	{
		Node *ptr = top;
		while (ptr != NULL)
		{
			cout << ptr->data << " ";
			ptr = ptr->next;
		}
		cout << endl;
	}
};