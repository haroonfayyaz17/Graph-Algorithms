#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Heap
{
	struct Node
	{
		string data;
		int count;
	};
	Node *arr;
	int arr_size;
public:
	int size;
	Heap() :size(0), arr_size(0)
	{
	}
	void ReadFile()
	{
		size = 0;
		string data;
		int count=0;
		ifstream indata("Vertices.txt");
		while (getline(indata,data))
			arr_size++;
		arr_size++;
		arr = new Node[arr_size];
		indata.close();
		indata.open("Vertices.txt");
		while (getline(indata, data))
			insert(data, 214748364);
		indata.close();
	}
	void WriteFile()
	{
		ofstream outdata("Trending Words.txt");
		for (int i = 1; i <= size; i++)
			outdata << arr[i].data << "<" << arr[i].count << endl;
		outdata.close();
	}
	int StringtoInt(string word)
	{
		int sum = 0;
		for (int i = 0; i < word.length(); i++)
		{
			int n = word[word.length() - i - 1] - 48;
			sum = sum + (n*pow(10, i));
		}
		return sum;
	}
	void insert(string data, int count)
	{
		if (size + 1 == arr_size)
			cout << "Heap is Full\n";
		else
		{
			size++;
			int p = size;
			percolate_Up(p, data, count);
		}
	}
	void percolate_Up(int p, string data, int n)
	{
		int i = p / 2;
		while (i != 0 && arr[i].count > n)
		{
			arr[p] = arr[i];
			p = i;
			i = i / 2;
		}
		arr[p].data = data;
		arr[p].count = n;
	}
	string delete_Min(int &weight)
	{
		string element = arr[1].data;
		weight = arr[1].count;
		arr[1] = arr[size];
		size--;
		percolate_Down(1, arr[1].data, arr[1].count);
		return element;
	}
	void percolate_Down(int i, string data, int n)
	{
		int p = i;
		while (i < size && (n > arr[i * 2].count || n > arr[i * 2 + 1].count))
		{
			p = i;
			if (arr[i * 2].count < arr[i * 2 + 1].count)
			{
				arr[i] = arr[i * 2];
				i = i * 2;
			}
			else
			{
				arr[i] = arr[i * 2 + 1];
				i = i * 2 + 1;
			}
		}
		if (i > size)
		{
			arr[p].count = n;
			arr[p].data = data;
		}
		else
		{
			arr[i].count = n;
			arr[i].data = data;
		}

	}
	bool decreaseKey(string data, int factor)
	{
		int i = 1;
		while (i <= size&&arr[i].data != data)
			i++;
		if (i <= size)
		{
			if (factor < arr[i].count)
			{
				arr[i].count = factor;
				percolate_Up(i, arr[i].data, arr[i].count);
				return true;
			}
		}
		return false;
	}
	void increaseKey(string data, int factor)
	{
		int i = 1;
		while (i <= size&&arr[i].data != data)
			i++;
		if (i > size)
			insert(data, 1);
		else
		{
			arr[i].count = factor;
			percolate_Down(i, arr[i].data, arr[i].count);
		}
	}
	void display()
	{
		for (int i = 1; i <= size; i++)
			cout << arr[i].data << " ";
		cout << endl;
	}
	void ReSize()
	{
		arr_size = arr_size + 20;
		Node *newarr = new Node[arr_size];
		for (int i = 0; i < size; i++)
			newarr[i] = arr[i];
		delete[] arr;
		arr = newarr;
	}
	void deleteAll()
	{
		delete[]arr;
	}
	~Heap()
	{
		deleteAll();
	}

};
