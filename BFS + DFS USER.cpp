#include <iostream>
#include <fstream>
#include <string>
#include "Queue.h"
#include "Stack.h"
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
	Vertex vertices[15];
	Edge  edges[200];
	int vCount, eCount;
	int **matrix;
public:
	Graph() :vCount(0), eCount(0){}
	string getString(string str, int start, int &end, char c)
	{
		char s[100];
		int i, count = 0;
		for (i = start; str[i] != c&&count < 99; i++)
			s[count++] = str[i];
		s[count] = '\0';
		end = i;
		return string(s);
	}
	void ReadVertices()
	{
		ifstream indata;
		indata.open("Vertices.txt");
		string data;
		while (getline(indata, data))
			vertices[vCount++].data = data;
		indata.close();
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
	void ReadEdges()
	{
		ifstream indata("EdgesUndirected.txt");
		string data;
		while (getline(indata, data,'<'))
		{
			edges[eCount].edge = data;
			getline(indata, data);
			edges[eCount++].weight = StringtoInt(data);
		}
		indata.close();
	}
	int getVertexPos(string str)
	{
		for (int i = 0; i < vCount; i++)
			if (vertices[i].data == str)
				return i;

	}
	void AdjacencyMatrix()
	{
		matrix = new int*[vCount];
		for (int i = 0; i < vCount; i++)
			matrix[i] = new int[vCount];
		for (int i = 0; i < vCount; i++)
		{
			for (int j = 0; j < vCount; j++)
				matrix[i][j] = 0;
		}
		for (int i = 0; i < eCount; i++)
		{
			int end;
			string str = edges[i].edge, rStr = getString(str, 1, end = 0, ','), cStr = getString(str, end + 1, end, ')');
			int row = getVertexPos(rStr), col = getVertexPos(cStr);
			matrix[row][col] = edges[i].weight;
			matrix[col][row] = edges[i].weight;
		}
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
		/*for (int i = 0; i < vCount; i++)
			delete[]matrix[i];
			delete[]matrix;*/
	}
	void changeStatus()
	{
		for (int i = 0; i < vCount; i++)
			vertices[i].isVisited = false;
	}
	void BFS(string start)
	{
		Queue<string>queue;
		queue.Enqueue(start);
		while (!queue.isEmpty())
		{
			start = queue.Dequeue();
			int vertex = getVertexPos(start);
			vertices[vertex].isVisited = true;
			for (int i = 0; i < vCount; i++)
			{
				if (matrix[vertex][i] != 0)
					if (vertices[i].isVisited == false)
					{
					queue.Enqueue(vertices[i].data);
					vertices[i].isVisited = true;
					}
			}
			cout << start << " ";
		}
		changeStatus();
		cout << endl;
	}
	void DFS(string start)
	{
		Stack<string>stack;
		stack.push(start);
		while (!stack.isEmpty())
		{
			start = stack.pop();
			int vertex = getVertexPos(start);
			vertices[vertex].isVisited = true;
			for (int i = 0; i < vCount; i++)
			{
				if (matrix[vertex][i] != 0)
					if (vertices[i].isVisited == false)
					{
					stack.push(vertices[i].data);
					vertices[i].isVisited = true;
					}
			}
			cout << start << " ";
		}
		changeStatus();
		cout << endl;
	}
};

int main()
{
	Graph graph;
	graph.ReadVertices();
	graph.ReadEdges();
	graph.AdjacencyMatrix();
	/*graph.BFS("a");
	graph.DFS("a");*/

	system("pause>0");
}