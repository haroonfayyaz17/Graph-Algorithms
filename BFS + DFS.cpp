#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;
class Graph
{
	struct Vertex
	{
		string data;
		bool isVisited = false;
	};
	struct Edge
	{
		string edge;
		int weight;
	};
	Vertex vertices[9];
	Edge  edges[200];
	int vCount, eCount;
public:
	Graph() :vCount(9), eCount(0){
		for (int i = 0; i < 9; i++)
		{
			vertices[i].data = 48 + i;
		}
	}
	int getVertexPos(string str)
	{
		for (int i = 0; i < vCount; i++)
		if (vertices[i].data == str)
			return i;

	}
	void changeStatus()
	{
		for (int i = 0; i < vCount; i++)
			vertices[i].isVisited = false;
	}
	void BFS(int matrix[][9], string start)
	{
		queue<string>q;
		q.push(start);
		while (!q.empty())
		{
			start = q.front();
			q.pop();
			int vertex = getVertexPos(start);
			vertices[vertex].isVisited = true;
			for (int i = 0; i < vCount; i++)
			{
				if (matrix[vertex][i] != 0)
				if (vertices[i].isVisited == false)
				{
					q.push(vertices[i].data);
					vertices[i].isVisited = true;
				}
			}
			cout << start << " ";
		}
		changeStatus();
		cout << endl;
	}
	void DFS(int matrix[][9], string start)
	{
		stack<string>stack;
		stack.push(start);
		int vertex = getVertexPos(start);
		vertices[vertex].isVisited = true;
		cout << start << " ";
		while (!stack.empty())
		{
			start = stack.top();
			int vertex = getVertexPos(start);
			bool done = false;
			for (int i = 0; i < vCount&&!done; i++)
			{
				if (matrix[vertex][i] != 0)
				if (vertices[i].isVisited == false)
				{
					stack.push(vertices[i].data);
					vertices[i].isVisited = true;
					done = true;
					cout << vertices[i].data << " ";
				}
			}
			if (!done)
				stack.pop();
		}
		changeStatus();
		cout << endl;
	}
	void display(int matrix[][9])
	{
		cout << "   ";
		for (int i = 0; i < vCount; i++)
			cout << vertices[i].data << "  ";
		cout << endl << endl;
		for (int i = 0; i < vCount; i++)
		{
			cout << vertices[i].data << "  ";
			for (int j = 0; j < vCount; j++)
			{
				cout << matrix[i][j] << "  ";
			}
			cout << endl << endl;
		}
	}
};

int main()
{
	Graph graph;
	int matrix[9][9] = { { 0, 1, 0, 0, 0, 0, 1, 1, 0 }, { 0, 0, 0, 0, 1, 0, 1, 0, 0 }, { 1, 1, 0, 0, 0, 0, 0, 0, 1 }, { 0, 0, 0, 0, 1, 1, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 1, 0, 0, 0, 0 }, { 0, 0, 0, 1, 1, 0, 0, 0, 0 }, { 0, 0, 0, 1, 0, 0, 1, 0, 0 }, { 1, 0, 0, 0, 0, 0, 0, 1, 0 } };
	graph.display(matrix);
	graph.BFS(matrix, "2");
	graph.DFS(matrix, "2");
	system("pause>0");
}