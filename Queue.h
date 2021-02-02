#include <iostream>
using namespace std;
template<typename Type>
class Queue
{
	struct Node
	{
		Type data;
		Node *next;
	};
	Node *front, *rear;
public:
	Queue() :front(NULL), rear(NULL){}
	bool isEmpty()
	{
		if (front == NULL)
			return true;
		else
			return false;
	}
	void Enqueue(Type n)
	{
		Node *ptr = new Node;
		ptr->data = n;
		ptr->next = NULL;
		if (isEmpty())
			front = rear = ptr;
		else
		{
			rear->next = ptr;
			rear = ptr;
		}
	}
	Type Dequeue()
	{
		if (isEmpty())
			cout << "Queue is Empty\n";
		else
		{
			Node *ptr = front;
			front = front->next;
			return ptr->data;
		}
	}
	void displayQueue()
	{
		Node *ptr = front;
		while (ptr != NULL)
		{
			cout << ptr->data << " ";
			ptr = ptr->next;
		}
		cout << endl;
	}
};